#ifndef CARTA_H
#define CARTA_H
#include <QString>
#include <QVector>

class Carta {
    protected:
        int baza;//Oros - 0 , Espadas - 1, Copas - 2, Bastos - 3
        int valor;//1, 2, 3, 4, 5, 6, 7, 10, 11, 12
        QString img;//String para luego asignar el StyleSheet

    public:
        Carta();
        Carta(int baza, int valor, QString img) {
            this-> baza = baza;
            this-> valor = valor;
            this-> img = img;
        }

        Carta(int valor) {
            this-> valor = valor;
        }

        Carta(QString img) {
            this-> img = img;
        }

        int getBaza() {
            return baza;
        }

        void setBaza(int baza) {
                this-> baza = baza;
        }

        int getValor() {
                return valor;
        }

        void setValor(int valor) {
                this-> valor = valor;
        }

        QString getImg() {
                return img;
        }

        void setImg(QString img) {
            this-> img = img;
        }
};
#endif // CARTA_H




