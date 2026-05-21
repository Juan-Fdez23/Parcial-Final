#pragma once

struct jugador{
   int x, y;
   int ItemCargado;
   int hP;
};

struct EstadoDelJuego;
void ActualizarPosicionDelJugador(EstadoDelJuego& juego, char tecla);

