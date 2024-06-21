/** 
* @file Stack.hpp
* @description Stack sinifi tanimi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef Stack_hpp
#define Stack_hpp
class Stack
{
private:
	int *items;
	int capacity;
	void reserve(int);
public:
	int topOfStack;
	int counter;
	Stack();
	bool IsEmpty();
	void clear();
	void push(int);
	const int &top();
	void pop();
	~Stack();
};
#endif