#pragma once

struct inventario{
    int x, y; 
    int Sx, Sy; // Sean "Sx" & "Sy" donde se encuentran por primera vez los objetos.
    int hb, Shb; // Sean "hb" &  "Shb" donde se encuentra el objeto (room).
    int tipo;
    bool IsActivo;
};

struct TipodeItem{
    static const int Nada = 0;
    static const int Llave = 1;
    static const int Espada = 2;
};


struct EstadoDelJuego;

void IniciarObj(EstadoDelJuego& juego);
void TomarObj(EstadoDelJuego& juego);
void BotarObj(EstadoDelJuego& juego);
void ReiniciarObj(EstadoDelJuego& juego);
