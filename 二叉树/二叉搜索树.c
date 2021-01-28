#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//ÿһ��������
typedef struct _Data
{
	int first;
	char str[20];
}Data;
//���������
typedef struct _TreeNode
{
	Data data;
	struct _TreeNode*LChild;
	struct _TreeNode*RChild;

}Node;
//��װһ������������
typedef struct _SeekTree
{
	Node* root;
	int treeSize;
}SeekTree;
//�������
Node* createNode(Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}
//����������
SeekTree* createSeekTree()
{
	SeekTree* newTree = (SeekTree*)malloc(sizeof(SeekTree));
	assert(newTree != NULL);
	newTree->root = NULL;
	newTree->treeSize = 0;
	return newTree;
}
//��ӡ
void print(Node* tree)
{
	printf("%d\t%s\n", tree->data.first,tree->data .str);
}
//�ݹ����
void CurTree(Node* tree)
{
	if (tree != NULL)
	{
		CurTree(tree->LChild);
		print(tree);
		CurTree(tree->RChild);
	}
}
//����
void insert(SeekTree* tree, Data data)
{
	Node* newNode = createNode(data);
	//�Һ���λ��
	Node* pMove = tree->root;
	Node* pMoveParent = NULL;//��¼
	while (pMove != NULL)
	{
		pMoveParent = pMove;//��¼�ƶ����ĸ��ڵ�
		if (data.first < pMove->data.first)
		{
			pMove = pMove->LChild;
		}
		else if (data.first < pMove->data.first)
		{
			pMove = pMove->RChild;
		}
		else//��ͬ�Ĵ��������� ��ѡ��ʽ
		{
			//�޸���ͬ�ؼ��ֵĽ���е�����
			strcmp(pMove->data.str, data.str);
			return;
		}
	}
	//�˳�ѭ��
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
//����
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
//��������ɾ��
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
			//��������
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
			//����������
			//����ɾ����ָ��
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
		//���ɾ���Ľ�����Ҵ��ڽ�㣬����ɾ��������һ�����
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
	printf("�������\n");
	CurTree(tree->root);
	while (1);
	return 0;
}
