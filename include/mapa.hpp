#pragma once

#include "juego.hpp"
#include "enemigo.hpp"

const int c = 20; // Columnas
const int r = 10; // Filas

struct Salidas{
    int THb;
    int requerimiento;
};

struct R_Salidas{
    static const int NA = 0;
    static const int Llave = 1;
    static const int Enemigo_Muerto = 2;
};

struct Hb{
    char matriz[r][c];
    Enemigo entidad1[2];

    bool esEnemigo;
    Salidas Norte;
    Salidas Sur;
    Salidas Este;
    Salidas Oeste;
};

struct EstadoDelJuego{
    jugador player;
    inventario item[8];
    Hb habitaciones[6];
    int Hb_Actual;
    int Velocidad_Enemigo;
    bool JuegoEnLoop;
};

void inHb(EstadoDelJuego& juego);
void DibujarMapa(EstadoDelJuego& juego);
bool IsMuro(EstadoDelJuego& juego, int x, int y);
bool PuedeSalir(EstadoDelJuego& juego, Salidas& salida);
void TransicionDeHb(EstadoDelJuego& juego);

void ActualizarEnemigo(EstadoDelJuego& juego);
void AtacarEnemigo(EstadoDelJuego& juego);
