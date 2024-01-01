#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef DAIRE_H
#define DAIRE_H
#include "Nokta.h"
#include <cmath>
#include <iostream>

class Daire {
private:
    Nokta merkez;
    double yaricap;

public:
    // merkez ve yar��ap� parametre olarak alan yap�c�
    Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

    // ba�ka bir Daire nesnesi al�p onun bir kopyas�n� yeni bir daire nesnesi olarak olu�turan yap�c�
    Daire(const Daire& d) : merkez(d.merkez), yaricap(d.yaricap) {}

    // ba�ka bir daire nesnesi ve reel bir pozitif x de�eri alarak parametre olarak al�nan daire nesnesini yar��ap� x ile �arp�lm�� olarak kopyalayan yap�c�
    Daire(const Daire& d, double x) : merkez(d.merkez), yaricap(d.yaricap* x) {}

    // alan metodu: dairenin alan�n� d�nd�r�r
    double alan() const {
        return M_PI * pow(yaricap, 2);
    }

    // cevre metodu: dairenin �evresini d�nd�r�r
    double cevre() const {
        return 2 * M_PI * yaricap;
    }

    // kesisim metodu: bir daire nesnesi al�r ve parametre olarak gelen daire metodu �a��ran dairenin i�inde ise 0 daireler birebir �rt���yorsa 1 hi� kesi�im yoksa 2 de�erini d�nd�r�r
    int kesisim(const Daire& d) const {
        double mesafe = sqrt(pow(d.merkez.getX() - merkez.getX(), 2) + pow(d.merkez.getY() - merkez.getY(), 2));
        if (mesafe < abs(yaricap - d.yaricap)) {
            return 0; // i� i�e
        }
        else if (mesafe == abs(yaricap - d.yaricap) || mesafe == yaricap + d.yaricap) {
            return 1; // birebir �rt���yor
        }
        else {
            return 2; // hi� kesi�miyor
        }
    }

    // toString metodu: dairenin merkezi ve yar��ap�n� string halinde d�nd�r�r
    std::string toString() const {
        return "Daire: Merkez = " + merkez.toString() + ", Yar��ap = " + std::to_string(yaricap);
    }

    // yazdir metodu: toString metodunu kullanarak ekrana direnin bilgilerini yazd�r�r
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
#endif

