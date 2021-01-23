#include <stdio.h>
#include <stdlib.h>
/*队列：先进先出*/
//基本单元
struct Node
{
	int data;
	struct Node* next;
};
//创建节点
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL; 
	return newNode;
}
//队列结构体封装
struct myQueue
{
	int size;
	struct Node* front;
	struct Node* tail;
};
//创建队列
struct myQueue* createQueue()
{
	struct myQueue* newQueue = (struct myQueue*)malloc(sizeof(struct myQueue));
	newQueue->front = NULL;
	newQueue->tail = NULL;
	newQueue->size = 0;
	return newQueue;
}
int exist(struct myQueue* queue)
{
	return queue->size == 0;
}
//入队
void push(struct myQueue* Queue, int data)
{
	struct Node* newNode = createNode(data);
	if (exist(Queue))
	{
		Queue->front = newNode;
		Queue->tail=newNode;
	}
	else
	{
		Queue->tail->next = newNode;
		Queue->tail = newNode;
	}
	Queue->size++;
}
void pull (struct myQueue* Queue)
{
	if (exist(Queue))
	{
		printf("没有可出栈的元素\n");
		return;
	}
	else
	{
		struct Node* newNode = Queue->front;
		Queue->front = newNode->next;
		free(newNode);
		newNode = NULL;
		Queue->size--;
	}
}
int gaindata(struct myQueue* Queue)
{
	if (exist(Queue))
	{
		printf("没有可出栈的元素\n");
		system("pause");
		exit(0);
	}
	return Queue->front->data;
}
int main()
{
	struct myQueue* queue = createQueue();
	//while (a)
	//{
	//	push(queue, a%10);
	//	a = a / 10;
	//}
	for (int i = 0; i < 10; i++)
	{
		push(queue,i);
	}
	while (queue->size)
	{
		printf("%d ",gaindata(queue));
		pull(queue);
	}
	printf("\n");
	system("pause");
	return 0;
}