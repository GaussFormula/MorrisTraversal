#include "MorrisTraserval.h"
template<typename T>
void printData(const T&t)
{
	std::cout << t << " ";
}

template<typename T>
void MorrisTraserval(BinaryTreeNode<T>*p, Order)
{
	if (p == NULL)
	{
		std::cerr << "root node is null" << std::endl;
		return;
	}
	if (Order == preOrder)
	{
		MorrisTraserval_preOrder(p);
		return;
	}
	if (Order == inOrder)
	{
		MorrisTraserval_inOrder(p);
		return;
	}
	if (Order == postOrder)
	{
		MorrisTraserval_postOrder(p);
		return;
	}
}

template<typename T>
void MorrisTraserval_inOrder(BinaryTreeNode<T>*p)
{
	BinaryTreeNode<T>*pCurrent = p;
	BinaryTreeNode<T>*pPrev = NULL;
	while (pCurrent!=NULL)
	{
		if (pCurrent->getLeftChild() == NULL)
		{
			pCurrent->displayData(printData(p->m_data));
			pCurrent = pCurrent->getRightChild();
		}
		else
		{
			pPrev = pCurrent->getLeftChild();
			while (pPrev->getRightChild != NULL && pPrev->getRightChild() != pCurrent)
			{
				pPrev = pPrev->getRightChild();
			}
			if (pPrev->getRightChild() == NULL)
			{
				pPrev->setRightChild(pCurrent);
				pCurrent = pCurrent->getLeftChild();
			}
			else
			{
				pPrev->setRightChild(NULL);
				pPrev->displayData(printData(pPrev->getData()));
				pCurrent = pCurrent->getRightChild();
			}
		}
	}
}

template<typename T>
void MorrisTraserval_preOrder(BinaryTreeNode<T>*p)
{
	BinaryTreeNode<T>*pCurrent = p;
	BinaryTreeNode<T>*pPrev = NULL;
	while (pCurrent!=NULL)
	{
		if (pCurrent->getLeftChild() == NULL)
		{
			pCurrent->displayData(printData(p->m_data));
			pCurrent = pCurrent->getRightChild();
		}
		else
		{
			pPrev = pCurrent->getLeftChild();
			//��ǰ���ڵ�
			while (pPrev->getRightChild() != NULL && pPrev->getRightChild() != pCurrent)
			{
				pPrev = pPrev->getRightChild();
			}
			if (pPrev->getRightChild() == NULL)
			{
				pPrev->setRightChild(pCurrent);
				pCurrent->displayData(printData(pCurrent->m_data));
				pCurrent = pCurrent->getLeftChild();
			}
			else
			{
				pPrev->setRightChild(NULL);
				pCurrent = pCurrent->getRightChild();
			}
		}
	}
}

template<typename T>
void MorrisTraserval_postOrder(BinaryTreeNode<T>*p)
{
	BinaryTreeNode<T> dump;
	dump->setLeftChild(p);
	BinaryTreeNode<T>*pCurrent = &dump;
	BinaryTreeNode<T>*pPrev = NULL;
	while (pCurrent!=NULL)
	{
		//����Ϊ�����Һ�����Ϊ��ǰ�ڵ�
		if (pCurrent->getLeftChild() == NULL)
		{
			pCurrent = pCurrent->getRightChild();
		}
		//���Ӳ�Ϊ�գ����ڵ�ǰ�ڵ�����������ҵ����������ǰ���ڵ�
		else
		{
			pPrev = pCurrent->getLeftChild();
			while (pPrev->getRightChild()!=NULL&&pPrev->getRightChild()!=pCurrent)
			{
				pPrev = pPrev->getRightChild();
			}

			//��ǰ���ڵ���Һ���Ϊ�գ����Һ�������Ϊ��ǰ�ڵ�
			//��ǰ�ڵ����Ϊ��������
			if (pPrev->getRightChild() == NULL)
			{
				pPrev->setRightChild(pCurrent);
				pCurrent = pCurrent->getLeftChild();
			}

			//���ǰ���ڵ���Һ���Ϊ��ǰ�ڵ�
			//�������Һ���������Ϊ��
			//��������ӵ�ǰ�ڵ����ӵ���ǰ���ڵ�����·���ϵ����нڵ�
			else
			{
				printReverse(pCurrent->getLeftChile(), pPrev);
				pPrev->setRightChild(NULL);
				pCurrent = pCurrent->getRightChild();
			}
		}
	}
}

template<typename T>
void printReverse(BinaryTreeNode<T>*from, BinaryTreeNode<T>*to)
{
	reverse(from, to);
	BinaryTreeNode<T>*p = to;
	while (true)
	{
		p->displayData(printData(p->getData()));
		if (p == from)
		{
			break;
		}
		p = p->getRightChild();
	}
	reverse(to,from);
}
template<typename T>
void reverse(BinaryTreeNode<T>*from, BinaryTreeNode<T>*to)
{
	if (from == to)
	{
		return;
	}
	BinaryTreeNode<T>*x = from, *y = from->getRightChild(), *z;
	while (true)
	{
		z = y->getRightChild();
		y->setRightChild(x);
		x = y;
		y = z;
		if (x == to)
		{
			break;
		}
	}
}