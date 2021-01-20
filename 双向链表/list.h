#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int Data;
typedef struct _Node
{
	struct _Node* first;
	int data;
	struct _Node* last;
}Node;
//有头结点
typedef struct doubleList
{
	Node*Front;
	int size;
	Node*Tail;
}doublelist;
void menu();
doublelist* creta_doubleList();//创建链表
void show(doublelist* list);//从头开始打印
void Tail_list(doublelist* list, Data data);//尾插
void Front_list(doublelist* list, Data data);//头插
Node* find(doublelist* list, Data data);//查找指定元素
void insertT_list(doublelist* list, Data data, Data index);//指定数据插入(后)
void insertF_list(doublelist* list, Data data, Data index);//指定数据插入(前)
int size(doublelist* list);//尺寸
void deleteTail_list(doublelist* list);//尾删
void deleteFront_list(doublelist* list);//头删
void deleteInsert_list(doublelist* list, Data index);//指定删除
void sort(doublelist* list);//排序
void clean_list(doublelist* list);//清空链表
void destory(doublelist** list);//销毁链表
void reverse(doublelist* list);//翻转