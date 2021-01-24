#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
概念：
	1.空的二叉树（就结构体指针，指向NULL） tree=NULL
	2.只有根结点的二叉树   （用一个指针指向这个结构体变量）
	3.只有左子树或者右子树的二叉树
		左子树（在左）
		右子树（在右）
	4.左右子树都存在
		1.完全二叉树（从1开始编序号）  
			1.孩子结点	2.父结点	3.姐妹结点 
		2.满二叉树
二叉树的遍历：（不重复打印）
	从左往右（看根结点在哪里） 最前前序（先序）  中间是中序  后面是后序

*/
typedef struct treeNode
{
	char data;
	struct treeNode* LChild;
	struct treeNode* RChild;
}TREE;/* (win  LP代表指针别名)*/
TREE* creataNode(char data)
{
	TREE* newTree = (TREE*)malloc(sizeof(TREE));
	assert(newTree != NULL);
	newTree->data = data;
	newTree->LChild = NULL;
	newTree->RChild = NULL;
	return newTree;
}
void insertTree(TREE* tree, TREE* left, TREE* right)
{
	tree->LChild = left;
	tree->RChild = right;
}
void print(TREE*tree)
{
	printf("%c ", tree->data);
}
//递归
//先序
void recursion_First(TREE*tree)
{
	if (tree != NULL)
	{
		print(tree);
		recursion_First(tree->LChild);
		recursion_First(tree->RChild);
	}
}
void routine_First(TREE*tree)
{
	TREE* stack[10] ;
	int stackTop = -1;
	TREE* pMove = tree;
	while (stackTop!=-1||pMove)
	{
		
		while (pMove)
		{
			printf("%c ", pMove->data);
			stack[++stackTop] = pMove;
			pMove = pMove->LChild;
		}
		if (stackTop != -1)
		{
			pMove = stack[stackTop];//把保存的上个数据
			stackTop--;
			pMove = pMove->RChild;
		}
	}
}
//中序
void recursion_MId(TREE*tree)
{
	if (tree != NULL)
	{
		recursion_MId(tree->LChild);
		print(tree);
		recursion_MId(tree->RChild);
	}
}
void routine_Mid(TREE* tree)
{
	TREE* stack[10];
	int stackTop = -1;
	TREE* pMove = tree;
	while (stackTop != -1 || pMove)
	{
		while (pMove)
		{
			stack[++stackTop] = pMove;
			pMove = pMove->LChild;
			
		}
		if (stackTop != -1)
		{
			pMove=stack[stackTop--];
			print(pMove);
			pMove = pMove->RChild;
		}
	}
}
//后序
void recursion_Last(TREE*tree)
{
	if (tree != NULL)
	{
		recursion_Last(tree->LChild);
		recursion_Last(tree->RChild);
		print(tree);
	}
}
//非递归
void routine_Last(TREE* tree)
{
	assert(tree != NULL); 
	TREE* stack[10];
	int stackTop = -1;
	TREE* pMove = tree;
	TREE* pLastVisit = NULL;

	while (pMove)
	{
		stack[++stackTop] = pMove;
		pMove = pMove->LChild;
	}
	while (stackTop!=-1)
	{
		pMove = stack[stackTop--];
		//当前结点是否被访问
		if (pMove->LChild == NULL || pMove->RChild == pLastVisit)
		{
			//如果被访问就打印，当前结点
			print(pMove);
			//改变标记位置
			pLastVisit = pMove;
		}
		else
		{
			//右边没有被访问
			stack[++stackTop] = pMove;
			pMove = pMove->RChild;
			while (pMove)
			{
				stack[++stackTop] = pMove;
				pMove = pMove->LChild;
			}
		}
	}

}
int main()
{
	TREE* A = creataNode('A');
	TREE* C = creataNode('C');
	TREE* B = creataNode('B');
	TREE* D = creataNode('D');
	TREE* E = creataNode('E');
	TREE* F = creataNode('F');
	TREE* G = creataNode('G');
	insertTree(A, B, C);
	insertTree(B, D, E);
	insertTree(C, F, G);
	printf("\n先序排列\n");
	recursion_First(A);
	putchar('\n');
	routine_First(A);
	printf("\n中序排列\n");
	recursion_MId(A);
	putchar('\n');
	routine_Mid(A);
	printf("\n后序排列\n");
	recursion_Last(A);
	putchar('\n');
	routine_Last(A);
	while (1);
	return 0;
}