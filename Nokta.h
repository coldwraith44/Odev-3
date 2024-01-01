#include <iostream>
#include <string>
#ifndef NOKTA_H
#define NOKTA_H

class Nokta {
private:
    double x;
    double y;

public:
    // parametresiz yapýcý
    Nokta() : x(0), y(0) {}

    // tek parametreli yapýcý
    Nokta(double val) : x(val), y(val) {}

    // iki parametreli yapýcý
    Nokta(double x, double y) : x(x), y(y) {}

    // baþka bir noktayý alýp o noktanýn bir kopyasýný yeni nokta olarak üreten yapýcý
    Nokta(const Nokta& nokta) : x(nokta.x), y(nokta.y) {}

    // baþka bir nokta ve iki double deðiþken alarak yeni bir nokta üretir
    Nokta(const Nokta& nokta, double ofset_x, double ofset_y) : x(nokta.x + ofset_x), y(nokta.y + ofset_y) {}

    // x ve y koordinatlarý için get ve set metotlarý
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    // ayný anda iki koordinat alan ve noktanýn x ve y koordinatlarýnýn deðerlerini deðiþtiren bir set metodu
    void set(double x, double y) {
        this->x = x;
        this->y = y;
    }

    // toString metodu noktanýn koordinatlarýnýn string gösterimini döndürür
    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    // yazdir metodu: toString metodunu kullanarak ekrana koordinatlarý yazdýrýr
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
#endif