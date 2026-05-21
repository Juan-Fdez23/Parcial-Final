#include "../include/jugador.hpp"
#include "../include/mapa.hpp"

void ActualizarPosicionDelJugador(EstadoDelJuego juego, char tecla){
    int nX = juego.player.x;
    int nY = juego.player.y;

    switch(tecla){
        case 'w':{
            nY--;
            break;
        };
        case 's':{
            nY++;
            break;
        };
        case 'a':{
            nX--;
            break;
        };
        case 'd':{
            nX++;
            break;
        }
    }

    if(!IsMuro(juego, nX, nY)){
        juego.player.x = nX;
        juego.player.y = nY;
    }
    TransicionDeHb(juego);
}
