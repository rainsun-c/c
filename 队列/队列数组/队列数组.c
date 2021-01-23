#define Max 10

#include <stdio.h>
#include <stdlib.h>
//静态
struct Queue
{
	int* queue;
	int front;
	int tail;
};
//创建队列
struct Queue* createQueue()
{
	struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
	newNode->queue = (int *)malloc(sizeof(int)*Max);
	newNode->front = 0;
	newNode->tail = 0;
	return newNode;
}
//入队尾插法
void push(struct Queue*	myQueue,int data)
{
	if (myQueue->tail == Max )
	{
		printf("队满不能入队\n");
		return;
	}
	else
	{
		//移动尾巴
		myQueue->queue[myQueue->tail++] = data;
	}
}
//出队（头出）
int pull(struct Queue* queue)
{
	if (queue->front == queue->tail)
	{
		printf("队列已经没有数据\n");
		return -1;
	}else
	{
		//移动头，做伪出栈
		return queue->queue[queue->front++];
	}
	
}
int size(struct Queue* queue)
{
	return queue->front != queue->tail;
}
int main()
{
	////队列数组
	//int queue[Max] = {0};
	//int num = 123;
	//int queueSize = 0;
	//while (num)
	//{
	//	queue[queueSize++] = num % 10;
	//	num = num / 10;
	//}
	//while (queueSize)
	//{
	//	printf("%d " ,queue[--queueSize]);
	//
	struct Queue* queue = createQueue();
	for (int i = 0; i < 5; i++)
	{
		push(queue,i);
	}
	while (size(queue))
	{
		printf("%d ", pull(queue));
	}
	system("pause");
	return 0;
}