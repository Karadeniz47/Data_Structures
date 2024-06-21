/** 
* @file test.cpp
* @description test dosyasi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Stack.hpp"
#include "AVLTreeNode.hpp"
#include "AVLTree.hpp"
#include "AVLTrees.hpp"
using namespace std;
int main()
{
    AVL_Trees a;
    try
    {
        a.ReadAVLAndAdd("Veri.txt");
    }
    catch (const char *c)
    {
        cout << c << endl;
    }
}