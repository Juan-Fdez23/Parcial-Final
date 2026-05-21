#pragma once

struct inventario{
    int x, y; 
    int Sx, Sy; // Sean "Sx" & "Sy" donde se encuentran por primera vez los objetos.
    int hb, Shb; // Sean "hb" &  "Shb" donde se encuentra el objeto (room).
    int tipo;
    bool IsActivo;
};

struct EstadoDelJuego;

void IniciarObj(EstadoDelJuego& juego);
void TomarObj(EstadoDelJuego& juego);
void BotarObj(EstadoDelJuego& juego);
void ReiniciarObj(EstadoDelJuego& juego);

