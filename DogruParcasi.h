#include "Nokta.h"
#include <cmath>
#include <iostream>
#ifndef DOGRUPARCASI_H
#define DOGRUPARCASI_H
class DogruParcasi {
private:
    Nokta p1;
    Nokta p2;

public:
    // iki uç noktayý nokta nesnesi olarak alan yapýcý
    DogruParcasi(const Nokta& p1, const Nokta& p2) : p1(p1), p2(p2) {}

    // baþka bir DogruParcasi nesnesi alýp onun bir kopyasýný yeni bir DogruParcasi nesnesi olarak oluþturan yapýcý
    DogruParcasi(const DogruParcasi& dp) : p1(dp.p1), p2(dp.p2) {}

    // bir nokta nesnesi,parçanýn uzunluðu ve eðimi deðerlerini alarak doðru parçasýnýn x ve y koordinatlarýný hesaplayan yapýcý
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
        double deltaX = uzunluk / 2 * cos(egim);
        double deltaY = uzunluk / 2 * sin(egim);
        p1.set(ortaNokta.getX() - deltaX, ortaNokta.getY() - deltaY);
        p2.set(ortaNokta.getX() + deltaX, ortaNokta.getY() + deltaY);
    }

    // ilgili get ve set metotlarý
    Nokta getP1() const { return p1; }
    Nokta getP2() const { return p2; }
    void setP1(const Nokta& p) { p1 = p; }
    void setP2(const Nokta& p) { p2 = p; }

    // uzunluk metodu: DogruParcasi nesnesinin uzunluðunun double deðiþken olarak hesaplar ve döndürür
    double uzunluk() const {
        return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    }

    // kesiþimNoktasý metodu: bir nokta nesnesini parametre olarak alýr bu noktadan doðru parçasýna dik olarak çizilecek doðru parçasýnýn kesiþme noktasýný hesaplar ve bir nokta nesnesi olarak döndürür
    Nokta kesisimNoktasý(const Nokta& p) const {
        double m1 = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        double m2 = -1 / m1;
        double x = (m2 * p.getX() - m1 * p1.getX() + p1.getY() - p.getY()) / (m2 - m1);
        double y = m2 * (x - p.getX()) + p.getY();
        return Nokta(x, y);
    }

    // ortaNokta metodu: doðru parçasýnýn orta noktasýný hesaplayan ve bir Nokta nesnesi olarak döndürür
    Nokta ortaNokta() const {
        return Nokta((p1.getX() + p2.getX()) / 2, (p1.getY() + p2.getY()) / 2);
    }

    // toString yöntemi: geçerli LineSegment nesnesinin String olarak döndürme. Nesne sýnýfýnýn toString yöntemini kullanmalý
    std::string toString() const {
        return "DogruParcasi: " + p1.toString() + " - " + p2.toString();
    }

    // yazdir metodu: iki uç noktayý toString metodunu kullanarak ekrana yazdýrýr
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
#endif
