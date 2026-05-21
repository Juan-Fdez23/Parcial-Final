#include "../include/juego.hpp"
#include "../include/jugador.hpp"

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


