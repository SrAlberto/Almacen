#include "brisca.h"
#include "ui_brisca.h"
#include <QMessageBox>

brisca::brisca(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::brisca)
{
    ui->setupUi(this);
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
        if (ele!=ui->hCartaEchada1 || ele!=ui->hCartaEchada2 || ele!=ui->hueco_mazo) {
            ele->setStyleSheet("");
        }
    }
}

void brisca::on_hCarta1J1_clicked()
{
  //Si esta pulsada la dejamos presionada
    if(ui->hCarta1J1->isChecked()){
        botonPress(ui->hCarta1J1);
    }else{
        botonRelease(ui->hCarta1J1);
    }
}

void brisca::botonPress(QPushButton* bt){
    //Obtenemos su posición
      geo= bt->geometry();
    //Movemos la Carta 5 pixles tanto abajo como a la derecha
      geo.translate(5,5);
      bt->setGeometry(geo);
    //La hacemos más pequeña
      bt->resize(*sm);
    //La cambiamos el diseño
      QString ss= bt->styleSheet();
      msg.setText(ss);msg.show();
      bt->setStyleSheet(qb+brepo+jksm+"}");
      ui->hCartaEchada1->setStyleSheet(bt->styleSheet());
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
