/* 
 * File:   Ventana.h
 * Author: pedro
 */
#include "Ventana.h"
#include <ncurses.h>

//costructor por defecto
Ventana::Ventana()
{
}
//atributos para el menu
void Ventana::print_menu(WINDOW *menuw)
{
	wattrset(titlew, COLOR_PAIR(6));
	box(titlew, ACS_BULLET, ACS_BULLET); // sets default borders for the window
	mvwprintw(titlew, 1, 1, "--------SCRABLE--------");
	wattroff(titlew, COLOR_PAIR(5));
	wrefresh(titlew);
	int i;
	char item[20];
	char list[NITEMS][20] = {"Juego Nuevo",
							 "Load/Delete Game",
							 "Instructions",
							 "High Scores",
							 "About Developers",
							 "Exit"};
	box(menuw, ACS_VLINE, ACS_HLINE); // sets default borders for the window

	// now print all the menu items and highlight the first one
	for (i = 0; i < NITEMS; i++)
	{
		sprintf(item, "%s", list[i]);
		mvwprintw(menuw, i + 1, 2, "%s", item);
	}

	mvwprintw(menuw, 11, 2, "'%c' -> Up", CONTROL_UP);
	mvwprintw(menuw, 12, 2, "'%c' -> Down", CONTROL_DOWN);
	mvwprintw(menuw, 13, 2, "Press '%c' to select ", CONTROL_NEXT);
	wrefresh(menuw); // update the terminal screen
}

//inicializa e imprime el menu metodo privado
int Ventana::menu()
{
	char list[NITEMS][20] = {"Juego Nuevo",
							 "Load/Delete Game",
							 "Instructions",
							 "High Scores",
							 "About Developers",
							 "Exit"};
	char item[20];
	int ch, dh, i = 0, width = 7;

	initscr();						  // initialize Ncurses
	menuw = newwin(15, 25, 4, 1);	  // create a new window
	box(menuw, ACS_VLINE, ACS_HLINE); // sets default borders for the window

	titlew = newwin(3, 25, 1, 1);
	wattrset(titlew, COLOR_PAIR(6));
	box(titlew, ACS_BULLET, ACS_BULLET); // sets default borders for the window
	mvwprintw(titlew, 1, 1, "--------SCRABLE--------");
	wattroff(titlew, COLOR_PAIR(6));
	wrefresh(titlew);

	// now print all the menu items and highlight the first one
	for (i = 0; i < NITEMS; i++)
	{
		if (i == 0)
			wattron(menuw, A_STANDOUT); // highlights the first item.
		else
			wattroff(menuw, A_STANDOUT);
		sprintf(item, "%s", list[i]);
		mvwprintw(menuw, i + 1, 2, "%s", item);
	}

	mvwprintw(menuw, 11, 2, "'%c' -> Up", CONTROL_UP);
	mvwprintw(menuw, 12, 2, "'%c' -> Down", CONTROL_DOWN);
	mvwprintw(menuw, 13, 2, "Press '%c' to select ", CONTROL_NEXT);
	wrefresh(menuw); // update the terminal screen

	i = 0;
	noecho();			 // disable echoing of characters on the screen
	keypad(menuw, TRUE); // enable keyboard input for the window.
	curs_set(0);		 // hide the default screen cursor.

	// get the input
	while (ch = wgetch(menuw))
	{

		// right pad with spaces to make the items appear with even width.
		sprintf(item, "%s", list[i]);
		mvwprintw(menuw, i + 1, 2, "%s", item);
		// use a variable to increment or decrement the value based on the input.
		switch (ch)
		{
		case CONTROL_UP:
			i--;
			i = (i < 0) ? (NITEMS - 1) : i;
			break;
		case CONTROL_DOWN:
			i++;
			i = (i > (NITEMS - 1)) ? 0 : i;
			break;
		case CONTROL_NEXT:
			if (i == 0)
			{
				int lvl = 0;
				
				miw = newwin(10, 45, 4, 30);
				wrefresh(miw);
				miw = newwin(10, 25, 4, 30);
				mvwprintw(miw, 1, 2, "Select Level :");
				mvwprintw(miw, 5, 2, "'%c' -> level up", CONTROL_UP);
				mvwprintw(miw, 6, 2, "'%c' -> level down", CONTROL_DOWN);
				mvwprintw(miw, 7, 2, "'%c' -> select", CONTROL_NEXT);
				mvwprintw(miw, 8, 2, "'%c' -> go back", CONTROL_BACK);
				box(miw, ACS_VLINE, ACS_HLINE);
				wrefresh(miw);
				while (dh = wgetch(miw))
				{
					switch (dh)
					{
					case CONTROL_DOWN:
						lvl--;
						lvl = (lvl < 0) ? (NO_LEVELS - 1) : lvl;
						break;
					case CONTROL_UP:
						lvl++;
						lvl = (lvl > (NO_LEVELS - 1)) ? 0 : lvl;
						break;
					case CONTROL_BACK:
						return -2;
					case CONTROL_NEXT:
						return lvl;
					}
					//mvwprintw(miw, 2, 5, " %d ", lvl);
					//mvwprintw(miw, 2,7, "Ingrese usuario para el juego: ");
					wrefresh(miw);
				}
			}

			if (i == 1)
			{
				return -3;
			}

			if (i == 2)
			{
				miw = newwin(10, 45, 4, 30);
				mvwprintw(miw, 1, 2, "Controls :");
				mvwprintw(miw, 3, 2, "Move Left -> j");
				mvwprintw(miw, 4, 2, "Move Right -> l");
				mvwprintw(miw, 5, 2, "Move down -> k");
				mvwprintw(miw, 6, 2, "Rotate -> i");
				mvwprintw(miw, 7, 2, "Pause Game -> p");
				mvwprintw(miw, 8, 2, "Quit game -> v");
				wrefresh(miw);
			}

			if (i == 3)
			{
				disp_score(NULL);
				clear();
				refresh();
				print_menu(menuw);
			}

			if (i == 4)
			{
				miw = newwin(10, 45, 4, 30);
				wclear(miw);
				mvwprintw(miw, 2, 2, "Game Developer :");
				mvwprintw(miw, 4, 2, "Contact info :");
				mvwprintw(miw, 6, 2, "For Source code visit :");
				wattrset(miw, COLOR_PAIR(12));
				mvwprintw(miw, 3, 2, "  \"Shadab Khan\"");
				mvwprintw(miw, 5, 2, "  \"shadabk14.comp@coep.ac.in\"");
				mvwprintw(miw, 7, 2, "  \"https://github.com/shadabk/tetris-minip\"");
				wattroff(miw, COLOR_PAIR(12));
				wrefresh(miw);
			}

			if (i == 5)
			{
				delwin(menuw);
				endwin();
				return -1;
			}
			break;
		}
		// now highlight the next item in the list.
		wattron(menuw, A_STANDOUT);
		sprintf(item, "%s", list[i]);
		mvwprintw(menuw, i + 1, 2, "%s", item);
		wattroff(menuw, A_STANDOUT);
	}

	delwin(menuw);
	endwin();
}

