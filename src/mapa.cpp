#include "../include/mapa.hpp"
#include "../include/inventario.hpp"

#include <iostream>

void Construir_Hb0(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[0];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','E','.','#'},
        {'#','.','.','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','P','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };

    for(int y = 0; y < r; y++)
    {
        for(int x = 0; x < c; x++)
        {
            room.matriz[y][x] = mtemp[y][x];
        }
    }

    room.Este.THb = 1;
    room.Este.requerimiento = R_Salidas::NA;

    room.esEnemigo = true;

    room.entidad1.x = 15;
    room.entidad1.y = 5;
    room.entidad1.IsVivo = true;
}

void Construir_Hb1(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[1];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','T','T','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','T','T','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };

    for(int y = 0; y < r; y++)
    {
        for(int x = 0; x < c; x++)
        {
            room.matriz[y][x] = mtemp[y][x];
        }
    }

    room.Oeste.THb = 0;
    room.Oeste.requerimiento= R_Salidas::NA;

    room.esEnemigo = false;
}

void inHb(EstadoDelJuego& juego){
    Construir_Hb0(juego);
    Construir_Hb1(juego);
}

bool IsMuro(EstadoDelJuego& juego, int x, int y){
    Hb& room = juego.habitaciones[juego.Hb_Actual];

    char tile = room.matriz[y][x];

    return tile == '#';
}

bool PuedeSalir(EstadoDelJuego& juego, Salidas& exit)
{
    if(exit.THb == -1)
        return false;

    if(exit.requerimiento == R_Salidas::NA)
        return true;

    if(exit.requerimiento == R_Salidas::Llave)
    {
        return juego.player.ItemCargado ==
               TipodeItem::Llave;
    }

    return false;
}

void TransicionDeHb(EstadoDelJuego& juego){

    Hb& room = juego.habitaciones[juego.Hb_Actual];

    char tile = room.matriz[juego.player.y][juego.player.x];

    if(tile == 'E')
    {
        if(PuedeSalir(juego, room.Este))
        {
            ReiniciarObj(juego);
            juego.Hb_Actual = room.Este.THb;

            juego.player.x = 1;
        }
    }

    if(tile == 'W')
    {
        if(PuedeSalir(juego, room.Oeste))
        {
            ReiniciarObj(juego);
            juego.Hb_Actual = room.Oeste.THb;
            juego.player.x = c - 2;
        }
    }

    if(tile == 'N'){
        if(PuedeSalir(juego, room.Norte)){
            ReiniciarObj(juego);
            juego.Hb_Actual = room.Norte.THb;
            juego.player.y = r - 2;
        }
    }

    if(tile == 'S'){
        if(PuedeSalir(juego , room.Sur)){
            ReiniciarObj(juego);
            juego.Hb_Actual = room.Sur.THb;
            juego.player.y = 1;
        }
    }
}

void DibujarMapa(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[juego.Hb_Actual];

    std::cout << "\033[1;38;2;0;0;255m *|MI ADVENTURE / PARCIAL FINAL|* \033[0m \n";
    for(int y = 0; y < r; y++)
    {
        for(int x = 0; x < c; x++)
        {
            if(juego.player.x == x &&
               juego.player.y == y)
            {
                std::cout << "\033[32m██\033[0m";
                continue;
            }

            if(room.esEnemigo &&
               room.entidad1.IsVivo &&
               room.entidad1.x == x &&
               room.entidad1.y == y)
            {
                std::cout <<
                "\033[31m██\033[0m";

                continue;
            }

            bool dibujadoObj = false;

            for(int i = 0; i < 8; i++)
            {
                inventario& item = juego.item[i];

                if(item.IsActivo &&
                    item.hb == juego.Hb_Actual &&
                   item.x == x &&
                   item.y == y 
                )
                {
                    if(item.tipo == TipodeItem::Llave){
                        std::cout <<"\033[33m ¬\033[0m";
                    }else if(item.tipo == TipodeItem::Espada){
                        std::cout << "\033[36m-+\033[0m";
                    }
                    dibujadoObj = true;
                    break;
                }
            }

            if(dibujadoObj)
                continue;

            char tile = room.matriz[y][x];

            switch(tile)
            {
                case '#':
                    std::cout <<
                    "\033[37m██\033[0m";
                    break;

                case '.':
                    std::cout << "  ";
                    break;

                case 'E':
                    std::cout <<
                    "\033[35m>>\033[0m";
                    break;

                case 'W':
                    std::cout <<
                    "\033[35m<<\033[0m";
                    break;

                case 'N':
                    std::cout  << "\033[35m^^\033[0m";
                    break;

                case 'S':
                    std::cout << "\033[35mvv\033[0m";
                    break;
                case 'T':
                    std::cout <<
                    "\033[32mTT\033[0m";
                    break;

                default:
                    std::cout << "  ";
                    break;
            }
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    std::cout <<
    "[WASD] Mover/Caminar | [E] Tomar | [F] Atacar (Cuando tienes la espada) | [Q] Soltar | [X] Salir del juego. \n";
    std::cout << "\nHP: ";

    for(int i = 0; i < juego.player.hP; i++){
    std::cout << "[]";
    }

std::cout << "\n";
}

void ActualizarEnemigo(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[juego.Hb_Actual];

    if(!room.esEnemigo)
        return;

    if(!room.entidad1.IsVivo)
        return;

    int dx = 0;
    int dy = 0;

    if(juego.player.x < room.entidad1.x)
        dx = -1;

    if(juego.player.x > room.entidad1.x)
        dx = 1;

    if(juego.player.y < room.entidad1.y)
        dy = -1;

    if(juego.player.y > room.entidad1.y)
        dy = 1;

    int newX = room.entidad1.x + dx;
    int newY = room.entidad1.y + dy;

    if(!IsMuro(juego, newX, newY))
    {
        room.entidad1.x = newX;
        room.entidad1.y = newY;
    }

    if(room.entidad1.x == juego.player.x &&
       room.entidad1.y == juego.player.y)
    {
        juego.player.hP--;
    }
}

void AtacarEnemigo(EstadoDelJuego& juego)
{
    Hb& room =
    juego.habitaciones[juego.Hb_Actual];

    if(!room.esEnemigo)
        return;

    if(!room.entidad1.IsVivo)
        return;

    if(juego.player.ItemCargado !=
       TipodeItem::Espada)
    {
        return;
    }

    int dx =
    room.entidad1.x - juego.player.x;

    int dy =
    room.entidad1.y - juego.player.y;

    if(dx < 0) dx = -dx;
    if(dy < 0) dy = -dy;

    if(dx <= 1 && dy <= 1)
    {
        room.entidad1.IsVivo = false;
    }
}
