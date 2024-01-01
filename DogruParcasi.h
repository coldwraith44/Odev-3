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
    // iki u� noktay� nokta nesnesi olarak alan yap�c�
    DogruParcasi(const Nokta& p1, const Nokta& p2) : p1(p1), p2(p2) {}

    // ba�ka bir DogruParcasi nesnesi al�p onun bir kopyas�n� yeni bir DogruParcasi nesnesi olarak olu�turan yap�c�
    DogruParcasi(const DogruParcasi& dp) : p1(dp.p1), p2(dp.p2) {}

    // bir nokta nesnesi,par�an�n uzunlu�u ve e�imi de�erlerini alarak do�ru par�as�n�n x ve y koordinatlar�n� hesaplayan yap�c�
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
        double deltaX = uzunluk / 2 * cos(egim);
        double deltaY = uzunluk / 2 * sin(egim);
        p1.set(ortaNokta.getX() - deltaX, ortaNokta.getY() - deltaY);
        p2.set(ortaNokta.getX() + deltaX, ortaNokta.getY() + deltaY);
    }

    // ilgili get ve set metotlar�
    Nokta getP1() const { return p1; }
    Nokta getP2() const { return p2; }
    void setP1(const Nokta& p) { p1 = p; }
    void setP2(const Nokta& p) { p2 = p; }

    // uzunluk metodu: DogruParcasi nesnesinin uzunlu�unun double de�i�ken olarak hesaplar ve d�nd�r�r
    double uzunluk() const {
        return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    }

    // kesi�imNoktas� metodu: bir nokta nesnesini parametre olarak al�r bu noktadan do�ru par�as�na dik olarak �izilecek do�ru par�as�n�n kesi�me noktas�n� hesaplar ve bir nokta nesnesi olarak d�nd�r�r
    Nokta kesisimNoktas�(const Nokta& p) const {
        double m1 = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        double m2 = -1 / m1;
        double x = (m2 * p.getX() - m1 * p1.getX() + p1.getY() - p.getY()) / (m2 - m1);
        double y = m2 * (x - p.getX()) + p.getY();
        return Nokta(x, y);
    }

    // ortaNokta metodu: do�ru par�as�n�n orta noktas�n� hesaplayan ve bir Nokta nesnesi olarak d�nd�r�r
    Nokta ortaNokta() const {
        return Nokta((p1.getX() + p2.getX()) / 2, (p1.getY() + p2.getY()) / 2);
    }

    // toString y�ntemi: ge�erli LineSegment nesnesinin String olarak d�nd�rme. Nesne s�n�f�n�n toString y�ntemini kullanmal�
    std::string toString() const {
        return "DogruParcasi: " + p1.toString() + " - " + p2.toString();
    }

    // yazdir metodu: iki u� noktay� toString metodunu kullanarak ekrana yazd�r�r
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
#endif
