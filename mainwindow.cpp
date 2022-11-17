#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <pthread.h>

const int num_intersections = 7;
pthread_mutex_t intersections[num_intersections];


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i=0;i<num_intersections;++i)
        pthread_mutex_init(&intersections[i], NULL);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,310,0, intersections);
    trem2 = new Trem(2,730,50, intersections);
    trem3 = new Trem(3, 60, 180, intersections);
    trem4 = new Trem(4, 460, 240, intersections);
    trem5 = new Trem(5, 870, 180, intersections);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

        trem1->start();
        trem2->start();
        trem3->start();
        trem4->start();
        trem5->start();

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    for(int i=0;i<num_intersections;++i)
        pthread_mutex_destroy(&intersections[i]);
}


void MainWindow::on_T1Slider_sliderMoved(int position)
{
    trem1->setVelocidade(position);
}

void MainWindow::on_T2Slider_sliderMoved(int position)
{
   trem2->setVelocidade(position);
}

void MainWindow::on_T3Slider_sliderMoved(int position)
{
   trem3->setVelocidade(position);
}

void MainWindow::on_T4Slider_sliderMoved(int position)
{
   trem4->setVelocidade(position);
}

void MainWindow::on_T5Slider_sliderMoved(int position)
{
   trem5->setVelocidade(position);
}
