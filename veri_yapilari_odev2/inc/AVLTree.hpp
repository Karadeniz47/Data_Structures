/** 
* @file AVLTree.hpp
* @description AVL sinifi tanimi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/

#ifndef AVLTree_hpp
#define AVLTree_hpp
#include "AVLTreeNode.hpp"
#include "Stack.hpp"
class AVL
{
private:
	Node *SearchAndAdd(Node *, const int &);
	Node *SwapWithLeftChild(Node *);
	Node *SwapWithRightChild(Node *);
	bool DeleteNode(Node *&);
	void inorder(Node *);
	void preorder(Node *);
	void postorder(Node *);
	int Height(Node *subNode);
	void PrintLevel(Node *, int);
	bool Search(Node *, const int &item);
	void addleaves(Node *subNode);

public:
	AVL(int);
	Node *root;
	Stack *stack;
	char ascii;
	int AVLToplamDugumDeger;
	int AVLNumber;
	int LeafNumber;
	void AddLeaves();
	void PrintStack();
	bool isEmpty() const;
	void Add(const int &);
	void inorder();
	void preorder();
	void postorder();
	void levelorder();
	int Height();
	bool Search(const int &);
	void Clear();
	~AVL();
};
#endif