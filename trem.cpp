#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y, pthread_mutex_t* intersections){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->intersections = intersections;
    velocidade = 100;
}

void Trem::setVelocidade(int velocidade) {
    this->velocidade = velocidade;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
       if(velocidade < 200) {
           handleTremPosition();
           msleep(velocidade + 20);
       }
    }
}

void Trem::handleTremPosition() {
    switch(ID){
    case 1:     //Trem 1
        if (y == 0 && x < 460){
            if(x == 440)
                pthread_mutex_lock(&intersections[6]);
            x+=10;
        }
        else if (x == 460 && y < 120){
            if(y == 100){
                pthread_mutex_lock(&intersections[0]);
                pthread_mutex_lock(&intersections[1]);
            }
            y+=10;
        }
        else if (x > 190 && y == 120){
            if(x == 440)
                pthread_mutex_unlock(&intersections[6]);
            else if(x == 310)
                pthread_mutex_unlock(&intersections[1]);
            x-=10;
        }
        else{
            if(y == 100){
                pthread_mutex_unlock(&intersections[0]);
            }
            y-=10;
        }
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 2: //Trem 2
        if (y == 0 && x <730){
            if(x == 480)
                pthread_mutex_unlock(&intersections[6]);
            x+=10;
        }
        else if (x == 730 && y < 120){
            if(y == 100)
                pthread_mutex_lock(&intersections[3]);
            y+=10;
        }
        else if (x > 460 && y == 120){
            if(x == 620){
                pthread_mutex_lock(&intersections[6]);
                pthread_mutex_lock(&intersections[2]);
            }
            if(x == 580)
                pthread_mutex_unlock(&intersections[3]);
            x-=10;
        }
        else{
            if(y == 100)
                pthread_mutex_unlock(&intersections[2]);
            y-=10;
        }
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 3: //Trem 3
        if (y == 120 && x < 330){
            if(x == 170){
                pthread_mutex_lock(&intersections[4]);
                pthread_mutex_lock(&intersections[0]);
            }
            x+=10;
        }
        else if (x == 330 && y < 240){
            if(y == 140)
                pthread_mutex_unlock(&intersections[0]);
            y+=10;
        }
        else if (x > 60 && y == 240){
            if(x == 310)
                pthread_mutex_unlock(&intersections[4]);
            x-=10;
        }
        else{
            y-=10;
        }
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 4: //Trem 4
        if (y == 120 && x < 600){
            if(x == 350)
                pthread_mutex_unlock(&intersections[4]);
            else if(x == 480)
                pthread_mutex_unlock(&intersections[1]);
            else if(x == 440)
                pthread_mutex_lock(&intersections[2]);
            else if(x == 580)
                pthread_mutex_lock(&intersections[5]);
            x+=10;
        }
        else if (x == 600 && y < 240){
            if(y == 140)
                pthread_mutex_unlock(&intersections[2]);
            y+=10;
        }
        else if (x > 330 && y == 240){
            if(x == 350)
                pthread_mutex_lock(&intersections[4]);
            else if(x == 580)
                pthread_mutex_unlock(&intersections[5]);
            x-=10;
        }
        else{
            if(y == 140)
                pthread_mutex_lock(&intersections[1]);
            y-=10;
        }
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 5: //Trem 5
        if (y == 120 && x < 870){
            if(x == 620)
                pthread_mutex_unlock(&intersections[5]);
            else if(x == 750)
                pthread_mutex_unlock(&intersections[3]);
            x+=10;
        }
        else if (x == 870 && y < 240)
            y+=10;
        else if (x > 600 && y == 240){
            if(x == 620){
                pthread_mutex_lock(&intersections[3]);
                pthread_mutex_lock(&intersections[5]);
            }
            x-=10;
        }
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    default:
        break;
    }
}


