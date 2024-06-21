/**
* @file SayilarListesi.cpp
* @description SayilarListesi Sinifi Fonksiyonlarinin Gövdesi
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#include "SayilarListesi.hpp"
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

Dugum *SayilarListesi::FindPrevByPosition(int position)
{
    Dugum *d = ilk;
    if (position < 0 || position > count())
    {
        throw "index out of range  (dugum)";
    }
    int index = 1;
    for (Dugum *itr = ilk; itr != NULL; itr = itr->d_sonraki, index++)
    {
        if (position == index)
        {
            return itr;
        }
    }
    return NULL;
}

SayilarListesi::SayilarListesi()
{
    ilk = NULL;
    uzunluk = 0;
}

void SayilarListesi::yazdir()
{
    int sayac = 0;
    if (bosmu())
        cout << "Liste bos" << endl;
    else
    {
        for (Dugum *d_itr = ilk; d_itr != NULL; d_itr = d_itr->d_sonraki)
        {

            cout << "###########" << setw(13);
            for (Basamak *b_itr = d_itr->sayi_p->ilk; b_itr != NULL; b_itr = b_itr->sonraki)
            {
                cout << "******* ";
            }
            cout << endl;
            cout << "#" << d_itr->sayi_p << " #" << setw(8);
            for (Basamak *b_itr = d_itr->sayi_p->ilk; b_itr != NULL; b_itr = b_itr->sonraki)
            {

                string adres = to_string(reinterpret_cast<uintptr_t>(b_itr));
                string son_uc_karakter = adres.substr(adres.length() - 3, 3);
                cout << " *  " << son_uc_karakter << "*";
                sayac++;
            }
            cout << endl;
            cout << "#---------#" << setw(13);
            for (Basamak *b_itr = d_itr->sayi_p->ilk; b_itr != NULL; b_itr = b_itr->sonraki)
            {
                cout << "******* ";
            }
            string bosluk(9 - d_itr->sayi_p->basamaksayisibul(d_itr->sayi_p->sayi), ' ');
            cout << endl
                 << "#" << bosluk << d_itr->sayi_p->sayi << "#" << setw(9);
            for (Basamak *b_itr = d_itr->sayi_p->ilk; b_itr != NULL; b_itr = b_itr->sonraki)
            {
                cout << "*   " << b_itr->basamak << " * ";
            }
            cout << endl
                 << "###########" << setw(13);
            for (Basamak *b_itr = d_itr->sayi_p->ilk; b_itr != NULL; b_itr = b_itr->sonraki)
            {
                cout << "******* ";
            }
            cout << endl;
        }
    }
}

int SayilarListesi::count() const
{
    return uzunluk;
}

bool SayilarListesi::bosmu() const
{
    return uzunluk == 0;
}

const Dugum *SayilarListesi::ilk_dugum()
{
    if (bosmu())
        throw "Empty List";
    return ilk;
}

const Dugum *SayilarListesi::son_dugum()
{
    if (bosmu())
        throw "Empty List";
    return FindPrevByPosition(uzunluk);
}
void SayilarListesi::SayiEkle(int index, int sayi)
{
    Sayi *yeni_sayi_p = new Sayi(sayi);

    if (index == 0)
    {

        ilk = new Dugum(yeni_sayi_p, NULL);
        yeni_sayi_p->BasamakEkle(sayi);
    }
    else
    {
        Dugum *indexten_onceki_dugum = FindPrevByPosition(index);
        indexten_onceki_dugum->d_sonraki = new Dugum(yeni_sayi_p, indexten_onceki_dugum->d_sonraki);
        yeni_sayi_p->BasamakEkle(sayi);
    }
    uzunluk++;
}

void SayilarListesi::sona_sayi_ekle(int sayi)
{
    SayiEkle(uzunluk, sayi);
}

void SayilarListesi::b_tersle()
{

    for (Dugum *d_itr = ilk; d_itr != NULL; d_itr = d_itr->d_sonraki)
    {
        Basamak *prev = nullptr;
        Basamak *current = d_itr->sayi_p->ilk;
        Basamak *next = nullptr;
        while (current != nullptr)
        {
            next = current->sonraki;
            current->sonraki = prev;
            prev = current;
            current = next;
        }
        d_itr->sayi_p->ilk = prev;
    }
}

void SayilarListesi::tekleri_basa_al()
{

    for (Dugum *d_itr = ilk; d_itr != NULL; d_itr = d_itr->d_sonraki)
    {
        Basamak *onceki = d_itr->sayi_p->ilk;
        Basamak *b = d_itr->sayi_p->ilk->sonraki;

        if (d_itr->sayi_p->ilk->basamak % 2 == 0)
        {
            while (b != nullptr)
            {
                if (b->basamak % 2 == 1)
                {
                    onceki->sonraki = b->sonraki;
                    b->sonraki = d_itr->sayi_p->ilk;
                    d_itr->sayi_p->ilk = b;
                    break;
                }
                onceki = onceki->sonraki;
                b = b->sonraki;
            }
        }
        Basamak *a = d_itr->sayi_p->ilk;
        onceki = d_itr->sayi_p->ilk;
        b = d_itr->sayi_p->ilk->sonraki;

        while (b != nullptr)
        {
            if ((b->basamak % 2 == 1) && (onceki->basamak % 2 == 0))
            {

                onceki->sonraki = b->sonraki;
                b->sonraki = a->sonraki;
                a->sonraki = b;
                b = onceki->sonraki;
                a = a->sonraki;
                continue;
            }

            else if ((b->basamak % 2 == 1) && (onceki->basamak % 2 == 1))
            {
                a = a->sonraki;
                onceki = onceki->sonraki;
                b = b->sonraki;
            }

            else
            {
                onceki = onceki->sonraki;
                b = b->sonraki;
            }
        }
    }
}

void SayilarListesi::SayiSil(int index)
{
    int sayi;
    if (uzunluk == 0)
        throw "Liste boş";
    Dugum *d;
    if (index == 0)
    {
        d = ilk;
        sayi = d->sayi_p->sayi;
        delete d->sayi_p;
        ilk = ilk->d_sonraki;
    }
    else
    {

        Dugum *onceki_dugum = FindPrevByPosition(index);
        d = onceki_dugum->d_sonraki;
        sayi = d->sayi_p->sayi;
        delete d->sayi_p;
        onceki_dugum->d_sonraki = onceki_dugum->d_sonraki->d_sonraki;
    }

    delete d;
    uzunluk--;
    cout << sayi << " Sayisi Silindi" << endl
         << endl;
}

void SayilarListesi::temizle()
{
    while (!bosmu())
    {
        SayiSil(0);
    }
}

void SayilarListesi::Dosya_Oku_Ekle(string dosya_adi)
{
    ifstream dosya(dosya_adi);
    if (dosya.is_open())
    {
        int sayi;
        while (dosya >> sayi)
        {
            sona_sayi_ekle(sayi);
        }
        dosya.close();
    }
    else
    {
        cout << "Dosya Acilamadi" << endl;
    }
}

void SayilarListesi::En_Buyuk_Sayi_Sil()
{
    int en_buyuk = 0;
    for (Dugum *d_itr = ilk; d_itr != NULL; d_itr = d_itr->d_sonraki)
    {
        if (d_itr->sayi_p->sayi >= en_buyuk)
        {
            en_buyuk = d_itr->sayi_p->sayi;
        }
    }
    SayiSil(indexof(en_buyuk));
}

int SayilarListesi::indexof(const int &s)
{
    int index = 0;
    for (Dugum *d_itr = ilk; d_itr != NULL; d_itr = d_itr->d_sonraki)
    {
        if (d_itr->sayi_p->sayi == s)
        {
            return index;
        }
        index++;
    }
    throw "Sayi bulunamadi";
}

SayilarListesi::~SayilarListesi()
{
    temizle();
    // cout << "Sayilar Listesi Sinifi Silindi" << endl;
}