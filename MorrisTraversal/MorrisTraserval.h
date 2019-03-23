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
void MorrisTraserval_inOrder(BinaryTreeNode<T>*p);

template<typename T>
void MorrisTraserval_postOrder(BinaryTreeNode<T>*p);