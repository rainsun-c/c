#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
���
	1.�յĶ��������ͽṹ��ָ�룬ָ��NULL�� tree=NULL
	2.ֻ�и����Ķ�����   ����һ��ָ��ָ������ṹ�������
	3.ֻ�������������������Ķ�����
		������������
		�����������ң�
	4.��������������
		1.��ȫ����������1��ʼ����ţ�  
			1.���ӽ��	2.�����	3.���ý�� 
		2.��������
�������ı����������ظ���ӡ��
	�������ң������������� ��ǰǰ������  �м�������  �����Ǻ���

*/
typedef struct treeNode
{
	char data;
	struct treeNode* LChild;
	struct treeNode* RChild;
}TREE;/* (win  LP����ָ�����)*/
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
//�ݹ�
//����
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
			pMove = stack[stackTop];//�ѱ�����ϸ�����
			stackTop--;
			pMove = pMove->RChild;
		}
	}
}
//����
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
//����
void recursion_Last(TREE*tree)
{
	if (tree != NULL)
	{
		recursion_Last(tree->LChild);
		recursion_Last(tree->RChild);
		print(tree);
	}
}
//�ǵݹ�
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
		//��ǰ����Ƿ񱻷���
		if (pMove->LChild == NULL || pMove->RChild == pLastVisit)
		{
			//��������ʾʹ�ӡ����ǰ���
			print(pMove);
			//�ı���λ��
			pLastVisit = pMove;
		}
		else
		{
			//�ұ�û�б�����
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
	printf("\n��������\n");
	recursion_First(A);
	putchar('\n');
	routine_First(A);
	printf("\n��������\n");
	recursion_MId(A);
	putchar('\n');
	routine_Mid(A);
	printf("\n��������\n");
	recursion_Last(A);
	putchar('\n');
	routine_Last(A);
	while (1);
	return 0;
}