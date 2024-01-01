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
    // merkez ve yarýçapý parametre olarak alan yapýcý
    Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

    // baþka bir Daire nesnesi alýp onun bir kopyasýný yeni bir daire nesnesi olarak oluþturan yapýcý
    Daire(const Daire& d) : merkez(d.merkez), yaricap(d.yaricap) {}

    // baþka bir daire nesnesi ve reel bir pozitif x deðeri alarak parametre olarak alýnan daire nesnesini yarýçapý x ile çarpýlmýþ olarak kopyalayan yapýcý
    Daire(const Daire& d, double x) : merkez(d.merkez), yaricap(d.yaricap* x) {}

    // alan metodu: dairenin alanýný döndürür
    double alan() const {
        return M_PI * pow(yaricap, 2);
    }

    // cevre metodu: dairenin çevresini döndürür
    double cevre() const {
        return 2 * M_PI * yaricap;
    }

    // kesisim metodu: bir daire nesnesi alýr ve parametre olarak gelen daire metodu çaðýran dairenin içinde ise 0 daireler birebir örtüþüyorsa 1 hiç kesiþim yoksa 2 deðerini döndürür
    int kesisim(const Daire& d) const {
        double mesafe = sqrt(pow(d.merkez.getX() - merkez.getX(), 2) + pow(d.merkez.getY() - merkez.getY(), 2));
        if (mesafe < abs(yaricap - d.yaricap)) {
            return 0; // iç içe
        }
        else if (mesafe == abs(yaricap - d.yaricap) || mesafe == yaricap + d.yaricap) {
            return 1; // birebir örtüþüyor
        }
        else {
            return 2; // hiç kesiþmiyor
        }
    }

    // toString metodu: dairenin merkezi ve yarýçapýný string halinde döndürür
    std::string toString() const {
        return "Daire: Merkez = " + merkez.toString() + ", Yarýçap = " + std::to_string(yaricap);
    }

    // yazdir metodu: toString metodunu kullanarak ekrana direnin bilgilerini yazdýrýr
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
#endif

