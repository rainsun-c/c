//#define MAX 10
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
///* 
//	���� 
//*/
//typedef  char vertexType[4];   //��������
//typedef int VrType;			   //������
//typedef struct _Graph		   //ͼ�ṹ
//{
//	int vexnum;				 //������
//	int arcunm;				 //����
//	vertexType vextex[MAX];	 //������
//	VrType matrix[MAX][MAX]; //����Ȩֵ���ŵı��
//}Graph;
////���ұ�Ҫ�ŵ�λ��
//int search(Graph* graph,vertexType ver)
//{
//	for (int i = 0; i < graph->vexnum; i++)
//	{
//		if (strcmp(graph->vextex[i], ver))
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//Graph* createGraph()
//{
//	Graph* newGraph = (Graph*)malloc(sizeof(Graph));
//	assert(newGraph!=NULL);
//	memset(newGraph->matrix,0,sizeof(4)*MAX*MAX);
//	printf("����������Ͷ������� ");
//	scanf("%d%d",&newGraph->arcunm,&newGraph->vexnum);
//	printf("������%d���������� ",newGraph->vexnum);
//	for (int i = 0; i < newGraph->vexnum; i++)
//	{
//		scanf("%s",newGraph->vextex[i]);
//	}
//	VrType vex;
//	vertexType v1, v2;
//	printf("�����������Ķ��������\n");
//	for (int i = 0; i < newGraph->arcunm; i++)
//	{
//		scanf("%s%s%d",v1,v2,&vex);
//		int pos1 = search(newGraph,v1);
//		int pos2 = search(newGraph, v2);
//		newGraph->matrix[pos1][pos2] = vex;
//	}
//	return newGraph;
//}
////��ʾ
//void show(Graph* graph)
//{
//	for (int i = 0; i < graph->vexnum; i++)
//	{
//		printf("\t%s",graph->vextex[i]);
//	}
//	putchar('\n');
//	for (int i = 0; i < graph->vexnum; i++)
//	{
//		printf("%s\n",graph->vextex[i]);
//		for (int j = 0; j < graph->vexnum; j++)
//		{
//			printf("\t%d",graph->matrix[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	Graph* graph = createGraph();
//	show(graph);
//	system("pause");
//	return 0;
//}