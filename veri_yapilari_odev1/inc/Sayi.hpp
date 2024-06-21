/**
* @file Sayi.hpp
* @description Sayi Sinifi Tanimi
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef Sayi_hpp
#define Sayi_hpp
#include "Basamak.hpp"

class Sayi
{
public:
    Basamak *ilk;
    int sayi;
    int uzunluk;
    int *p;

    Sayi();

    Sayi(int);

    int basamaksayisibul(int);

    int *basamaklari_ayir(int);

    Basamak *FindPrevByPosition(int);

    int hesapla() const;

    void BasamakEkle(int);

    int indexof(const int &);

    int p_indexof(const Basamak *);

    bool bosmu();

    void BasamakSil(int);

    void clear();

    ~Sayi();
};
#endif