#define  _CRT_SECURE_NO_WARNINGS

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct _Data//数据类型
{
	int first;				//建
	char str[20];			//元素
}Data;
typedef struct _SkipN  //跳表结点
{
	Data* data;				//元素
	Node* first;	//放哈希冲突元素（分支）
	struct _SkipN* next;	//下个哈希结点
}SkipNode;
typedef struct _Node//分支结点
{
	Data* data;				//数据
	struct _Node* next;		//下个分支结点
}Node;
typedef struct _Skiplist//跳表
{
	SkipNode* headNode;		//跳表的头结点
	int divs;               //个数（取余法）
	int sizeSkipList;		//大小
}Skiplist;
Node* createNode(Data* data);//创建分支结点

SkipNode* createSkipNode(Data* data);//创建跳表结点

Skiplist* createSkipList(int divisor);

void show(Skiplist* list);//显示

void addSkipListNode(Skiplist* list, Data* data);