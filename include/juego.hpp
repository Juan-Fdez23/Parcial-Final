#pragma once

#include <iostream>

#include "jugador.hpp"
#include "inventario.hpp"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
#endif

struct EstadoDelJuego;


void Iniciar_Juego(EstadoDelJuego& juego);
void Shutdown_Juego(EstadoDelJuego& juego);
void Juego_Loop(EstadoDelJuego& juego);

void ActualizarTerminal();
void EsconderCursor();
void MostrarCursor();
void EnableUTF8();
void wait();
bool TeclaPresionada();
char LeerTecla();
