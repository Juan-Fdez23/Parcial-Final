#pragma once

#include <iostream>

#include "jugador.hpp"
#include "inventario.hpp"
#include "mapa.hpp"


struct EstadoDelJuego{
    jugador player;
    inventario item[8];
    Hb habitaciones[6];
    int Hb_Actual;
    int Velocidad_Enemigo;
    bool JuegoEnLoop;
};

void Iniciar_Juego(EstadoDelJuego& juego);
void Shutdown_Juego(EstadoDelJuego& juego);
void Juego_Loop(EstadoDelJuego& juego);

void ActualizarTerminal();
void EsconderCursor();
void MostrarCursor();
void EnableUTF8();
bool TeclaPresionada();
char LeerTecla();
