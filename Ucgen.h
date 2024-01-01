#include "Nokta.h"
#include "DogruParcasi.h"
#include <cmath>
#include <iostream>
#ifndef UCGEN_H
#define UCGEN_H
class Ucgen {
private:
    Nokta p1;
    Nokta p2;
    Nokta p3;

public:
    // üç tane Nokta nesnesi alan yapýcý
    Ucgen(const Nokta& p1, const Nokta& p2, const Nokta& p3) : p1(p1), p2(p2), p3(p3) {}

    // ilgili get ve set metotlarý
    Nokta getP1() const { return p1; }
    Nokta getP2() const { return p2; }
    Nokta getP3() const { return p3; }
    void setP1(const Nokta& p) { p1 = p; }
    void setP2(const Nokta& p) { p2 = p; }
    void setP3(const Nokta& p) { p3 = p; }

    // toString metodu: Üçgenin string temsilini þu þekilde döndürür: üçgen , onun noktalarý
    std::string toString() const {
        return "Ucgen; onun noktalarý: " + p1.toString() + ", " + p2.toString() + ", " + p3.toString();
    }

    // alan metodu: bu üç noktanýn temsil ettiði üçgenin alanýný hesaplar ve döndürür
    double alan() const {
        return abs((p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY())) / 2.0);
    }

    // cevre metodu: üçgenin çevresini hesaplar ve döndürür. Yöntem içerisinde üç doðru parçasý oluþturur ve DogruParcasi sýnýfýnýn uzunluk metodunu kullanýr
    double cevre() const {
        DogruParcasi dp1(p1, p2);
        DogruParcasi dp2(p2, p3);
        DogruParcasi dp3(p3, p1);
        return dp1.uzunluk() + dp2.uzunluk() + dp3.uzunluk();
    }

    // acilar metodu: üçgenin açýlarýný üç öðeli double dizi olarak hesaplar ve döndürür
    double* acilar() const {
        double* acilar = new double[3];
        double a = DogruParcasi(p2, p3).uzunluk();
        double b = DogruParcasi(p1, p3).uzunluk();
        double c = DogruParcasi(p1, p2).uzunluk();
        acilar[0] = acos((b * b + c * c - a * a) / (2 * b * c));
        acilar[1] = acos((a * a + c * c - b * b) / (2 * a * c));
        acilar[2] = acos((a * a + b * b - c * c) / (2 * a * b));
        return acilar;
    }
};
#endif

