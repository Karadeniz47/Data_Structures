/** 
* @file AVLTrees.cpp
* @description AVL_Trees sinifi gövdesi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/
#include "AVLTrees.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void AVL_Trees::ReadAVLAndAdd(const string &filename)
{
	int AVLNumber = FindAVLNumber(filename);
	while (capacity < AVLNumber)
	{
		reserve(capacity * 3);
	}
	string line = "";
	int c = 0;
	int c1 = 1;
	ifstream f(filename);

	if (f.is_open())
	{
		while (getline(f, line))
		{
			items[c] = new AVL(c1);
			istringstream ss(line);
			int value;
			while (ss >> value)
			{

				items[c]->Add(value);
			}
			items[c]->stack = new Stack;
			items[c]->AddLeaves();

			c++;
			c1++;
			length++;
		}
		if(length == 0)
		{
			throw "Dosya bos";
		}

		comparetoStacks(AVLNumber);

		f.close();
	}
	else
	{
		cout << "file could not be opened" << endl;
		return;
	}
}
void AVL_Trees::comparetoStacks(int number)
{

	int a = number;
	printASCII(a);

	while (number > 1)
	{

		int minIndex = -1;
		int minValue = 10000;
		int maxIndex = -1;
		int maxValue = 0;
		for (int i = 0; i < a; i++)
		{
			if (items[i] != nullptr && items[i]->stack != nullptr)
			{
				if (items[i]->stack->top() < minValue)
				{
					minValue = items[i]->stack->top();
					minIndex = i;
				}
			}
		}
		items[minIndex]->stack->pop();
		items[minIndex]->stack->counter++;
		if (items[minIndex]->stack->IsEmpty())
		{
			if (items[minIndex] != nullptr)
			{
				delete items[minIndex];
				items[minIndex] = nullptr;
				number--;

				restartStacks(a);
				system("CLS");
				printASCII(a);
				continue;
			}
		}

		for (int i = 0; i < a; i++)
		{
			if (items[i] != nullptr && items[i]->stack != nullptr)
			{
				if (items[i]->stack->top() > maxValue)
				{
					maxValue = items[i]->stack->top();
					maxIndex = i;
				}
			}
		}
		items[maxIndex]->stack->pop();
		items[maxIndex]->stack->counter++; // counter kac eleman cikarildigini tutar
		if (items[maxIndex]->stack->IsEmpty())
		{
			if (items[maxIndex] != nullptr)
			{
				delete items[maxIndex];
				items[maxIndex] = nullptr;
				number--;

				restartStacks(a);
				system("CLS");
				printASCII(a);
			}
		}
	}
	system("CLS");
	printTable(a);
}

void AVL_Trees::restartStacks(int avlnumber) // baslangictaki avl agacı sayısı = avlnumber
{
	for (int i = 0; i < avlnumber; i++)
	{
		if ((items[i] != nullptr) && (items[i]->stack != nullptr))
		{
			items[i]->stack->topOfStack = items[i]->stack->topOfStack + items[i]->stack->counter;
			items[i]->stack->counter = 0;
		}
	}
}

int AVL_Trees::FindAVLNumber(const string &filename)
{
	ifstream f(filename);
	if (f.is_open())
	{
		string line = "";
		int counter = 0;
		while (getline(f, line))
		{
			counter++;
		}

		return counter;
	}
	else
	{
		throw "file can not be opened";
	}
}

void AVL_Trees::printASCII(int AVLNumber)
{
	for (int i = 0; i < AVLNumber; i++)
	{
		if (items[i] != nullptr)
			cout << items[i]->ascii;
	}
}

void AVL_Trees::printTable(int AVLNumber)
{
	int index = -1;
	for (int i = 0; i < AVLNumber; i++)
	{
		if (items[i] != nullptr)
		{
			index = items[i]->AVLNumber - 1;
		}
	}

	for (int i = 0; i < 30; i++)
	{
		cout << "=";
	}
	cout << endl
		 << "|" << setw(29) << "|";
	cout << endl
		 << "|" << setw(29) << "|";
	cout << endl
		 << "|" << setw(19) << "Son Karakter: " << items[index]->ascii << setw(9) << "|";
	cout << endl
		 << "|" << setw(11) << "AVL No"
		 << "      : " << items[index]->AVLNumber << setw(7) << "|";
	cout << endl
		 << "|" << setw(29) << "|";
	cout << endl
		 << "|" << setw(29) << "|" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "=";
	}
}

void AVL_Trees::reserve(int newCapacity)
{
	if (capacity >= newCapacity)
		return;
	AVL **tmp = new AVL *[newCapacity];
	for (int j = 0; j < length; j++)
		tmp[j] = items[j];
	if (items != nullptr)
		delete[] items;
	items = tmp;
	capacity = newCapacity;
}

AVL_Trees::AVL_Trees()
{
	length = 0;
	capacity = 500;
	items = new AVL *[capacity];
}

AVL_Trees::~AVL_Trees() //!!
{
	for (int i = 0; i < length; i++)
	{
		if (items[i] != nullptr)
		{
			delete items[i];
			items[i] = nullptr;
		}
	}
	delete[] items;
}
