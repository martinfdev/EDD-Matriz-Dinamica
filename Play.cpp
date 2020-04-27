/* 
 * File:   Play.cpp
 * Author: pedro
 */
#include "Play.h"

Play::Play(Config *conf, MatrizDispersa *matriz_, ListaDoble<string> *dictionary_, Jugador *player1_, Jugador *player2_, Lista<Ficha *> *colaFichas_)
{
    matriz = matriz_;
    this->conf = conf;
    dimension = conf->getDimension();
    dictionary = dictionary_;
    colaFichas = colaFichas_;
    player1 = player1_;
    player1->setEstado(true);
    player2 = player2_;
    fill_f_p1();
    fill_f_p2();
    socorep1 = socorep2 = 0;
}

void Play::play_game()
{
    int opcion;
    string tmpop, tmpalabra = "";
    generate_grid();
    while (true)
    {
        cout << "1.\tIngresar Palabra\n";
        cout << "2.\tVolver al Menu\n";
        cin >> tmpop;
        opcion = atoi(tmpop.c_str());
        clean_display();
        print_grid();
        switch (opcion)
        {
        case 1:
            if (player1->getEstado())
            {
                tmpCasillas = new Lista<CasillaE *>();
                cout << "Turno Jugador 1\n";
                cout << "Fichas Disponibles\n";
                opcion = turn(player1, tmpalabra);
                player1->setEstado(false);
                player2->setEstado(true);
            }
            else if (player2->getEstado())
            {
                cout << "Turno Jugador 2\n";
                cout << "Fichas Disponibles\n";
                opcion = turn(player2, tmpalabra);
                player1->setEstado(true);
                player2->setEstado(false);
            }
            break;
        case 2:
            reportM();
            return; //volver al menu
            break;
        default:
            cout << "Escoja la opcion correcta!!\n";
            break;
        }
    }
} //genera la matriz para el juego
void Play::generate_grid()
{
    string contenido = " ";
    for (int y = 0; y < dimension; y++)
    {
        for (int x = 0; x < dimension; x++)
        {
            int box = special_box(x, y);
            if (box == 2)
            {
                tmpmatriz.insertMatrix(x, y, "2");
            }
            else if (box == 3)
            {
                tmpmatriz.insertMatrix(x, y, "3");
            }
            else
            {
                tmpmatriz.insertMatrix(x, y, contenido);
            }
        }
    }
}

//imprime la matriz en pantalla
void Play::print_grid()
{
    int number = 0;
    print_line();
    for (int y = 0; y < dimension; y++)
    {
        for (int x = 0; x < dimension; x++)
        {
            printf(" %s |", tmpmatriz.searchM(x, y).c_str());
            number += 1;
        }
        printf("\n");
        print_line();
    }
}

//metodo privado que genera la lineas de division simulacion matriz
void Play::print_line()
{
    for (int y = 0; y < dimension + (dimension / 2); y++)
    {
        if (y == 0)
        {
            printf("%s", " ");
        }
        else
            printf("%s", "---");
    }
    printf("\n");
}

//comprobar casilla especial
int Play::special_box(int x, int y)
{
    Lista<CasillaE *> *ltmpCE = conf->getCasillaE();
    for (int i = 0; i < ltmpCE->size(); i++)
    {
        CasillaE *tmpCE = ltmpCE->getDataC();
        if (tmpCE->getX() == x && tmpCE->getY() == y)
        {
            return tmpCE->getPuntaje();
        }
    }
}

//limpia la pantalla de la consola
void Play::clean_display() { system("clear"); }

//turno de jugadores
int Play::turn(Jugador *jugador, string palabra)
{
    bool banderaM = false;
    int x, y, option;
    string tmpin;
    while (1)
    {
        if (player1->getEstado())
        {
            show_f_player(player1);
        }
        else if (player2->getEstado())
        {
            show_f_player(player2);
        }
        cout << "1.\tIngresar Letra\n";
        cout << "2.\tIntercambiar Fichas\n";
        cout << "3.\tTerminar Turno\n";
        cin >> tmpin;
        option = atoi(tmpin.c_str());
        switch (option)
        {
        case 1:
            cout << "Igresar letra en la fila: ";
            cin >> tmpin;
            y = atoi(tmpin.c_str());
            cout << "\n";
            cout << "Ingresar letra en la columna: ";
            cin >> tmpin;
            x = atoi(tmpin.c_str());
            cout << "\n";
            cout << "Letra: (\"En mayusculas\") ";
            cin >> tmpin;
            palabra = palabra + tmpin;
            //if (player1->getEstado())
            //{
            //    int spebox = special_box(x, y);
            //    if (!f_true(jugador, tmpin, socorep1, spebox))
            //    {
            //        return 1;
            //    }
            //    banderaM = true;
            //}
            //else if (player2->getEstado())
            //{
            //    int spebox = special_box(x, y);
            //    if (!f_true(jugador, tmpin, socorep2, spebox))
            //    {
            //        return 1;
            //    }
            //    banderaM = true;
            //}
            if (x <= dimension && y <= dimension)
            {
                tmpCasillas->add_endS(new CasillaE(x, y, 0));
                tmpmatriz.setData(x, y, tmpin);
                print_grid();
            }
            else
            {
                cout << "indices fuera de rango pierde turno! \n";
            }
            break;
        case 2:
            if (player1->getEstado())
            {
                swap_tokens(player1);
                cout << "Turno Jugador 2\n";
                return 1;
            }
            else if (player2->getEstado())
            {
                swap_tokens(player2);
                cout << "Turno Jugador 1\n";
                return 1;
            }
            break;
        case 3: //termina turno
            if (player1->getEstado())
            {
                if (word_dictionary(palabra))
                {
                    player1->setScore(socorep1);
                    socorep1 = 0;
                    palabra = "";
                }
                socorep1 = 0;
                palabra = "";
                cout << "Turno Jugador 2\n";
                player2->setEstado(1);
                player1->setEstado(0);
            }
            else if (player2->getEstado())
            {
                if (word_dictionary(palabra))
                {
                    player2->setScore(socorep2);
                    socorep2 = 0;
                    palabra = "";
                }
                socorep2 = 0;
                palabra = "";
                cout << "Turno Jugador 1\n";
                player1->setEstado(1);
                player2->setEstado(0);
            }
            break;
        default:
            return 0;
        }
    }
}

