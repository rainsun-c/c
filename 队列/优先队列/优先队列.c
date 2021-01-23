//#define Max 10
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct Data
//{
//	int data;
//	int weight;
//};
//struct Queue
//{
//	struct Data* queue;
//	int size;
//};
//struct Queue* createQueue()
//{
//	struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
//	newQueue->queue = (struct Data*)malloc(sizeof(struct Data)*Max);
//	newQueue->size; 
//	return newQueue;
//}
//void push(struct Queue* myQueue, struct Data Data)
//{
//	if (myQueue->size == Max)
//	{
//		printf("¶ÓÒÑÂú\n");
//		return;
//	}
//	else{
//		myQueue->queue[myQueue->size++] = Data;
//	}
//}
//void pull(struct Queue* myQueue)
//{
//	myQueue->queue[myQueue->size++] = Data;
//}
//int main()
//{
//	while (1);
//	return 0;
//}