/** 
* @file AVLTreeNode.hpp
* @description Node sinifi tanimi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef AVLTreeNode_hpp
#define AVLTreeNode_hpp
struct Node
{
	int data;
	Node *left;
	Node *right;
	int height;
	Node(const int &, Node *, Node *);
	Node(const int &);
};
#endif