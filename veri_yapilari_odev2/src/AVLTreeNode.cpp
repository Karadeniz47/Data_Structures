/** 
* @file AVLTreeNode.cpp
* @description Node sinifi gövdesi.
* @course 1.ogretim A grubu
* @assignment 2
* @date 22.12.2023
* @author İsmail Alper Karadeniz ismailalperkaradeniz@gmail.com
*/
#include "AVLTreeNode.hpp"
Node::Node(const int &vr, Node *sl, Node *sg)
{
    data = vr;
    left = sl;
    right = sg;
    height = 0;
}

Node::Node(const int &vr)
{
    data = vr;
    left = nullptr;
    right = nullptr;
    height = 0;
}