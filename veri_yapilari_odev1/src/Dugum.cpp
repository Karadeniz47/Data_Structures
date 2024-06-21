/**
* @file Dugum.cpp
* @description Dugum Sinifi Fonksiyonlarinin Gövdesi
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#include "Dugum.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

Dugum::Dugum(Sayi *p, Dugum *s = NULL)
{
    sayi_p = p;
    d_sonraki = s;
}

Dugum::~Dugum(){}
