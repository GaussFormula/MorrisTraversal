#pragma once

template<typename T>
class BinaryTreeNode
{
private:
	T m_data;
	BinaryTreeNode<T>* LeftChild;
	BinaryTreeNode<T>* RightChild;
public:
	BinaryTreeNode() = default;
	BinaryTreeNode(T t):m_data(T),LeftChild(nullptr),RightChild(nullptr){}
	BinaryTreeNode(const BinaryTreeNode&);//������ʹ�� ���ܴ����ڴ�й©
	BinaryTreeNode<T>& operator=(const BinaryTreeNode<T>&);//������ʹ�� ���ܴ����ڴ�й©
	T& getData();
	BinaryTreeNode<T>* getLeftChild();
	BinaryTreeNode<T>* getRightChild();
	void setData(const T&t);
	void setLeftChild(BinaryTreeNode<T>*p);
	void setRightChild(BinaryTreeNode<T>*p);
};