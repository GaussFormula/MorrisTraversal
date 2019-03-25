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
			//找前驱节点
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
		//左孩子为空则将右孩子作为当前节点
		if (pCurrent->getLeftChild() == NULL)
		{
			pCurrent = pCurrent->getRightChild();
		}
		//左孩子不为空，则在当前节点的左子树中找到中序遍历的前驱节点
		else
		{
			pPrev = pCurrent->getLeftChild();
			while (pPrev->getRightChild()!=NULL&&pPrev->getRightChild()!=pCurrent)
			{
				pPrev = pPrev->getRightChild();
			}

			//若前驱节点的右孩子为空，则将右孩子设置为当前节点
			//当前节点更新为它的左孩子
			if (pPrev->getRightChild() == NULL)
			{
				pPrev->setRightChild(pCurrent);
				pCurrent = pCurrent->getLeftChild();
			}

			//如果前驱节点的右孩子为当前节点
			//将它的右孩子重新设为空
			//倒序输出从当前节点左孩子到该前驱节点这条路径上的所有节点
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