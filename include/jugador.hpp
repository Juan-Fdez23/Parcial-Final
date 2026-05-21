#pragma once



struct jugador{
   int x, y;
   int ItemCargado;
   int hP;
};

struct EstadoDelJuego;
void APDJ(EstadoDelJuego& juego, char tecla);
