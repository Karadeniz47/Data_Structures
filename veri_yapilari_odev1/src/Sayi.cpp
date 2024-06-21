/**
* @file Sayi.cpp
* @description Sayi Sinifi Fonksiyonlarinin Gövdesi
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#include "Sayi.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Sayi::Sayi()
{
    ilk = NULL;
    uzunluk = 0;
}

Sayi::Sayi(int sayi)
{
    this->sayi = sayi;
}

int Sayi::basamaksayisibul(int sayi)
{
    string str = to_string(sayi);
    stringstream ss(str);
    char basamak;
    int sayac = 0;
    while (ss >> basamak)
    {
        sayac++;
    }
    return sayac;
}

int *Sayi::basamaklari_ayir(int sayi)
{
    int basamak_sayisi = basamaksayisibul(sayi);
    p = new int[basamak_sayisi];
    string str = to_string(sayi);
    stringstream ss(str);
    char c_basamak;
    int i_basamak;
    int i = 0;
    while (ss >> c_basamak)
    {
        i_basamak = c_basamak - '0';
        p[i] = i_basamak;
        i = i + 1;
    }
    return p;
}

Basamak *Sayi::FindPrevByPosition(int position)
{
    
    if ((position < 0) || (position > uzunluk))
    {
        throw "index out of range (basamak)";
    }
    int index = 1;
    for (Basamak *b_itr = ilk; b_itr != nullptr; b_itr = b_itr->sonraki, index++)
    {
        if (position == index)
        {
            return b_itr;
        }
    }
    return NULL;
}

int Sayi::hesapla() const
{
    return uzunluk;
}

void Sayi::BasamakEkle(int sayi)
{
    int *basamaklar = basamaklari_ayir(sayi);
    int basamak_sayisi = basamaksayisibul(sayi);

    for (int i = 0; i < basamak_sayisi; i++)
    {
        if (i == 0)
        {
            ilk = new Basamak(basamaklar[i], NULL);
        }
        else
        {
            Basamak *indexten_onceki_basamak = FindPrevByPosition(i);
            indexten_onceki_basamak->sonraki = new Basamak(basamaklar[i], indexten_onceki_basamak->sonraki);
        }
        uzunluk++;
    }
}

int Sayi::indexof(const int &b)
{

    int index = 0;
    for (Basamak *itr = ilk; itr != NULL; itr = itr->sonraki, index++)
    {
        if (itr->basamak == b)
            return index;
    }
    throw "basamak bulunamadi";
   
}

int Sayi::p_indexof(const Basamak *p)
{
    int index = 0;
    for (Basamak *itr = ilk; itr != NULL; itr = itr->sonraki, index++)
    {
        if (itr == p)
            return index;
    }
    throw "basamak bulunamadi";
    
}

bool Sayi::bosmu()
{
    return uzunluk == 0;
}

void Sayi::BasamakSil(int index)
{
    int basamak;
    if (uzunluk == 0)
    {
        cout << "Liste bos";    // !!
        return;
    }
        
    Basamak *d;
    if (index == 0)
    {
        d = ilk;
        basamak = d->basamak;
        ilk = ilk->sonraki;
    }

    else
    {
        Basamak *indexten_onceki_basamak = FindPrevByPosition(index);
        d = indexten_onceki_basamak->sonraki;
        basamak = d->basamak;
        indexten_onceki_basamak->sonraki = indexten_onceki_basamak->sonraki->sonraki;
    }

    delete d;
    uzunluk--;
    cout << basamak << " Silindi" << endl;
}

void Sayi::clear()
{
    while (!bosmu())
    {
        BasamakSil(0);
    }
}

Sayi::~Sayi()
{
    clear();
    delete[] p;
    cout << "Sayi Sinifi Silindi" << endl;
}