void Ventana::menuGame(){
	int ch, level, y;
	keypad(gamew, TRUE);
	initscr();
	while (1)
	{
		y = 1;
		initialise_colors();
		bkgd(COLOR_PAIR(9));
		refresh();
		int play = menu();
		if (play == -1)
		{
			delwin(gamew);
			endwin();
			return;
		}
		if (play == -2)
			continue;
		init_windows();
		if (play == -3)
		{
			y = -3;
			level = 0;
		}
		else
			level = play;
		nodelay(stdscr, TRUE);
		//play_game(level, y);

		clear();
		refresh();
	}
	delwin(gamew);
	endwin();
}



/* Displays the score from highscores.txt file
 * Can be called anytime.
 */
void Ventana::disp_score(char *message) {
	nodelay(stdscr, FALSE);
	char ch, str[15];
	wclear(gamew);
	//POINTS points;
	scorew = newwin(GAME_HEIGHT - 2, GAME_WIDTH, 0, 0);
	box(scorew, ACS_VLINE, ACS_HLINE);
	wrefresh(scorew);


	if(message != NULL) {
		wattrset(scorew, COLOR_PAIR(1));
		mvwprintw(scorew, 17 , 19, "## %s ##", message);
		wattroff(scorew, COLOR_PAIR(1));
	}
	FILE *fp;
	fp = fopen("highscores.txt", "r");
	if(fp == NULL) {
		mvwprintw(scorew, 10, 10, "Highscores file not found.");
		wrefresh(scorew);
		ch = getch();
		return;
	}
	
	wattrset(scorew, COLOR_PAIR(14));
	mvwprintw(scorew, 2, 23, "## Highscores ##");	
	mvwprintw(scorew, 19, 17, "## Press any key to exit ##");
	wattroff(scorew, COLOR_PAIR(14));
	mvwprintw(scorew, 4, 10, "Player Name");
	mvwprintw(scorew, 4, 27, "Points");
	mvwprintw(scorew, 4, 37, "Lines");
	mvwprintw(scorew, 4, 47, "Level");
	mvwprintw(scorew, 6, 7, "1.");

	int i = 10, j = 6, rank = 2;
	while((ch = fgetc(fp)) != EOF) {
		if(ch == '\t') {
			i = (((i + 10) / 10 ) * 10);
			continue;
		}
		if(ch == '\n') {
			i = 10;
			j++;
			mvwprintw(scorew, j, 7, "%d.", rank++);	
			continue;
		}		
		mvwprintw(scorew, j, i, "%c", ch);
		i++;
		wrefresh(scorew);
	}
	ch = getch();
	nodelay(stdscr, TRUE);
}

// All colour definitions are defined here :
void Ventana::initialise_colors()
{
	start_color();
	init_pair(9, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(11, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_CYAN);
	init_pair(12, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);
	init_pair(13, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(14, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(15, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(16, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(17, COLOR_MAGENTA, COLOR_BLACK);
}

// Initiliases the windows for the first time :
void Ventana::init_windows()
{
	//POINTS points;
	//points.points = 0;
	//points.lines = 0;
	//points.level = 0;
	int STAT_HEIGHT = WELL_HEIGHT / 2;
	gamew = newwin(GAME_HEIGHT, GAME_WIDTH, 0, 0);
	wellw = newwin(WELL_HEIGHT + 1, WELL_WIDTH + 2, 1, 1);
	statw = newwin(STAT_HEIGHT, NEXT_WIDTH, NEXT_HEIGHT + 2, WELL_WIDTH + 3);
	nextw = newwin(NEXT_HEIGHT, NEXT_WIDTH, 2, WELL_WIDTH + 3);
	instw = newwin(WELL_HEIGHT + 1, 20, 1, WELL_WIDTH + NEXT_WIDTH + 4);
	//update_stat(points);
	//update_next(1, 1);
	//update_inst();
	box(statw, ACS_VLINE, ACS_HLINE);
	wrefresh(wellw);
	wrefresh(statw);
}



//destructor
Ventana::~Ventana() {}
