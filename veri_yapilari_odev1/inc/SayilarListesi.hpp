/**
* @file SayilarListesi.hpp
* @description SayilarListesi Sinifi Tanimi
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include "Dugum.hpp"
#include <string>
using namespace std;

class SayilarListesi
{
public:
    Dugum *ilk;
    int uzunluk;
    Dugum *FindPrevByPosition(int);

    SayilarListesi();

    void yazdir();

    int count() const;

    bool bosmu() const;

    const Dugum *ilk_dugum();

    const Dugum *son_dugum();

    void SayiEkle(int, int);

    void sona_sayi_ekle(int);

    void b_tersle();

    void En_Buyuk_Sayi_Sil();

    int indexof(const int &);

    void tekleri_basa_al();

    void ilki_tek_yap();

    void SayiSil(int);

    void temizle();

    void Dosya_Oku_Ekle(string);

    ~SayilarListesi();
};
#endif