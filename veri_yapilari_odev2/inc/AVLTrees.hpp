/** 
* @file AVLTrees.hpp
* @description AVL_Trees sinifi tanimi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef AVLTrees_hpp
#define AVLTrees_hpp
#include "AVLTree.hpp"
#include <string>
using namespace std;

class AVL_Trees
{
private:
	int length;
	int capacity;
	void reserve(int);

public:
	AVL **items;
	AVL_Trees();
	int FindAVLNumber(const string &);
	void ReadAVLAndAdd(const string &);
	void comparetoStacks(int);
	void restartStacks(int);
	void printASCII(int);
	void printTable(int);
	~AVL_Trees();
};
#endif
