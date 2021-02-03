#define _CRT_SECURE_NO_WARNINGS

#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef  char vertexType[4];   //顶点类型
/*
邻接顶点法
*/
//结点
typedef struct _Node
{
	int num;
	struct _Node* first;
}Node;

//数据
typedef struct _Data
{
	vertexType ver;
	Node* firstNode;
}Data;

//图
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
	printf("请输入图的边和顶点\n");
	scanf("%d%d", &graph->sideNum, &graph->verNum);
	//顶点
	printf("请输入%d个顶点\n", graph->verNum);
	graph->data = (Data*)malloc(sizeof(Data)*graph->verNum);
	assert(graph->data != NULL);
	for (int i = 0; i < graph->verNum; i++)
	{
		scanf("%s", graph->data[i].ver);
		graph->data[i].firstNode = NULL;
	}
	printf("输入连接的点\n");
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
{   //选定的结点不要入栈
	//定义栈
	Node* stack[MAX];
	int top = -1;
	//标记
	int visited[MAX] = { 0 };

	visitVextex(graph->data[inpos].ver);//打印
	visited[inpos] = 1;//标记打印过的数据
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
	printf("无向无权\n");
	Graph* graph = createGraph();
	//show(graph);
	DFSTgraph(graph, 0);//头插
	system("pause");
	return 0;
}