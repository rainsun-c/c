#define _CRT_SECURE_NO_WARNINGS

#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef  char vertexType[4];   //��������
/*
�ڽӶ��㷨
*/
//���
typedef struct _Node
{
	int num;
	struct _Node* first;
}Node;

//����
typedef struct _Data
{
	vertexType ver;
	Node* firstNode;
}Data;

//ͼ
typedef struct _Graph
{
	int verNum;
	int sideNum;
	Data* data;
}Graph;

Node* createNode(int w)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->first = NULL;
	newNode->num = w;
	return newNode;
}
void insert(Node** N, int w)
{
	Node* newNode = createNode(w);
	newNode->first = *N;
	*N = newNode;
}
int search(Graph* graph, vertexType ver)
{
	for (int i = 0; i < graph->verNum; i++)
	{
		if (strcmp(graph->data[i].ver, ver) == 0)
		{
			return i;
		}
	}
	return -1;
}
Graph* createGraph()
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	assert(graph != NULL);
	printf("������ͼ�ıߺͶ���\n");
	scanf("%d%d", &graph->sideNum, &graph->verNum);
	//����
	printf("������%d������\n", graph->verNum);
	graph->data = (Data*)malloc(sizeof(Data)*graph->verNum);
	assert(graph->data != NULL);
	for (int i = 0; i < graph->verNum; i++)
	{
		scanf("%s", graph->data[i].ver);
		graph->data[i].firstNode = NULL;
	}
	printf("�������ӵĵ�\n");
	vertexType ver1, ver2;
	for (int i = 0; i < graph->sideNum; i++)
	{
		scanf("%s%s", ver1, ver2);
		int v1 = search(graph, ver1);
		int v2 = search(graph, ver2);
		insert(&graph->data[v1].firstNode, v2);
		insert(&graph->data[v2].firstNode, v1);
	}
	return graph;
}
void show(Graph* graph)
{
	for (int i = 0; i < graph->verNum; i++)
	{
		printf("%s->", graph->data[i].ver);
		Node* pMove = graph->data[i].firstNode;
		while (pMove)
		{
			printf("%s->", graph->data[pMove->num].ver);
			pMove = pMove->first;
		}
		printf("\n");
	}
}
void visitVextex(vertexType ver)
{
	printf("%s-->", ver);
}
void DFSTgraph(Graph* graph, int inpos)
{   //ѡ���Ľ�㲻Ҫ��ջ
	//����ջ
	Node* stack[MAX];
	int top = -1;
	//���
	int visited[MAX] = { 0 };

	visitVextex(graph->data[inpos].ver);//��ӡ
	visited[inpos] = 1;//��Ǵ�ӡ��������
	Node* pMove = graph->data[inpos].firstNode;
	while (top > -1 || pMove)
	{
		while (pMove)
		{
			if (visited[pMove->num] == 1)
			{
				pMove = pMove->first;
			}
			else
			{
				visitVextex(graph->data[pMove->num].ver);
				visited[pMove->num] = 1;
				stack[++top] = pMove;
				pMove = pMove->first;
			}
		}
		if (top > -1)
		{
			pMove = stack[top--];
			pMove = pMove->first;
		}
	}
}
int main()
{
	printf("������Ȩ\n");
	Graph* graph = createGraph();
	//show(graph);
	DFSTgraph(graph, 0);//ͷ��
	system("pause");
	return 0;
}