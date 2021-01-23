#define Max 10

#include <stdio.h>
#include <stdlib.h>
//��̬
struct Queue
{
	int* queue;
	int front;
	int tail;
};
//��������
struct Queue* createQueue()
{
	struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
	newNode->queue = (int *)malloc(sizeof(int)*Max);
	newNode->front = 0;
	newNode->tail = 0;
	return newNode;
}
//���β�巨
void push(struct Queue*	myQueue,int data)
{
	if (myQueue->tail == Max )
	{
		printf("�����������\n");
		return;
	}
	else
	{
		//�ƶ�β��
		myQueue->queue[myQueue->tail++] = data;
	}
}
//���ӣ�ͷ����
int pull(struct Queue* queue)
{
	if (queue->front == queue->tail)
	{
		printf("�����Ѿ�û������\n");
		return -1;
	}else
	{
		//�ƶ�ͷ����α��ջ
		return queue->queue[queue->front++];
	}
	
}
int size(struct Queue* queue)
{
	return queue->front != queue->tail;
}
int main()
{
	////��������
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