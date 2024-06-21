/** 
* @file AVLTree.cpp
* @description AVL sinifi gövdesi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/
#include "AVLTreeNode.hpp"
#include "AVLTree.hpp"
#include "Stack.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

Node *AVL::SearchAndAdd(Node *subNode, const int &item)
{
	if (subNode == nullptr)
	{
		subNode = new Node(item);
	}
	else if (item < subNode->data)
	{
		subNode->left = SearchAndAdd(subNode->left, item);

		if (Height(subNode->left) == Height(subNode->right) + 2)
		{
			if (item < subNode->left->data)
				subNode = SwapWithLeftChild(subNode);
			else
			{
				subNode->left = SwapWithRightChild(subNode->left);
				subNode = SwapWithLeftChild(subNode);
			}
		}
	}
	else if (item > subNode->data)
	{
		subNode->right = SearchAndAdd(subNode->right, item);

		if (Height(subNode->right) == Height(subNode->left) + 2)
		{
			if (item > subNode->right->data)
				subNode = SwapWithRightChild(subNode);
			else
			{
				subNode->right = SwapWithLeftChild(subNode->right);
				subNode = SwapWithRightChild(subNode);
			}
		}
	}
	subNode->height = Height(subNode);
	return subNode;
}
Node *AVL::SwapWithLeftChild(Node *subNode)
{
	Node *tmp = subNode->left;
	subNode->left = tmp->right;
	tmp->right = subNode;

	subNode->height = Height(subNode);
	tmp->height = 1 + max(Height(tmp->left), subNode->height);

	return tmp;
}
Node *AVL::SwapWithRightChild(Node *subNode)
{
	Node *tmp = subNode->right;
	subNode->right = tmp->left;
	tmp->left = subNode;

	subNode->height = Height(subNode);
	tmp->height = 1 + max(Height(tmp->right), subNode->height);

	return tmp;
}
bool AVL::DeleteNode(Node *&subNode)
{
	Node *delNode = subNode;

	if (subNode->right == nullptr)
		subNode = subNode->left;
	else if (subNode->left == nullptr)
		subNode = subNode->right;
	else
	{
		delNode = subNode->left;
		Node *parentNode = subNode;
		while (delNode->right != nullptr)
		{
			parentNode = delNode;
			delNode = delNode->right;
		}
		subNode->data = delNode->data;
		if (parentNode == subNode)
			subNode->left = delNode->left;
		else
			parentNode->right = delNode->left;
	}

	delete delNode;
	return true;
}
void AVL::inorder(Node *subNode)
{
	if (subNode != nullptr)
	{
		inorder(subNode->left);
		cout << subNode->data << " ";
		inorder(subNode->right);
	}
}
void AVL::preorder(Node *subNode)
{
	if (subNode != nullptr)
	{
		cout << subNode->data << " ";
		preorder(subNode->left);
		preorder(subNode->right);
	}
}
void AVL::postorder(Node *subNode)
{
	if (subNode != nullptr)
	{
		postorder(subNode->left);
		postorder(subNode->right);
		cout << subNode->data << " ";
	}
}

void AVL::AddLeaves()
{
	addleaves(root);
}

void AVL::addleaves(Node *subNode)
{
	int number = 0;
	if (subNode != nullptr)
	{
		addleaves(subNode->left);
		addleaves(subNode->right);
		if (subNode->left == nullptr && subNode->right == nullptr)
		{
			stack->push(subNode->data);
			number++;
		}
		else
		{
			AVLToplamDugumDeger = AVLToplamDugumDeger + subNode->data;
		}
	}
	ascii = AVLToplamDugumDeger % (90 - 65 + 1) + 65;
	LeafNumber = number;
}

void AVL::PrintStack()
{
	while (!stack->IsEmpty())
	{
		cout << stack->top() << endl;
		stack->pop();
	}
}

int AVL::Height(Node *subNode)
{
	if (subNode == nullptr)
		return -1;
	return 1 + max(Height(subNode->left), Height(subNode->right));
}
void AVL::PrintLevel(Node *subNode, int level)
{
	if (subNode == nullptr)
		return;
	if (level == 0)
		cout << subNode->data << " ";
	else
	{
		PrintLevel(subNode->left, level - 1);
		PrintLevel(subNode->right, level - 1);
	}
}
bool AVL::Search(Node *subNode, const int &item)
{
	if (subNode == nullptr)
		return false;
	if (subNode->data == item)
		return true;
	if (item < subNode->data)
		return Search(subNode->left, item);
	else
		return Search(subNode->right, item);
}

AVL::AVL(int number)
{
	root = nullptr;
	AVLNumber = number;
	AVLToplamDugumDeger = 0;
	ascii = 0;
}
bool AVL::isEmpty() const
{
	return root == nullptr;
}
void AVL::Add(const int &item)
{
	root = SearchAndAdd(root, item);
}
void AVL::inorder()
{
	inorder(root);
}
void AVL::preorder()
{
	preorder(root);
}
void AVL::postorder()
{
	postorder(root);
}
void AVL::levelorder()
{
	int h = Height();
	for (int level = 0; level <= h; level++)
	{
		PrintLevel(root, level);
	}
}
int AVL::Height()
{
	return Height(root);
}
bool AVL::Search(const int &item)
{
	return Search(root, item);
}
void AVL::Clear()
{
	while (!isEmpty())
		DeleteNode(root);
}
AVL::~AVL()
{

	Clear();
	delete stack;
}
