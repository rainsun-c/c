#include "skip.h"

Node* createNode(Data* data)//������֧���
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
SkipNode* createSkipNode(Data* data)//����������
{
	SkipNode* newNode = (SkipNode*)malloc(sizeof(SkipNode));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->first = NULL;
	newNode->next = NULL;
	return newNode;
}
Skiplist* createSkipList(int divisor)//��������
{
	Skiplist* list = (Skiplist*)malloc(sizeof(Skiplist));
	assert(list != NULL);
	list->headNode = NULL;
	list->divs = divisor;
	list->sizeSkipList = 0;
	return list;
}
void addSkipListNode(Skiplist* list, Data* data)
{
	SkipNode * newSkipNode = createSkipNode(data);
	int pos = data->first % list->divs;//����
	if (list->sizeSkipList == 0)//����Ϊ��ʱ
	{
		list->headNode = newSkipNode;
		list->sizeSkipList++;
	}
	else
	{
		if (list->headNode->data->first > pos)//�����С��ͷ���λ�ã����½��ͳ�Ϊͷ���
		{
			newSkipNode->next = list->headNode;
			list->headNode = newSkipNode;
			list->sizeSkipList++;
		}
		else
		{
			SkipNode* Move = list->headNode;
			SkipNode* pMove = Move;
			while (Move->data->first %list->divs < pos)//������λ��С�ڲ������ݵļ�ʱѭ����
			{	//����ʱ��ʾ�ڸõ�ַǰ������ߵ�����Ҫ�����ж�
				pMove = Move;
				Move = pMove->next;
				if (Move == NULL)
				{
					break;
				}
			}
			if (Move == NULL)
			{   //��Ϊ���һ��ʱ�������������������һ��
				if (pMove->data->first % list->divs < pos)
				{
					pMove->next = newSkipNode;

					list->sizeSkipList++;
				}
				//��λ�������������һ��ʱ����
				if (pMove->data->first % list->divs == pos)
				{
					//����һ��ʱ��ֱ�ӿ���
					if (pMove->data->first = data->first)
					{
						strcpy(pMove->data->str, data->str);
					}
					//��һ��ʱ������֧��
					else
					{
						Node* newNode = createNode(data);
						Node* rep = pMove->first;
						//��û�з�֧ʱ����ͷ����ͷ��
						if (rep == NULL)
						{
							newNode->next = pMove->first;
							pMove->first = newNode;
							list->sizeSkipList++;
						}
						//�з�֧ʱ��������û��һ����
						else
						{
							while (rep->data->first != data->first)
							{
								if (rep == NULL)
								{
									break;
								}
								rep = rep->next;
							}
							//����Ϊ�գ��������һ���ģ�ֱ�Ӹ���
							if (rep != NULL)
							{
								strcpy(rep->data->str, data->str);
							}
							//û��һ���ľ�ͷ��
							else
							{
								newNode->next = pMove->first;
								pMove->first = newNode;
								list->sizeSkipList++;
							}
						}
					}
				}
			}
		}
	}
}
void show(Skiplist* list)//��ʾ
{
	SkipNode* rep = list->headNode;
	while (rep != NULL)
	{
		printf("(%d,%s)\t", rep->data->first, rep->data->str);
		Node* rep1 = rep->first;
		while (rep1 != NULL)
		{
			printf("(%d,%s)", rep1->data->first, rep1->data->str);
			rep1 = rep1->next;
		}
		rep = rep->next;
		putchar('\n');
	}
}