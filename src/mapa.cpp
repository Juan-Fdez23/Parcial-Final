#include "../include/mapa.hpp"
#include "../include/inventario.hpp"

#include <iostream>

void Construir_Hb0(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[0];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','N','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'W','.','.','.','.','.','.','.','.','P','.','.','.','.','.','.','.','.','.','E'},
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

    room.Este.THb = 1;
    room.Este.requerimiento = R_Salidas::NA;

    room.Oeste.THb = 2;
    room.Oeste.requerimiento = R_Salidas::NA;

    room.Norte.THb = 3;
    room.Norte.requerimiento = R_Salidas::Llave; 

}

void Construir_Hb1(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[1];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','T','T','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','T','T','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','#'},
        {'W','.','.','.','.','.','.','#','.','.','#','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','#','.','.','.','.','#','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','.','.','.','.','.','.','#','#','.','.','.','.','.','#'},
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

    room.esEnemigo = true;
    room.entidad1[0].x = 15;
    room.entidad1[0].y = 5;
    room.entidad1[0].IsVivo = true;
    room.entidad1[0].TipoE = 0;
}

void Construir_Hb2(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[2];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','#','.','#','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','E'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','#'},
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

    room.Este.THb = 0;
    room.Este.requerimiento= R_Salidas::NA;

    room.esEnemigo = true;
    room.entidad1[1].x = 2;
    room.entidad1[1].y = 5;
    room.entidad1[1].IsVivo = true;
    room.entidad1[1].TipoE = 1;
}

void Construir_Hb3(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[3];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','.','.','#','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','E'},
        {'#','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','S','#','#','#','#','#','#','#','#','#'}
    };

    for(int y = 0; y < r; y++)
    {
        for(int x = 0; x < c; x++)
        {
            room.matriz[y][x] = mtemp[y][x];
        }
    }

    room.Sur.THb = 0;
    room.Sur.requerimiento= R_Salidas::NA;

    room.Este.THb = 4;
    room.Este.requerimiento = R_Salidas::Enemigo_Muerto;

    room.esEnemigo = true;
    room.entidad1[1].x = 19;
    room.entidad1[1].y = 2;
    room.entidad1[1].IsVivo = true;
    room.entidad1[1].TipoE = 2;

}

void Construir_Hb4(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[4];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','N','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','.','.','#','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'W','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','#'},
        {'#','.','.','.','.','#','.','.','.','.','#','.','.','.','.','.','.','.','.','#'},
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

    room.Norte.THb = 5;
    room.Sur.requerimiento= R_Salidas::Llave;

    

    room.esEnemigo = true;
    room.entidad1[0].x = 19;
    room.entidad1[0].y = 2;
    room.entidad1[0].IsVivo = true;
    room.entidad1[0].TipoE = 0;

}

void Construir_Hb5(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[5];

    char mtemp[r][c] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','W','I','N','N','E','R','.','.','.','.','.','.','.','.','#'},
        {'W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','S','#','#','#','#','#','#','#','#','#'}
    };

    for(int y = 0; y < r; y++)
    {
        for(int x = 0; x < c; x++)
        {
            room.matriz[y][x] = mtemp[y][x];
        }
    }

     room.Norte.THb = 4;
    room.Sur.requerimiento= R_Salidas::NA;

    room.esEnemigo = false;
    
}



void inHb(EstadoDelJuego& juego){
    Construir_Hb0(juego);
    Construir_Hb1(juego);
    Construir_Hb2(juego);
    Construir_Hb3(juego);
    Construir_Hb4(juego);
    Construir_Hb5(juego);
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
        return juego.player.ItemCargado == TipodeItem::Llave;
    }

    if(exit.requerimiento == R_Salidas::Enemigo_Muerto){
        Hb& room = juego.habitaciones[juego.Hb_Actual];
        return !room.entidad1[0].IsVivo;
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

            bool dibujadoEnemigo = false;
            for(int i = 0; i < 2; i++){
                Enemigo& enemigo = room.entidad1[i];
                if(enemigo.IsVivo && enemigo.x == x && enemigo.y == y){
                    if(enemigo.TipoE == 0){
                        std::cout<< "\033[31m██\033[0m";
                    }else if(enemigo.TipoE == 1){
                        std::cout<< "\033[35m██\033[0m";
                    }else if(enemigo.TipoE == 2){
                        std::cout<< "\033[36m██\033[0m";
                    }

                    dibujadoEnemigo = true;

                    break;
                 }
            }

            if(dibujadoEnemigo) continue;
        
    
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
    std::cout <<"[WASD] Mover/Caminar | [E] Tomar | [F] Atacar (Cuando tienes la espada) | [Q] Soltar | [X] Salir del juego. \n";
    std::cout << "[¬ Llave (algunas puertas necesitan llave)] | [-+] Espada (para acabar con los enemigos)";
    std::cout << "\nHP: ";

    for(int i = 0; i < juego.player.hP; i++){
        std::cout << "[]";
    }

std::cout << "\n";
}

void ActualizarEnemigo(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[juego.Hb_Actual];
    for(int i = 0; i < 2; i++){
        Enemigo& enemigo = room.entidad1[i];

        if(!enemigo.IsVivo){
            continue;
        }
        if(enemigo.TipoE == 0){
            if(juego.player.x < enemigo.x){
                enemigo.x--;
            }else if(juego.player.x > enemigo.x){
                enemigo.x++;
            }
            if(juego.player.y < enemigo.y){
                enemigo.y--;
            }else if(juego.player.y > enemigo.y){
                enemigo.y++;
            }
        }else if(enemigo.TipoE == 1){
            if(juego.player.x < enemigo.x){
                enemigo.x--;
            }else if(juego.player.x > enemigo.x){
                enemigo.x++;
            }
        }else if(enemigo.TipoE == 2){
            if(juego.player.y < enemigo.y){
                enemigo.y--;
            }else if(juego.player.y > enemigo.y){
                enemigo.y++;
            }
        }
        if(enemigo.x == juego.player.x && enemigo.y == juego.player.y){
            juego.player.hP--;
        }
    }
}

void AtacarEnemigo(EstadoDelJuego& juego){
    Hb& room = juego.habitaciones[juego.Hb_Actual];
    if(juego.player.ItemCargado != TipodeItem::Espada) return;
    for(int i=0; i < 2; i++){
        Enemigo& enemigo = room.entidad1[i];
        if(!enemigo.IsVivo) continue;

        int dx = enemigo.x - juego.player.x;
        int dy = enemigo.y - juego.player.y;

        if(dx < 0) dx = -dx;
        if(dy < 0) dy = -dy;

        if(dx <=1 && dy <=1){
            enemigo.IsVivo = false;
        }

    }
}
