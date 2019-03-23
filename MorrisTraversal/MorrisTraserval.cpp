#include "MorrisTraserval.h"

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
void MorrisTraserval_preOrder(BinaryTreeNode<T>*p)
{
	;
}