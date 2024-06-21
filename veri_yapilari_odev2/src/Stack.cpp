/** 
* @file Stack.cpp
* @description Stack sinifi gövdesi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#include "Stack.hpp"
#include <iostream>
using namespace std;
int *items;
int topOfStack;
int capacity;

void Stack::reserve(int newcapacity)
{
	int *tmp = new int[newcapacity];
	for (int i = 0; i < capacity; i++)
	{
		tmp[i] = items[i];
	}
	delete[] items;
	items = tmp;
	capacity = newcapacity;
}

Stack::Stack()
{
	capacity = 500;
	topOfStack = -1;
	counter = 0;
	items = new int[capacity];
}

bool Stack::IsEmpty()
{
	return topOfStack == -1;
}

void Stack::clear()
{
	topOfStack = -1;
}

void Stack::push(int data)
{
	if (topOfStack + 1 == capacity)
	{
		reserve(3 * capacity);
	}
	topOfStack++;
	items[topOfStack] = data;
}
const int &Stack ::top()
{
	if (IsEmpty())
		throw "no data";
	return items[topOfStack];
}

void Stack::pop()
{
	if (IsEmpty())
		throw "no data";
	topOfStack--;
}
Stack::~Stack()
{

	delete[] items;
}
