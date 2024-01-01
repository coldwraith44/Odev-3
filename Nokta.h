#include <iostream>
#include <string>
#ifndef NOKTA_H
#define NOKTA_H

class Nokta {
private:
    double x;
    double y;

public:
    // parametresiz yap�c�
    Nokta() : x(0), y(0) {}

    // tek parametreli yap�c�
    Nokta(double val) : x(val), y(val) {}

    // iki parametreli yap�c�
    Nokta(double x, double y) : x(x), y(y) {}

    // ba�ka bir noktay� al�p o noktan�n bir kopyas�n� yeni nokta olarak �reten yap�c�
    Nokta(const Nokta& nokta) : x(nokta.x), y(nokta.y) {}

    // ba�ka bir nokta ve iki double de�i�ken alarak yeni bir nokta �retir
    Nokta(const Nokta& nokta, double ofset_x, double ofset_y) : x(nokta.x + ofset_x), y(nokta.y + ofset_y) {}

    // x ve y koordinatlar� i�in get ve set metotlar�
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    // ayn� anda iki koordinat alan ve noktan�n x ve y koordinatlar�n�n de�erlerini de�i�tiren bir set metodu
    void set(double x, double y) {
        this->x = x;
        this->y = y;
    }

    // toString metodu noktan�n koordinatlar�n�n string g�sterimini d�nd�r�r
    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    // yazdir metodu: toString metodunu kullanarak ekrana koordinatlar� yazd�r�r
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
#endif