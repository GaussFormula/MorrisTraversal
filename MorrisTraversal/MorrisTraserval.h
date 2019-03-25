#pragma once
#include "BinaryTreeNode.h"
#include <iostream>
enum Order
{
	preOrder,inOrder,postOrder
};

template<typename T>
void MorrisTraserval(BinaryTreeNode<T>*p, Order);

template<typename T>
void MorrisTraserval_preOrder(BinaryTreeNode<T>*p);

template<typename T>
void MorrisTraserval_inOrder(BinaryTreeNode<T>*p);//ÖÐÐò±éÀú

template<typename T>
void MorrisTraserval_postOrder(BinaryTreeNode<T>*p);

template<typename T>
void printReverse(BinaryTreeNode<T>*from, BinaryTreeNode<T>*to);

template<typename T>
void reverse(BinaryTreeNode<T>*from, BinaryTreeNode<T>*to);