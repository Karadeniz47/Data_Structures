/**
* @file Dugum.hpp
* @description Dugum Sinifi Tanimi
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef Dugum_hpp
#define Dugum_hpp
#include "Sayi.hpp"

class Dugum
{
public:
    Sayi *sayi_p;
    Dugum *d_sonraki;

    Dugum(Sayi *, Dugum *);

    ~Dugum();
};
#endif