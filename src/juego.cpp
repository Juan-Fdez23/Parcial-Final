#include "../include/juego.hpp"
#include "../include/jugador.hpp"
#include "../include/mapa.hpp"

void ActualizarTerminal(){
    std::cout << "\033[H";
}

void EsconderCursor(){
    std::cout << "\033[?25l";
}

void MostrarCursor(){
    std::cout << "\033[?25h";
}

void EnableUTF8(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
}

void wait(int ms){
    #ifdef _WIN32

    Sleep(ms);

#else

    usleep(ms * 1000);

#endif
}

bool TeclaPresionada(){
    #ifdef _WIN32

    return _kbhit();

#else

    termios oldt;
    termios newt;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO,
              TCSANOW,
              &newt);

    int oldf =
    fcntl(STDIN_FILENO,
          F_GETFL,
          0);

    fcntl(STDIN_FILENO,
          F_SETFL,
          oldf | O_NONBLOCK);

    int ch = getchar();

    tcsetattr(STDIN_FILENO,
              TCSANOW,
              &oldt);

    fcntl(STDIN_FILENO,
          F_SETFL,
          oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);

        return true;
    }

    return false;
#endif
}

char LeerTecla(){
    #ifdef _WIN32

    return _getch();

    #else

    termios oldt;
    termios newt;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO,
              TCSANOW,
              &newt);

    char ch = getchar();

    tcsetattr(STDIN_FILENO,
              TCSANOW,
              &oldt);

    return ch;

    #endif
}

void Iniciar_Juego(EstadoDelJuego& juego){
    #ifdef _WIN32
    EnableUTF8();
    #endif
    
    EsconderCursor();
    ActualizarTerminal();
    

    juego.JuegoEnLoop = true;

    juego.Hb_Actual = 0;

    juego.player.x = 1;
    juego.player.y = 8;
    juego.player.hP = 5;
    juego.Velocidad_Enemigo = 0;

    juego.player.ItemCargado =
    TipodeItem::Nada;

    inHb(juego);

    IniciarObj(juego);
}

void Shutdown_Game(EstadoDelJuego& juego){
    MostrarCursor();
    ActualizarTerminal();

    std::cout << "Gracias por jugar \n";
}


void Juego_Loop(EstadoDelJuego& juego){
    char tecla = 0;
    if(TeclaPresionada()){
        tecla = LeerTecla();
    }

    if(tecla)
    {
        if(tecla == 'x')
        {
            juego.JuegoEnLoop = false;
            return;
        }

        ActualizarPosicionDelJugador(juego , tecla);

        if(tecla == 'e')
            TomarObj(juego);

        if(tecla == 'q')
            BotarObj(juego);

        if(tecla == 'f')
            AtacarEnemigo(juego);
    }

    juego.Velocidad_Enemigo++;

    if(juego.Velocidad_Enemigo >= 5)
    {
        ActualizarEnemigo(juego);

        juego.Velocidad_Enemigo = 0;
    }

    ActualizarTerminal();

    DibujarMapa(juego);

    std::cout.flush();

    if(juego.player.hP <= 0)
    {
        ActualizarTerminal();

        std::cout
        << "\n\nGAME OVER\n";

        juego.JuegoEnLoop = false;
    }

    wait(100);
}

