#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//每一结点的数据
typedef struct _Data
{
	int first;
	char str[20];
}Data;
//二叉树结点
typedef struct _TreeNode
{
	Data data;
	struct _TreeNode*LChild;
	struct _TreeNode*RChild;

}Node;
//封装一个二叉搜索树
typedef struct _SeekTree
{
	Node* root;
	int treeSize;
}SeekTree;
//创建结点
Node* createNode(Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}
//创建搜索树
SeekTree* createSeekTree()
{
	SeekTree* newTree = (SeekTree*)malloc(sizeof(SeekTree));
	assert(newTree != NULL);
	newTree->root = NULL;
	newTree->treeSize = 0;
	return newTree;
}
//打印
void print(Node* tree)
{
	printf("%d\t%s\n", tree->data.first,tree->data .str);
}
//递归遍历
void CurTree(Node* tree)
{
	if (tree != NULL)
	{
		CurTree(tree->LChild);
		print(tree);
		CurTree(tree->RChild);
	}
}
//插入
void insert(SeekTree* tree, Data data)
{
	Node* newNode = createNode(data);
	//找合适位置
	Node* pMove = tree->root;
	Node* pMoveParent = NULL;//记录
	while (pMove != NULL)
	{
		pMoveParent = pMove;//记录移动结点的父节点
		if (data.first < pMove->data.first)
		{
			pMove = pMove->LChild;
		}
		else if (data.first < pMove->data.first)
		{
			pMove = pMove->RChild;
		}
		else//相同的处理在于你 的选择方式
		{
			//修改相同关键字的结点中的数据
			strcmp(pMove->data.str, data.str);
			return;
		}
	}
	//退出循环
	if (tree->root == NULL)
	{
		tree->root = newNode;
	}
	else
	{
		//pmoveParent
		if (pMoveParent->data.first > data.first)
		{
			pMoveParent->LChild = newNode;
		}
		else
		{
			pMoveParent->RChild = newNode;
		}
	}
	tree->treeSize++;
}
//查找
Node* search(SeekTree* tree, int first)
{
	Node* pMove = tree->root;
	if (pMove == NULL)
	{
		return pMove;
	}
	else
	{
		while (pMove->data.first != first)
		{
			if (pMove->data.first > first)
			{
				pMove = pMove->LChild;
			}
			else
			{
				pMove = pMove->RChild;
			}
			if (pMove == NULL)
			{
				return pMove;
			}
			return pMove;
		}
	}
}
//二叉树的删除
void erase(SeekTree* tree, int first)
{
	Node*pMove = tree->root;
	Node*pMoveParent = NULL;
	while (pMove != NULL&&pMove->data.first != first)
	{
		pMoveParent = pMove;
		if (first < pMove->data.first)
		{
			pMove = pMove->LChild;
		}
		else if (first>pMove->data.first)
		{
			pMove = pMove->RChild;
		}
		else
		{
			break;
		}
		if (pMove->LChild != NULL&&pMove->RChild != NULL)
		{
			Node* moveNode = pMove->LChild;
			Node* moveNodeParent = pMove;
			while (moveNode->RChild != NULL)
			{
				moveNodeParent = moveNode;
				moveNode = moveNode->RChild;
			}
			Node* newNode = createNode(moveNode->data);
			newNode->LChild = pMove->LChild;
			newNode->RChild = pMove->RChild;
			//分类讨论
			if (pMoveParent == NULL)
			{
				tree->root = newNode;
			}
			else if (pMove == pMoveParent->LChild)
			{
				pMoveParent->LChild = newNode;
			}
			else
			{
				pMoveParent->RChild = newNode;
			}
			//调整二叉树
			//调整删除的指针
			if (moveNodeParent == pMove)
			{
				pMoveParent = newNode;
			}
			else
			{
				pMoveParent = moveNodeParent;
			}
			free(pMove);
			pMove = moveNode;
		}
		Node* sNode = NULL;
		//如果删除的结点左右存在结点，保存删除结点的下一个结点
		if (pMove->LChild!= NULL)
		{
			sNode = pMove->LChild;
		}
		else
		{
			sNode = pMove->RChild;
		}
		if (tree->root == pMove)
		{
			tree->root = sNode;
		}
		else
		{
			if (pMove == pMoveParent->LChild)
			{
				pMoveParent->LChild = sNode;
			}
			else
			{
				pMoveParent->RChild = sNode;
			}
		}
		free(pMove);
		tree->treeSize--;
	}
}
int main()
{

	SeekTree* tree = createSeekTree();
	Data A[5] = { 23, "wda", 12, "dasd", 56, "fger", 23, "fwerd" ,43 ,"dahgdy"};
	for (int i = 0; i < 5; i++)
	{
		insert(tree,A[i]);
	}
	printf("中序遍历\n");
	CurTree(tree->root);
	while (1);
	return 0;
}
