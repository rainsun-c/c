#define  _CRT_SECURE_NO_WARNINGS

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct _Data//��������
{
	int first;				//��
	char str[20];			//Ԫ��
}Data;
typedef struct _SkipN  //������
{
	Data* data;				//Ԫ��
	Node* first;	//�Ź�ϣ��ͻԪ�أ���֧��
	struct _SkipN* next;	//�¸���ϣ���
}SkipNode;
typedef struct _Node//��֧���
{
	Data* data;				//����
	struct _Node* next;		//�¸���֧���
}Node;
typedef struct _Skiplist//����
{
	SkipNode* headNode;		//�����ͷ���
	int divs;               //������ȡ�෨��
	int sizeSkipList;		//��С
}Skiplist;
Node* createNode(Data* data);//������֧���

SkipNode* createSkipNode(Data* data);//����������

Skiplist* createSkipList(int divisor);

void show(Skiplist* list);//��ʾ

void addSkipListNode(Skiplist* list, Data* data);