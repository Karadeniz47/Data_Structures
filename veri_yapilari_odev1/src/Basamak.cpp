/**
* @file Basamak.cpp
* @description Basamak Sinifi Fonksiyonlarinin Gövdesi 
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#include "Basamak.hpp"
#include <iostream>
using namespace std;
Basamak::Basamak()
{
    sonraki = nullptr;
}

Basamak::Basamak(const int &b, Basamak *s = nullptr)
{
    basamak = b;
    sonraki = s;
}

Basamak::~Basamak(){}
