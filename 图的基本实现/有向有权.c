//#define MAX 10
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
///* 
//	矩阵法 
//*/
//typedef  char vertexType[4];   //顶点类型
//typedef int VrType;			   //边类型
//typedef struct _Graph		   //图结构
//{
//	int vexnum;				 //顶点数
//	int arcunm;				 //边数
//	vertexType vextex[MAX];	 //顶点名
//	VrType matrix[MAX][MAX]; //所有权值（放的表格）
//}Graph;
////查找边要放的位置
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
//	printf("请输入边数和顶点数： ");
//	scanf("%d%d",&newGraph->arcunm,&newGraph->vexnum);
//	printf("请输入%d个顶点名： ",newGraph->vexnum);
//	for (int i = 0; i < newGraph->vexnum; i++)
//	{
//		scanf("%s",newGraph->vextex[i]);
//	}
//	VrType vex;
//	vertexType v1, v2;
//	printf("请输入相连的顶点与边数\n");
//	for (int i = 0; i < newGraph->arcunm; i++)
//	{
//		scanf("%s%s%d",v1,v2,&vex);
//		int pos1 = search(newGraph,v1);
//		int pos2 = search(newGraph, v2);
//		newGraph->matrix[pos1][pos2] = vex;
//	}
//	return newGraph;
//}
////显示
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