#include "brisca.h"
#include "ui_brisca.h"
#include <QMessageBox>

brisca::brisca(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::brisca)
{
    ui->setupUi(this);
    srand(time(nullptr));
    configurarUI();
    crearBaraja();
    barajear();
    players= {{ui->hCarta1J1, ui->hCarta2J1, ui->hCarta3J1}, {ui->hCarta1J2, ui->hCarta2J2, ui->hCarta3J2}};
    ui->hCartaPinta->setStyleSheet(qb+monton[0].getImg());monton.remove(0);
    repartir();
}

brisca::~brisca()
{
    delete ui;
}

void brisca::configurarUI(){
    QVector<QPushButton*> gui;
    gui.append(ui->hCartaEchada1);
    gui.append(ui->hCartaEchada2);
    gui.append(ui->hueco_mazo);

    gui.append(ui->hCartaPinta);
    gui.append(ui->hCarta1J1);
    gui.append(ui->hCarta1J2);
    gui.append(ui->hCarta2J1);
    gui.append(ui->hCarta2J2);
    gui.append(ui->hCarta3J1);
    gui.append(ui->hCarta3J2);

    foreach(QPushButton* ele, gui){
        if(ele==ui->hCartaEchada1 || ele==ui->hCartaEchada2 || ele==ui->hueco_mazo){
            ele->setFlat(true);
            ele->setDisabled(true);
        }else{
            ele->setFlat(true);
            ele->setCheckable(true);
            ele->setChecked(false);
        }
        ele->setStyleSheet("");
        if(ele==ui->hueco_mazo){
            ui->hueco_mazo->setStyleSheet("QPushButton{background-image:url(:/'atras_mazo'.png);background-position:center;background-repeat:no-repeat;}");
        }
    }
}

void brisca::on_hCarta1J1_clicked()
{
    botonPress(ui->hCarta1J1, 1);
}

void brisca::on_hCarta2J1_clicked()
{
    botonPress(ui->hCarta2J1, 1);
}

void brisca::on_hCarta3J1_clicked()
{
    botonPress(ui->hCarta3J1, 1);
}

void brisca::on_hCarta1J2_clicked()
{
    botonPress(ui->hCarta1J2, 2);
}

void brisca::on_hCarta2J2_clicked()
{
    botonPress(ui->hCarta2J2, 2);
}

void brisca::on_hCarta3J2_clicked()
{
    botonPress(ui->hCarta3J2, 2);
}

void brisca::botonPress(QPushButton* bt, int n){
  //Si esta pulsada, es una carta grande (aún sin presionar) y su hueco para echar esta vacio, la dejamos presionada,
    if(bt->isChecked() && bt->size()==*md && ((n==1 && ui->hCartaEchada1->styleSheet()=="") || (n==2 && ui->hCartaEchada2->styleSheet()==""))){
      //Obtenemos su posición
        geo= bt->geometry();
      //Movemos la Carta 5 pixles tanto abajo como a la derecha
        geo.translate(5,5);
        bt->setGeometry(geo);
      //La hacemos más pequeña
        bt->resize(*sm);
      //La cambiamos el diseño
      //Vector con la informacion de la carta
        QVector<QString> carta= getCarta(bt);
      //Asigna el StyleSheet a su respectivo hueco
        if(n==1) ui->hCartaEchada1->setStyleSheet(qb+bi+carta[0]+"'/'"+carta[1]+"'.jpg);}");
        else if(n==2) ui->hCartaEchada2->setStyleSheet(qb+bi+carta[0]+"'/'"+carta[1]+"'.jpg);}");
        bt->setStyleSheet(qb+brepo+jksm+"}");
    }else bt->setChecked(false);
}

QVector<QString> brisca::getCarta(QPushButton* bt){
    QVector<QString> carta;
    foreach(QString l, bt->styleSheet().split("'")){
        if(l=="oro" || l=="basto" || l=="copa" || l=="espada"){
            carta.append(l);
        }
        if(l.toInt()>=1 && l.toInt()<=12){
            carta.append(l);
        }
    }
    return carta;
}

void brisca::botonRelease(QPushButton* bt){
  //Obtenemos su posición
    geo= bt->geometry();
  //Movemos la Carta 5 pixles tanto arriba como a la izquierda para recolocarla
    geo.translate(-5,-5);
    bt->setGeometry(geo);
  //La hacemos más grande
    bt->resize(*md);
  //La cambiamos el diseño
    bt->setStyleSheet(qb+atr+brepo+"}"+qbh+jksm+"}");
    ui->hCartaEchada1->setStyleSheet(qb+atr+"}");
}

void brisca::repartir(){
    int cartasRestantes= monton.size()-1;
    foreach(QVector<QPushButton*> pj, players) {
        foreach(QPushButton* bt, pj){
            if(bt->styleSheet()==""){
                if(cartasRestantes>=0){
                    bt->setStyleSheet(qb+jk+"}"+qbh+monton[cartasRestantes].getImg());
                    monton.remove(cartasRestantes);
                }
                cartasRestantes--;
            }
        }
    }
}
