#include "BinaryTreeNode.h"

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode &other)
{
	if (this == &other)
	{
		return *this;
	}
	m_data = other.m_data;
	LeftChild = other.LeftChild;
	RightChild = other.RightChild;
}

template<typename T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T>&other)
{
	if (this == &other)
	{
		return *this;
	}
	m_data = other.m_data;
	LeftChild = other.LeftChild;
	RightChild = other.RightChild;
	return *this;
}

template<typename T>
T& BinaryTreeNode<T>::getData()
{
	return this->m_data;
}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild()
{
	return this->LeftChild;
}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild()
{
	return this->RightChild;
}

template<typename T>
void BinaryTreeNode<T>::setData(const T&t)
{
	this->m_data = t;
}

template<typename T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>*p)
{
	this->LeftChild = p;
}

template<typename T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>*p)
{
	this->RightChild = p;
}