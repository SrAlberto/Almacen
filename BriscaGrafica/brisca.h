#ifndef BRISCA_H
#define BRISCA_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include "carta.h"

namespace Ui {
class brisca;
}

class brisca : public QMainWindow
{
    Q_OBJECT

public:
    explicit brisca(QWidget *parent = nullptr);
  //Destructor
    ~brisca();
  //Configurar UI para que quitar bordes, hacer estáticas las cartas echadas y la baraja, hacerlas que sean un booleano
    void configurarUI();
  //Tamaño normal para las cartas
    QSize *md= new QSize(100,130);
  //Tamaño pequeño para las cartas
    QSize *sm= new QSize(90,120);
  //Nos permite repartir Cartas nuevas una vez echadas las de la mano
    void repartir();

private slots:
  //Cuando las cartas de los jugadores son echadas se pone una en el hueco de las cartas echadas y el resto de la mano se
  //
  //
  //
    void on_hCarta1J1_clicked();

private:
    Ui::brisca *ui;
  //Variables para concatenar en los StyleSheets
    QString qb= "QPushButton{", qbh= "QPushButton:hover{", atr= "background-image: url(:/'atras'.png);",
    atrsm= "background-image: url(:/'atras_sm'.png);", jk= "background-image: url(:/'joker'.png);",
    jksm= "background-image: url(:/'joker_sm'.png);", brepo= " background-repeat:no-repeat;background-position:center;";
  //Vector que contiene las cartas de la baraja ordenadas
    QVector<Carta> baraja;
  //Vector que contiene las cartas de la baraja ya desordenadas
    QVector<Carta> monton;
  //Vector de dos dimensiones que simula a cada jugador
    QVector<QPushButton*> player1;
    QVector<QPushButton*> player2;
    QVector<QVector<QPushButton*>> players;//= {player1, player2};
  //Método que nos crea la baraja
    void crearBaraja(){
        Carta oros1= Carta(0, 1, "background-image:url(:/'oro'/'1_sm'.jpg);"+brepo+"}");
        Carta oros2= Carta(0, 1, "background-image:url(:/'oro'/'2_sm'.jpg);"+brepo+"}");
        Carta oros3= Carta(0, 1, "background-image:url(:/'oro'/'3_sm'.jpg);"+brepo+"}");
        Carta oros4= Carta(0, 1, "background-image:url(:/'oro'/'4_sm'.jpg);"+brepo+"}");
        Carta oros5= Carta(0, 1, "background-image:url(:/'oro'/'5_sm'.jpg);"+brepo+"}");
        Carta oros6= Carta(0, 1, "background-image:url(:/'oro'/'6_sm'.jpg);"+brepo+"}");
        Carta oros7= Carta(0, 1, "background-image:url(:/'oro'/'7_sm'.jpg);"+brepo+"}");
        Carta oros10= Carta(0, 1, "background-image:url(:/'oro'/'10_sm'.jpg);"+brepo+"}");
        Carta oros11= Carta(0, 1, "background-image:url(:/'oro'/'11_sm'.jpg);"+brepo+"}");
        Carta oros12= Carta(0, 1, "background-image:url(:/'oro'/'12_sm'.jpg);"+brepo+"}");

        Carta espadas1= Carta(1, 1, "background-image:url(:/'espada'/'1_sm'.jpg);"+brepo+"}");
        Carta espadas2= Carta(1, 1, "background-image:url(:/'espada'/'2_sm'.jpg);"+brepo+"}");
        Carta espadas3= Carta(1, 1, "background-image:url(:/'espada'/'3_sm'.jpg);"+brepo+"}");
        Carta espadas4= Carta(1, 1, "background-image:url(:/'espada'/'4_sm'.jpg);"+brepo+"}");
        Carta espadas5= Carta(1, 1, "background-image:url(:/'espada'/'5_sm'.jpg);"+brepo+"}");
        Carta espadas6= Carta(1, 1, "background-image:url(:/'espada'/'6_sm'.jpg);"+brepo+"}");
        Carta espadas7= Carta(1, 1, "background-image:url(:/'espada'/'7_sm'.jpg);"+brepo+"}");
        Carta espadas10= Carta(1, 1, "background-image:url(:/'espada'/'10_sm'.jpg);"+brepo+"}");
        Carta espadas11= Carta(1, 1, "background-image:url(:/'espada'/'11_sm'.jpg);"+brepo+"}");
        Carta espadas12= Carta(1, 1, "background-image:url(:/'espada'/'12_sm'.jpg);"+brepo+"}");

        Carta copas1= Carta(2, 1, "background-image:url(:/'copa'/'1_sm'.jpg);"+brepo+"}");
        Carta copas2= Carta(2, 1, "background-image:url(:/'copa'/'2_sm'.jpg);"+brepo+"}");
        Carta copas3= Carta(2, 1, "background-image:url(:/'copa'/'3_sm'.jpg);"+brepo+"}");
        Carta copas4= Carta(2, 1, "background-image:url(:/'copa'/'4_sm'.jpg);"+brepo+"}");
        Carta copas5= Carta(2, 1, "background-image:url(:/'copa'/'5_sm'.jpg);"+brepo+"}");
        Carta copas6= Carta(2, 1, "background-image:url(:/'copa'/'6_sm'.jpg);"+brepo+"}");
        Carta copas7= Carta(2, 1, "background-image:url(:/'copa'/'7_sm'.jpg);"+brepo+"}");
        Carta copas10= Carta(2, 1, "background-image:url(:/'copa'/'10_sm'.jpg);"+brepo+"}");
        Carta copas11= Carta(2, 1, "background-image:url(:/'copa'/'11_sm'.jpg);"+brepo+"}");
        Carta copas12= Carta(2, 1, "background-image:url(:/'copa'/'12_sm'.jpg);"+brepo+"}");

        Carta bastos1= Carta(3, 1, "background-image:url(:/'basto'/'1_sm'.jpg);"+brepo+"}");
        Carta bastos2= Carta(3, 1, "background-image:url(:/'basto'/'2_sm'.jpg);"+brepo+"}");
        Carta bastos3= Carta(3, 1, "background-image:url(:/'basto'/'3_sm'.jpg);"+brepo+"}");
        Carta bastos4= Carta(3, 1, "background-image:url(:/'basto'/'4_sm'.jpg);"+brepo+"}");
        Carta bastos5= Carta(3, 1, "background-image:url(:/'basto'/'5_sm'.jpg);"+brepo+"}");
        Carta bastos6= Carta(3, 1, "background-image:url(:/'basto'/'6_sm'.jpg);"+brepo+"}");
        Carta bastos7= Carta(3, 1, "background-image:url(:/'basto'/'7_sm'.jpg);"+brepo+"}");
        Carta bastos10= Carta(3, 1, "background-image:url(:/'basto'/'10_sm'.jpg);"+brepo+"}");
        Carta bastos11= Carta(3, 1, "background-image:url(:/'basto'/'11_sm'.jpg);"+brepo+"}");
        Carta bastos12= Carta(3, 1, "background-image:url(:/'basto'/'12_sm'.jpg);"+brepo+"}");

        baraja.append(oros1);
        baraja.append(oros2);
        baraja.append(oros3);
        baraja.append(oros4);
        baraja.append(oros5);
        baraja.append(oros6);
        baraja.append(oros7);
        baraja.append(oros10);
        baraja.append(oros11);
        baraja.append(oros12);

        baraja.append(espadas1);
        baraja.append(espadas2);
        baraja.append(espadas3);
        baraja.append(espadas4);
        baraja.append(espadas5);
        baraja.append(espadas6);
        baraja.append(espadas7);
        baraja.append(espadas10);
        baraja.append(espadas11);
        baraja.append(espadas12);

        baraja.append(copas1);
        baraja.append(copas2);
        baraja.append(copas3);
        baraja.append(copas4);
        baraja.append(copas5);
        baraja.append(copas6);
        baraja.append(copas7);
        baraja.append(copas10);
        baraja.append(copas11);
        baraja.append(copas12);

        baraja.append(bastos1);
        baraja.append(bastos2);
        baraja.append(bastos3);
        baraja.append(bastos4);
        baraja.append(bastos5);
        baraja.append(bastos6);
        baraja.append(bastos7);
        baraja.append(bastos10);
        baraja.append(bastos11);
        baraja.append(bastos12);
    }
  //Método que nos bajarea la baraja para tenerla desordenada
    void barajear(){
        while(baraja.size()!=0) {
            int rnd= rand() % baraja.size();
            monton.append(baraja.at(rnd));
            baraja.remove(rnd);
        }
    }
  //Caja de "texto" para pruebas
    QMessageBox msg;
  //Nos permite obtener la posición de la Carta, para luego moverla
    QRect geo;
  //Personalizar la Carta pulsada
    void botonPress(QPushButton* bt);
  //Personalizar la Carta pulsada por segunda vez
    void botonRelease(QPushButton* bt);

};

#endif // BRISCA_H
