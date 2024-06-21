/**
* @file Basamak.hpp
* @description Basamak Sinifi Tanimi
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef Basamak_hpp
#define Basamak_hpp

class Basamak
{
public:
    int basamak;
    Basamak *sonraki;

    Basamak();

    Basamak(const int &, Basamak *);

    ~Basamak();
};
#endif