#include "include/juego.hpp"
#include "include/mapa.hpp"

int main(){
    EstadoDelJuego juego;

    Iniciar_Juego(juego);

    while(juego.JuegoEnLoop){
        Juego_Loop(juego);
    }

    Shutdown_Juego(juego);
    return 0;
}
