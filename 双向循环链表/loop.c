#include "loop_list.h"

void menu()
{
	printf("********************************+*\n");
	printf("* [1]头添加        [2]尾添加     *\n");
	printf("* [3]头删除        [4]尾删除     *\n");
	printf("* [5]指定添加(前)  [6]指定添加(后)*\n");
	printf("* [7]显示          [8]排序       *\n");
	printf("* [9]查找元素      10]清空       *\n");
	printf("* [11]销毁         [12]长度      *\n");
	printf("* [13]指定删除     [14]翻转      *\n");
	printf("**********************************\n");
}
doublelist* creta_doubleList()//创建链表
{
	doublelist* List = (doublelist*)calloc(1, sizeof(doublelist));
	assert(List != NULL);
	List->Front = List->Tail;
	List->size = 0;
	return List;
}
Node* create_Node(Data data)//创建结点
{
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->data = data;
	newNode->first = NULL;
	newNode->last = NULL;
	return newNode;
}
void Tail_list(doublelist* list, Data data)//尾插
{
	Node* newNode = create_Node(data);
	assert(newNode != NULL);
	if (list->size == 0)
	{
		list->Front = newNode;
		list->Tail = newNode;
		newNode->first = newNode;
		newNode->last = newNode;
	}
	else
	{
		newNode->last = list->Tail->last;
		newNode->first = list->Front;
		list->Tail->last = newNode;
		list->Tail = newNode;
		list->Front->first = newNode;
	}
	list->size++;
}
void Front_list(doublelist* list, Data data)//头插
{

	Node* newNode = create_Node(data);
	assert(newNode != NULL);
	if (list->size == 0)
	{
		list->Front = newNode;
		list->Tail = newNode;
		newNode->first = newNode;
		newNode->last = newNode;
	}
	else
	{
		newNode->first = list->Front->first;
		newNode->last = list->Front;
		list->Front->first = newNode;
		list->Front = newNode;
		list->Tail->last = newNode;
	}
	list->size++;
}
void insertT_list(doublelist* list, Data data, Data index)//指定数据插入(后)
{
	assert(list != NULL);
	Node* rep = find(list, index);
	assert(rep != NULL);
	if (rep == list->Tail)
	{
		Tail_list(list, data);
		return;
	}
	Node* rep1 = rep->last;
	Node* newNode = create_Node(data);

	newNode->first = rep;
	rep->last = newNode;

	newNode->last = rep1;
	rep1->first = newNode;

	list->size++;
}
void insertF_list(doublelist* list, Data data, Data index)//指定数据插入(前)
{
	assert(list != NULL);
	Node* rep = find(list, index);
	assert(rep != NULL);
	if (rep == list->Front)//如果插入的位置是第一个节点
	{
		Front_list(list, data);//头插
	}
	else
	{
		Node* rep1 = rep->first;
		Node* newNode = create_Node(data);
		assert(rep1 != NULL);
		assert(newNode != NULL);
		newNode->last = rep;
		newNode->first = rep1;
		rep->first = newNode;
		rep1->last = newNode;	
		list->size++;
	}

}
Node* find(doublelist* list, Data data)//查找指定元素
{
	assert(list != NULL);
	Node* rep = list->Front;
	while (rep != list->Tail)
	{
		if (rep->data == data)
		{
			return rep;
		}
		rep = rep->last;
	}
	return NULL;
}
void deleteTail_list(doublelist* list)//尾删
{
	assert(list != NULL);
	if (list->size < 1)
	{
		return;
	}
	Node* rep = list->Tail;
	if (list->size == 1)
	{
		list->Front = list->Tail = NULL;
	}
	if (list->size>1)
	{
		rep->first->last = list->Front;
		list->Front->first = rep->first;
		list->Tail = rep->first;
	}
	free(rep);
	rep = NULL;
	list->size--;
}
void deleteFront_list(doublelist* list)//头删
{
	assert(list != NULL);
	if (list->size < 1)
	{
		return;
	}
	Node* rep = list->Front;//第一个节点
	if (list->size == 1)
	{
		list->Front = list->Tail = NULL;
	}
	else
	{
		Node* rep1 = rep->last;
		rep1->first = rep->first;
		list->Tail->last = rep1;
		list->Front = rep1;
	}
	free(rep);
	rep = NULL;
	list->size--;
}
void deleteInsert_list(doublelist* list, Data index)//指定删除
{
	assert(list != NULL);
	Node* rep = find(list, index);
	if (rep == NULL)
	{
		printf("error");
		return;
	}
	if (list->Front == rep)
	{
		deleteFront_list(list);//头删
	}
	else if (list->Tail == rep)
	{
		deleteTail_list(list);//尾删
	}
	else
	{
		Node* rep1 = rep->first;
		rep1->last = rep->last;
		rep->last->first = rep1;
		free(rep);
		rep = NULL;
		list->size--;
	}
}
void show(doublelist* list)//从头开始打印
{
	assert(list != NULL);

	Node* rep = list->Front;
	if (!size(list))
	{
		return;
	}
	//while (rep!= list->Tail)
	//{
	//	printf("%d ", rep->data);
	//	rep = rep->last;
	//}
	//if (rep == list->Tail)
	//{
	//	printf("%d ",rep->data);
	//}

	doublelist* p = list;
	while (p->size)
	{
		printf("%d ", rep->data);
		p->size--;
		rep = rep->last;
	}
}
int size(doublelist* list)//计算长度
{
	return list->size;
}
void sort(doublelist* list)//排序(从小到大)
{
	assert(list != NULL);
	Node* rep = list->Front;
	for (Node* i = rep; i != list->Tail;)
	{
		for (Node* j = rep; j != list->Tail;)
		{
			if ((i->data)< (j->data))
			{
				Data temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
			j = j->last;
		}
		i = i->last;
	}
}
//void sort(doublelist* list)//大到小
//{
//	/*if (empty(list))
//		return;*/
//	Node* rep = list->Front;
//	for (Node* i = rep; i != NULL; i = list->Tail)
//	{
//		for (Node* k = rep; k != NULL; k = list->Tail)
//		{
//			if (i->data > k->data)
//			{
//				Data t = k->data;
//				k->data = i->data;
//				i->data = t;
//			}
//		}
//	}
//}
void clean_list(doublelist* list)//清空链表
{
	assert(list != NULL);
	while (list->size > 0)
	{
		deleteFront_list(list);
		list->size--;
	}
}
void destory(doublelist** list)//销毁链表
{
	clean_list(*list);
	free((*list)->Front);
	free((*list)->Tail);
	free(*list);
	*list = NULL;
}
void reverse(doublelist* list)//翻转
{
	if (list->size<1)
	{
		return;
	}
	Node* p = list->Front;
	list->Front = list->Tail;
	list->Tail = p;
	//Node* curNode = list->Front;
	//Node* prevNode = NULL;
	//Node* nextNode = NULL;
	//list->Tail = curNode;

	//while (curNode != list->Tail)
	//{
	//	nextNode = curNode->last;

	//	curNode->last = prevNode;
	//	curNode->first = nextNode;

	//	prevNode = curNode;
	//	curNode = nextNode;		//移动当前指针
	//}
	//list->Front = prevNode;
	//prevNode->first = list->Front;
}