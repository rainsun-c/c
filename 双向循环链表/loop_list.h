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
//��ͷ���
typedef struct doubleList
{
	Node*Front;
	int size;
	Node*Tail;
}doublelist;
void menu();
doublelist* creta_doubleList();//��������
void show(doublelist* list);//��ͷ��ʼ��ӡ
void Tail_list(doublelist* list, Data data);//β��
void Front_list(doublelist* list, Data data);//ͷ��
Node* find(doublelist* list, Data data);//����ָ��Ԫ��
void insertT_list(doublelist* list, Data data, Data index);//ָ�����ݲ���(��)
void insertF_list(doublelist* list, Data data, Data index);//ָ�����ݲ���(ǰ)
int size(doublelist* list);//�ߴ�
void deleteTail_list(doublelist* list);//βɾ
void deleteFront_list(doublelist* list);//ͷɾ
void deleteInsert_list(doublelist* list, Data index);//ָ��ɾ��
void sort(doublelist* list);//����
void clean_list(doublelist* list);//�������
void destory(doublelist** list);//��������
void reverse(doublelist* list);//��ת