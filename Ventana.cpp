/* 
 * File:   Ventana.h
 * Author: pedro
 */
#include "Ventana.h"
#include <ncurses.h>

//costructor por defecto
Ventana::Ventana()
{
	lscoreJugador = new Lista<Jugador *>();
}

//constructor con parametros
Ventana::Ventana(ListaDoble<string> *diccionario_, BST *usuario_, Config *config_, Lista<Ficha *> *colaficha_, MatrizDispersa *matriz_)
{
	diccionario = diccionario_;
	arbolJugadores = usuario_;
	conf = config_;
	player2 = player1 = nullptr;
	lscoreJugador = new Lista<Jugador *>();
	colaFicha = colaficha_;
	matriz = matriz_;
}

//random letras
void Ventana::random()
{
	int ran;
	for (size_t i = 0; i < 12; i++)
	{
		ran = drand48() * (27) + 1;
		Ficha *tmpF = colaFicha->del_by_position(ran);
		colaFicha->add_endS(tmpF);
	}
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

//atributos para el menu para reimprimir
void Ventana::print_menu(WINDOW *menuw)
{
	wattrset(titlew, COLOR_PAIR(6));
	box(titlew, ACS_BULLET, ACS_BULLET); // sets default borders for the window
	mvwprintw(titlew, 1, 1, "--------MENU SCRABLE--------");
	wattroff(titlew, COLOR_PAIR(5));
	wrefresh(titlew);
	int i;
	char item[30];
	char list[NITEMS][30] = {"Juego Nuevo",
							 "Agregar Jugador",
							 "Reportes",
							 "Score",
							 "About",
							 "Exit"};
	box(menuw, ACS_VLINE, ACS_HLINE); // sets default borders for the window

	// now print all the menu items and highlight the first one
	for (i = 0; i < NITEMS; i++)
	{
		sprintf(item, "%s", list[i]);
		mvwprintw(menuw, i + 1, 2, "%s", item);
	}

	mvwprintw(menuw, 11, 2, "KEY UP -> Up");
	mvwprintw(menuw, 12, 2, "KEY DOWN -> Down");
	mvwprintw(menuw, 13, 2, "Press '%c' to select ", CONTROL_NEXT);
	wrefresh(menuw); // update the terminal screen
}

//agregar usuarios al arbol
int Ventana::addPlayer()
{
	//----------------------------------------------------------------------asks user for name.
	int i;
	char ch;
	addpw = newwin(15, 45, 4, 40);
	box(addpw, ACS_VLINE, ACS_HLINE);
	wrefresh(addpw);
	mvwprintw(addpw, 1, (getmaxx(addpw) / 2) - 7.5, "Agregar Jugador");
	mvwprintw(addpw, 3, 3, "Ingrese su nombre : [");
	mvwprintw(addpw, 3, 3 + 14 + strlen("Ingrese su nombre : ["), "]");
	mvwprintw(addpw, (getmaxy(addpw) / 2) + 3, 12, "Pulsar '+' Agregar");
	mvwprintw(addpw, (getmaxy(addpw) / 2) + 4, 12, "Pulsar '-' Borrar");
	mvwprintw(addpw, (getmaxy(addpw) / 2) + 5, 12, "Pulsar '/' Cancelar");
	wrefresh(addpw);
	nodelay(stdscr, FALSE);
	int letter_count = 0;
	char pathname[15];
	for (i = 0; i < 15; i++)
		pathname[i] = ' ';
	pathname[15] = '\0';
	do
	{
		ch = wgetch(addpw);
		if (letter_count < 15)
		{
			if (ch != '+')
				pathname[letter_count] = ch;
		}
		if (ch == '-')
		{
			pathname[letter_count] = ' ';
			(letter_count > 0) ? (letter_count = letter_count - 2) : letter_count;
			pathname[letter_count + 1] = ' ';
		}
		if (ch == '/')
			return 1;
		letter_count++;
		wattrset(addpw, COLOR_PAIR(14));
		mvwprintw(addpw, 3, 3 + strlen("Ingrese su nombre : ["), "%s", pathname);
		wattroff(addpw, COLOR_PAIR(14));
		mvwprintw(addpw, 3, +3 + 14 + strlen("Ingrese su nombre : ["), "]");
		wrefresh(addpw);
	} while ((ch != '+') && (letter_count != 18));
	if (ch == '+')
	{
		//pathname[letter_count - 1] = ' ';
		arbolJugadores->insert(pathname);
		if (player1==nullptr)
		{
			player1 = arbolJugadores->search(pathname);
		}
		else
			player2 = arbolJugadores->search(pathname);

		if (arbolJugadores->dataExist())
		{
			wattrset(addpw, COLOR_PAIR(16));
			mvwprintw(addpw, 6, 3, "Ya existe el Jugador: ");
			wattrset(addpw, COLOR_PAIR(16));
			mvwprintw(addpw, 6, 4 + strlen("Ya existe el Jugador: "), "%s", pathname);
			wrefresh(addpw);
			getch();
		}
	}
}

// Initiliases the windows for the first time :
void Ventana::init_windows()
{
	int STAT_HEIGHT = WELL_HEIGHT / 2;
	gamew = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
	wellw = newwin(WELL_HEIGHT - 6, WELL_WIDTH + 10, 1, 21);
	statw = newwin(STAT_HEIGHT - 6, (WELL_WIDTH - 12) * 2 + WELL_WIDTH + 10, WELL_HEIGHT - 5, 1);
	nextw = newwin(WELL_HEIGHT - 7, NEXT_WIDTH, 2, (WELL_WIDTH - 12) * 2 + WELL_WIDTH + 11);
	wp2 = newwin(WELL_HEIGHT - 6, WELL_WIDTH - 12, 1, WELL_WIDTH + 10 + 21);
	wp1 = newwin(WELL_HEIGHT - 6, WELL_WIDTH - 12, 1, 1);
	asignar_fichas();
	update_stat();
	update_next();
	update_wp1();
	update_wp2();
	box(wp1, ACS_VLINE, ACS_HLINE);
	box(wellw, ACS_VLINE, ACS_HLINE);
	box(statw, ACS_VLINE, ACS_HLINE);
	wrefresh(wp1);
	wrefresh(wellw);
	wrefresh(statw);
	getch();
}

//Redraws the window showing next block
void Ventana::update_next()
{

	box(nextw, ACS_VLINE, ACS_HLINE);
	mvwprintw(nextw, 0, 3, "# DICCIONARIO #");
	wrefresh(nextw);
	int j = 2;

	for (size_t i = 0; i < diccionario->getSize(); i++)
	{

		string tmpS = diccionario->getDataC();
		mvwprintw(nextw, j, (getmaxx(nextw) / 2) - (strlen(tmpS.c_str()) / 2), tmpS.c_str());
		wrefresh(nextw);
		j++;
	}
}

//Redraws stat window
void Ventana::update_stat()
{

	box(statw, ACS_VLINE, ACS_HLINE);
	mvwprintw(statw, 2, 5, "Score : %d", 2);
	mvwprintw(statw, 3, 5, "Lines : %d", 3);
	//mvwprintw(statw, 1, (getmaxx(statw) / 2) - 7.5, "# DICCIONARIO #");
	wrefresh(statw);
}

//updates win player2
void Ventana::update_wp2()
{
	mvwprintw(wp2, 1, (getmaxx(wp2) / 2) - (strlen("Player 2") / 2), "Player 2");
	mvwprintw(wp2, 2, (getmaxx(wp2) / 2) - strlen(player2->getName().c_str())/2, player2->getName().c_str());
	mvwprintw(wp2, 3, 1, "Score: ");
	mvwprintw(wp2, 4, 1 + strlen("Score: "), to_string(player2->getScoreMax()).c_str());
	mvwprintw(wp2, 5, (getmaxx(wp2) / 2) - (strlen("Letras") / 2), "Letras");
	int Y = 6;
	//for (int i = 0; i < player2->lfichas.getSize(); i++)
	//{
	//	Ficha *tmpF = player2->lfichas.getDataNext();
	//	mvwprintw(wp2, Y, (getmaxx(wp2) / 2) - (strlen(tmpF->getLetra().c_str()) / 2), tmpF->getLetra().c_str());
	//	Y++;
	//	wrefresh(wp2);
	//}
	box(wp2, ACS_VLINE, ACS_HLINE);
	wrefresh(wp2);
}

//update win player1
void Ventana::update_wp1()
{
	mvwprintw(wp1, 1, (getmaxx(wp1) / 2) - (strlen("Player 1") / 2), "Player 1");
	mvwprintw(wp1, 2, (getmaxx(wp1) / 2) - (strlen(player1->getName().c_str()) / 2), player1->getName().c_str());
	mvwprintw(wp1, 4, 1, "Score: ");
	mvwprintw(wp1, 5, 1 + strlen("Score:  "), to_string(player1->getScoreMax()).c_str());
	mvwprintw(wp1, 6, (getmaxx(wp1) / 2) - (strlen("Letras") / 2), "Letras");
	int Y = 7;
	//for (int i = 0; i < player1->lfichas.getSize(); i++)
	//{
	//	Ficha *tmpF = player1->lfichas.getDataNext();
	//	mvwprintw(wp1, Y, (getmaxx(wp1) / 2) - (strlen(tmpF->getLetra().c_str()) / 2), tmpF->getLetra().c_str());
	//	Y++;
	//	wrefresh(wp1);
	//}
	box(wp1, ACS_VLINE, ACS_HLINE);
	wrefresh(wp1);
}

//inicializa e imprime el menu metodo privado
int Ventana::menu()
{
	char list[NITEMS][30] = {"Juego Nuevo",
							 "Agregar Jugador",
							 "Reportes",
							 "Score",
							 "About",
							 "Exit"};
	char item[30];
	int ch, dh, i = 0, width = 7;

	initscr();						  // initialize Ncurses
	menuw = newwin(15, 30, 4, 1);	  // create a new window
	box(menuw, ACS_VLINE, ACS_HLINE); // sets default borders for the window

	titlew = newwin(3, 30, 1, 1);
	wattrset(titlew, COLOR_PAIR(6));
	box(titlew, ACS_BULLET, ACS_BULLET); // sets default borders for the window
	mvwprintw(titlew, 1, 1, "--------MENU SCRABLE--------");
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

	mvwprintw(menuw, 11, 2, "KEY UP -> Up");
	mvwprintw(menuw, 12, 2, "KEY DOWN -> Down");
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
		case KEY_UP:
			i--;
			i = (i < 0) ? (NITEMS - 1) : i;
			break;
		case KEY_DOWN:
			i++;
			i = (i > (NITEMS - 1)) ? 0 : i;
			break;
		case CONTROL_NEXT:
			if (i == 0)
			{

				if (arbolJugadores->getSize() >= 2)
				{
					init_windows();
					delwin(menuw);
					return 1;
				}
				else
				{
					addPlayer();
					clear();
					refresh();
					print_menu(menuw);
				}
			}

			if (i == 1)
			{
				addPlayer();
				clear();
				refresh();
				print_menu(menuw);
			}

			if (i == 2)
			{
				//munu de opciones reportes
				//miw = newwin(10, 45, 4, 30);
				//mvwprintw(miw, 1, 2, "Controls :");
				//mvwprintw(miw, 3, 2, "Move Left -> j");
				//mvwprintw(miw, 4, 2, "Move Right -> l");
				//mvwprintw(miw, 5, 2, "Move down -> k");
				//mvwprintw(miw, 6, 2, "Rotate -> i");
				//mvwprintw(miw, 7, 2, "Pause Game -> p");
				//mvwprintw(miw, 8, 2, "Quit game -> v");
				//wrefresh(miw);
			}

			if (i == 3)
			{
				score_general(NULL);
				clear();
				refresh();
				print_menu(menuw);
			}

			if (i == 4)
			{
				miw = newwin(10, 70, 5, 33);
				wclear(miw);
				mvwprintw(miw, 2, 2, "UNIVERSIDAD SAN CARLOS DE GUATEMALA");
				mvwprintw(miw, 3, 2, "ESTRUCTURA DE DATOS");
				mvwprintw(miw, 6, 2, "For Source code visit :");
				wattrset(miw, COLOR_PAIR(12));
				mvwprintw(miw, 4, 2, "  \"201700656\"");
				mvwprintw(miw, 5, 2, "  \"pedromartinf07@gmail.com\"");
				mvwprintw(miw, 7, 2, "  \"https://github.com/usuario80/EDD_1S2020_PY1_201700656.git\"");
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

void Ventana::menuGame()
{

	keypad(gamew, TRUE);
	initscr();
	while (1)
	{
		initialise_colors();
		bkgd(COLOR_PAIR(9));
		refresh();
		int play = menu();
		if (play == -1) //salir del juego
		{
			delwin(gamew);
			endwin();
			return;
		}
		if (play == -2) //continuar
			continue;
		init_windows();
		if (play == -3) //sin funcionalidad por el momento
		{
			//y = -3;
			//level = 0;
		}
		//inicia la ventana del juego
		nodelay(stdscr, TRUE);
		play_game();

		clear();
		refresh();
	}
	delwin(gamew);
	endwin();
}

/* View config read file json init
 */
void Ventana::score_general(char *message)
{
	nodelay(stdscr, FALSE);
	char ch, str[15];
	addpw = newwin(15, 45, 4, 40);
	box(addpw, ACS_VLINE, ACS_HLINE);
	wattrset(addpw, COLOR_PAIR(14));
	mvwprintw(addpw, 1, (getmaxx(addpw) / 2) - 5, "Highscores");
	wrefresh(addpw);

	if (lscoreJugador->size() == 0)
	{
		wattrset(addpw, COLOR_PAIR(16));
		mvwprintw(addpw, 6, (getmaxx(addpw) / 2) - 10, "Lista Score Vacia!!");
		mvwprintw(addpw, getmaxy(addpw) - 2, (getmaxx(addpw) / 2) - 17.5, "Presiona cualquier tecla para salir");
		wrefresh(addpw);
		ch = getch();
		return;
	}

	wattrset(addpw, COLOR_PAIR(14));
	mvwprintw(addpw, 1, (getmaxx(addpw) / 2) - 5, "Highscores");
	mvwprintw(addpw, getmaxy(addpw) - 2, (getmaxx(addpw) / 2) - 17.5, "Presiona cualquier tecla para salir");
	wattroff(addpw, COLOR_PAIR(14));
	mvwprintw(addpw, 3, 2, "No.");
	mvwprintw(addpw, 3, 2 + strlen("No.") + 6, "Player Name");
	mvwprintw(addpw, 3, 2 + strlen("No.") + 6 + strlen("Player Name") + 8, "Points");
	wrefresh(addpw);

	int j = 4;
	for (int i = 0; i < lscoreJugador->size(); i++)
	{
		if (i < 9)
		{
			Jugador *jtmp = lscoreJugador->getData();
			mvwprintw(addpw, j, 2 + 1, "%d", i + 1);
			mvwprintw(addpw, j, 2 + strlen("No.") + 6, jtmp->getName().c_str());
			mvwprintw(addpw, j, 2 + strlen("No.") + 6 + strlen("Player Name") + 8 + 2, "%d", jtmp->getScoreMax());
			j++;
			wrefresh(addpw);
		}
	}
	ch = getch();
	nodelay(stdscr, TRUE);
	//delete lscoreJugador;
}

//play game
void Ventana::play_game()
{
}

// Draws or erases the block depending on the del value
void Ventana::draw_block(WINDOW *win, int y, int x, int type, int orient, char del)
{
	int i;
	//DOT dot;

	for (i = 0; i < 4; i++)
	{
		//dot = block_data[type][orient][i];
		//wattron(win, COLOR_PAIR(del ? 9 : dot.clr));
		//mvwprintw(win, y + dot.y, 2 * (x + dot.x), "  ");
	}
	if (del == 0)
		wrefresh(win);
	wattroff(win, COLOR_PAIR(del ? 9 : 1));
	box(win, ACS_VLINE, ACS_HLINE);
	wrefresh(win);
}

//Redraws well
void Ventana::update_well()
{
	/*int y = 0, x = 0, i;
	for (x = 0; x < WELL_WIDTH; x++)
	{
		for (y = 0; y < WELL_HEIGHT; y++)
		{
			if (*yx2pointer(y, x) > 0)
			{
				wattrset(wellw, COLOR_PAIR(*yx2pointer(y, x)));
				mvwprintw(wellw, y, 2 * x, "  ");
			}
			else
			{
				wattrset(wellw, COLOR_PAIR(9));
				mvwprintw(wellw, y, 2 * x, "  ");
			}
		}
	}*/
	wattroff(wellw, COLOR_PAIR(1));
	box(wellw, ACS_VLINE, ACS_HLINE);
	wrefresh(wellw);
}

//genera la cuadricula
void Ventana::draw_grid()
{
	int i, j;
	waddch(wellw, ACS_ULCORNER);
}

//asigna fichas de la cola a los jugadores
void Ventana::asignar_fichas()
{
	
	for (int i = 0; i < colaFicha->size(); i++)
	{
		if (i < 7)
		{
			//player1->lfichas.insertarUltimo(colaFicha->del_headS());
		}
	}
	for (int i = 0; i < colaFicha->size(); i++)
	{
		if (i < 7)
		{
			//player2->lfichas.insertarUltimo(colaFicha->del_headS());
		}
	}
	Reporte r = Reporte();
	r.ReporteFichasCola(colaFicha);
	//r.ReporteFichasUsuario(&player1->lfichas, player1->getName());

}

//destructor
Ventana::~Ventana() {}
