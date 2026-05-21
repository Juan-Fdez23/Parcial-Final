#include "../include/inventario.hpp"
#include "../include/juego.hpp"
#include "../include/jugador.hpp"

void IniciarObj(EstadoDelJuego& juego){
    for(int i = 0; i < 8; i++)
    {
        juego.item[i].IsActivo = false;
    }

    juego.item[0].x = 10;
    juego.item[0].y = 5;
    juego.item[0].hb = 0;
    juego.item[0].Sx = 10;
    juego.item[0].Sy = 5;
    juego.item[0].Shb = 0;
    juego.item[0].tipo = TipodeItem::Llave;
    juego.item[0].IsActivo = true;

    juego.item[1].x = 15;
    juego.item[1].y = 6;
    juego.item[1].hb = 1;
    juego.item[1].Sx = 15;
    juego.item[1].Sy = 6;
    juego.item[1].Shb = 1;
    juego.item[1].tipo = TipodeItem::Espada;
    juego.item[1].IsActivo = true;
}

void TomarObj(EstadoDelJuego& juego){
     if(juego.player.ItemCargado !=TipodeItem::Nada)
        return;

    for(int i = 0; i < 8; i++)
    {
        inventario& item = juego.item[i];

        if(!item.IsActivo)
            continue;

        if(item.IsActivo && item.hb == juego.Hb_Actual && item.x == juego.player.x &&
           item.y == juego.player.y)
        {
            juego.player.ItemCargado = item.tipo;

            item.IsActivo = false;

            break;
        }
    }
}

void BotarObj(EstadoDelJuego& juego)
{
    if(juego.player.ItemCargado == TipodeItem::Nada)
        return;

    for(int i = 0; i < 8; i++)
    {
        inventario& item = juego.item[i];

        if(item.IsActivo)
            continue;

        item.x = juego.player.x;
        item.y = juego.player.y;

        item.hb = juego.Hb_Actual;
        item.tipo = juego.player.ItemCargado;

        item.IsActivo = true;
        
       juego.player.ItemCargado = TipodeItem::Nada;

        break;
    }
}

void ReiniciarObj(EstadoDelJuego& juego){
    for(int i = 0; i< 16; i++){
        inventario& item = juego.item[i];
        if(item.IsActivo){
            item.x = item.Sx;
            item.y = item.Sy;
            item.hb = item.Shb; 
        }
    }
}
