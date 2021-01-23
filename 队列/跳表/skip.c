#include "skip.h"

Node* createNode(Data* data)//创建分支结点
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
SkipNode* createSkipNode(Data* data)//创建跳表结点
{
	SkipNode* newNode = (SkipNode*)malloc(sizeof(SkipNode));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->first = NULL;
	newNode->next = NULL;
	return newNode;
}
Skiplist* createSkipList(int divisor)//创建跳表
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
	int pos = data->first % list->divs;//求余
	if (list->sizeSkipList == 0)//跳表为空时
	{
		list->headNode = newSkipNode;
		list->sizeSkipList++;
	}
	else
	{
		if (list->headNode->data->first > pos)//如果键小于头结点位置，则新结点就成为头结点
		{
			newSkipNode->next = list->headNode;
			list->headNode = newSkipNode;
			list->sizeSkipList++;
		}
		else
		{
			SkipNode* Move = list->headNode;
			SkipNode* pMove = Move;
			while (Move->data->first %list->divs < pos)//当跳表位置小于插入数据的键时循环，
			{	//大于时表示在该地址前插入或者到最后就要其他判断
				pMove = Move;
				Move = pMove->next;
				if (Move == NULL)
				{
					break;
				}
			}
			if (Move == NULL)
			{   //当为最后一个时，键（余数）大于最后一个
				if (pMove->data->first % list->divs < pos)
				{
					pMove->next = newSkipNode;

					list->sizeSkipList++;
				}
				//当位置与键（余数）一样时讨论
				if (pMove->data->first % list->divs == pos)
				{
					//当键一样时，直接拷贝
					if (pMove->data->first = data->first)
					{
						strcpy(pMove->data->str, data->str);
					}
					//不一样时，往分支走
					else
					{
						Node* newNode = createNode(data);
						Node* rep = pMove->first;
						//当没有分支时，无头链表头插
						if (rep == NULL)
						{
							newNode->next = pMove->first;
							pMove->first = newNode;
							list->sizeSkipList++;
						}
						//有分支时，先找有没有一样的
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
							//当不为空，则表明有一样的，直接覆盖
							if (rep != NULL)
							{
								strcpy(rep->data->str, data->str);
							}
							//没有一样的就头插
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
void show(Skiplist* list)//显示
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