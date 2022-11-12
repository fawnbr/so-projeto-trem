#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
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
        if (y == 0 && x < 460)
            x+=10;
        else if (x == 460 && y < 120)
            y+=10;
        else if (x > 190 && y == 120)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 2: //Trem 2
        if (y == 0 && x <730)
            x+=10;
        else if (x == 730 && y < 120)
            y+=10;
        else if (x > 460 && y == 120)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 3: //Trem 3
        if (y == 120 && x < 330)
            x+=10;
        else if (x == 330 && y < 240)
            y+=10;
        else if (x > 60 && y == 240)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 4: //Trem 4
        if (y == 120 && x < 600)
            x+=10;
        else if (x == 600 && y < 240)
            y+=10;
        else if (x > 330 && y == 240)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 5: //Trem 5
        if (y == 120 && x < 870)
            x+=10;
        else if (x == 870 && y < 240)
            y+=10;
        else if (x > 600 && y == 240)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    default:
        break;
    }
}


