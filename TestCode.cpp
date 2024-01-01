#include "DogruParcasi.h"
#include "Daire.h"
#include "Ucgen.h"
#include "Nokta.h"
#include <locale>

// Test kodu
int main() {
    setlocale(LC_ALL, "Turkish");
    //Nokta
    std::cout << std::endl << "NOKTA SINIFI ���N TEST �IKTILARI:" << std::endl;
    Nokta n1;
    Nokta n2(5);
    Nokta n3(3, 4);
    Nokta n4(n3);
    Nokta n5(n3, 1, -1);

    std::cout << "Olu�turulan 5 noktan�n x ve y de�erleri:" << std::endl;
    n1.yazdir();
    n2.yazdir();
    n3.yazdir();
    n4.yazdir();
    n5.yazdir();

    std::cout << "1. ve 2. noktalar�n g�ncel x ve y de�erleri:" << std::endl;
    n1.setX(10);
    n1.yazdir();
    n2.set(25, 30);
    n2.yazdir();

    //Dogru Parcasi
    std::cout << std::endl << "DOGRUPARCASI SINIFI ���N TEST SONU�LARI:" << std::endl;
    Nokta n11;
    Nokta n21(3, 4);
    DogruParcasi dp(n11, n21);
    DogruParcasi dp2(dp);
    DogruParcasi dp3(n21, 10, 45);

    std::cout << "Olu�turulan 3 do�ru par�as�n�n ba�lang�� ve biti� noktalar�:" << std::endl;
    dp.yazdir();
    dp2.yazdir();
    dp3.yazdir();

    std::cout << "2. do�ru par�as�n�n ba�lang�� ve biti� noktalar�:" << std::endl;
    dp2.setP1(Nokta());
    dp2.yazdir();

    std::cout << "1. do�ru par�as� i�in uzunluk de�eri: " << dp.uzunluk() << std::endl;
    std::cout << "1. do�ru par�as� i�ib orta nokta: " << dp.ortaNokta().toString() << std::endl;

    //Daire
    std::cout << std::endl << "DAIRE SINIFI ���N TEST SONU�LARI:" << std::endl;
    Nokta merkez1(0, 0);
    Daire d1(merkez1, 5);
    Daire d2(d1);
    Daire d3(d2, 3);

    std::cout << "Daire 1: ";
    d1.yazdir();
    std::cout << "Alan: " << d1.alan() << ", �evre: " << d1.cevre() << std::endl;

    std::cout << "Daire 2: ";
    d2.yazdir();
    std::cout << "Alan: " << d2.alan() << ", �evre: " << d2.cevre() << std::endl;

    std::cout << "Daire 3: ";
    d3.yazdir();
    std::cout << "Alan: " << d3.alan() << ", �evre: " << d3.cevre() << std::endl;

    std::cout << "Daire 1 ve Daire 2 Kesi�im Durumu: " << d1.kesisim(d2) << std::endl;
    std::cout << "Daire 1 ve Daire 3 Kesi�im Durumu: " << d1.kesisim(d3) << std::endl;

    //Ucgen
    std::cout << std::endl << "UCGEN SINIFI ���N TEST SONU�LARI:" << std::endl;
    Ucgen ucgen(Nokta(0, 0), Nokta(4, 0), Nokta(0, 3));

    std::cout << ucgen.toString() << std::endl;
    std::cout << "Alan: " << ucgen.alan() << std::endl;
    std::cout << "�evre: " << ucgen.cevre() << std::endl;

    double* acilar = ucgen.acilar();
    std::cout << "A��lar: " << acilar[0] << ", " << acilar[1] << ", " << acilar[2] << std::endl;


    return 0;
}