//comprobar diccionario
bool Play::word_dictionary(string palabra)
{
    ListaDoble<string> *tmp = dictionary;
    int size = tmp->getSize();
    for (int i = 0; i < size; i++)
    {
        string tmpString = tmp->getDataC();
        if (tmpString == palabra)
        {
            //cout << tmpString << " \n";
            return true;
        }
    }
    return false;
}

//imprime el diccionario
void Play::print_dictionary()
{
    ListaDoble<string> *tmp = dictionary;
    cout << "Diccionario de Palabras Validas\n";
    int size = tmp->getSize();
    for (int i = 0; i < size; i++)
    {
        cout << tmp->getDataC() << " ";
    }
    cout << "\n";
}

//revierte las casillas con valor si no se cumple la condicion de que existe la palabra en el diccionario
void Play::reverse()
{
    int x, y, size;
    size = tmpCasillas->size();
    for (int i = 0; i < size; i++)
    {
        CasillaE *tmpC = tmpCasillas->getData();
        x = tmpC->getX();
        y = tmpC->getY();
        tmpmatriz.insertMatrix(x, y, " ");
    }
}

//llenar ficha de jugadores
void Play::fill_f_p1()
{
    ListaDoble<Ficha *> *tmplfp1 = new ListaDoble<Ficha *>();
    for (int i = 0; i < 7; i++)
    {
        Ficha *tmpf = colaFichas->del_headS();
        tmplfp1->insertarUltimo(tmpf);
    }
    player1->setFicha(tmplfp1);
}

void Play::fill_f_p2()
{
    ListaDoble<Ficha *> *tmplfp2 = new ListaDoble<Ficha *>();
    for (int i = 0; i < 7; i++)
    {
        Ficha *tmpf = colaFichas->del_headS();
        tmplfp2->insertarUltimo(tmpf);
    }
    player2->setFicha(tmplfp2);
}

//mostrar las fichar de jugador
void Play::show_f_player(Jugador *player_)
{
    ListaDoble<Ficha *> tmplf = *player_->getFicha();
    int size = tmplf.getSize();
    for (int i = 0; i < size; i++)
    {
        Ficha *f = tmplf.getDataNext();
        cout << f->getLetra() << " ";
    }
    cout << "\n";
}

//intercambiar fichas opcion de juego
void Play::swap_tokens(Jugador *player)
{
    if (player == player1)
    {
        swap_f(player);
        //player1->setEstado(false);
        //player2->setEstado(true);
        fill_f_p1();
    }
    else if (player == player2)
    {
        swap_f(player);
        //player2->setEstado(false);
        // player1->setEstado(true);
        fill_f_p2();
    }
}

//intercambiar fichas
void Play::swap_f(Jugador *player)
{
    ListaDoble<Ficha *> *tmpldf = player->getFicha();
    int size = tmpldf->getSize();
    for (int i = 0; i < size; i++)
    {
        Ficha *tmpf = tmpldf->borrarFinal();
        colaFichas->add_endS(tmpf);
        //random_f();
    }
}

//intercambiar fichas
void Play::random_f()
{
    int ran, size;
    size = colaFichas->size();
    srand(time(NULL));
    for (size_t i = 0; i < 5; i++)
    {
        ran = 1 + rand() % (size - 1);
        Ficha *tmpF = colaFichas->del_by_position(ran);
        colaFichas->add_endS(tmpF);
    }
}

//comprobar si es la ficha correcta
bool Play::f_true(Jugador *player, string entrada, int score, int spebox)
{
    ListaDoble<Ficha *> tmpl = *player->getFicha();
    int size = tmpl.getSize();
    for (int i = 0; i < size; i++)
    {
        Ficha *tmp = tmpl.getDataNext();
        if (tmp->getLetra() == entrada)
        {
            score = score + tmp->getPuntaje() * spebox;
            tmp->setCantidad(tmp->getCantidad() - 1);
            if (tmp->getCantidad() == 0)
            {
                delete tmp;
            }
            return true;
        }
        else
            return false;
    }
}

//reporte matriz
void Play::reportM(){
   
    for (int y = 0; y < dimension; y++)
    {
        for (int x = 0; x < dimension; x++)
        {
            if (tmpmatriz.searchM(x, y)!=" " && tmpmatriz.searchM(x,y)!="2" &&tmpmatriz.searchM(x,y)!="3")
            {
                matriz->insertMatrix(x, y, tmpmatriz.searchM(x, y));
            }
        }
    }
}

//drestructor
Play::~Play() {}