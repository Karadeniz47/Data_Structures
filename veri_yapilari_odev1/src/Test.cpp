/**
* @file Test.cpp
* @description Test Dosyası
* @course 1.Öğretim A grubu
* @assignment 1
* @date 25.10.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#include <iostream>
#include <exception>
#include <string>
#include "Dugum.hpp"
#include "Basamak.hpp"
#include "Sayi.hpp"
#include "SayilarListesi.hpp"

using namespace std;
int main()
{
    setlocale(LC_ALL, "Turkish");
    int a;
    SayilarListesi s;
    s.Dosya_Oku_Ekle("Sayilar.txt");

    s.yazdir();
    do
    {

        cout << endl;
        cout << "1. Tek Basamaklari Basa Al" << endl;
        cout << "2. Basamaklari Tersle" << endl;
        cout << "3. En Buyuk Cikar " << endl;
        cout << "4. Cikis" << endl;
        cout << "Secim : ";
        cin >> a;

        if (a == 1)
        {
            system("cls");
            s.yazdir();
            cout << endl
                 << endl;

            s.tekleri_basa_al();

            s.yazdir();
            cout << endl;
        }
        else if (a == 2)
        {
            system("cls");
            s.yazdir();
            cout << endl
                 << endl;

            s.b_tersle();

            s.yazdir();

            cout << endl;
        }
        else if (a == 3)
        {
            system("cls");
            s.yazdir();
            cout << endl
                 << endl;
            try
            {
               s.En_Buyuk_Sayi_Sil();
            }
            catch(const char*c)
            {
                cout << c <<endl;
            }
            
            

            s.yazdir();

            cout << endl;
        }

    } while (a != 4);
}