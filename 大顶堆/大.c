#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define Max 11
typedef struct _Heap
{
	int sizeHeap;
	int* heapData;
}Heap;

//创建堆
Heap* createHeap()
{
	Heap* newHeap = (Heap*)malloc(sizeof(Heap));
	assert(newHeap!=NULL);
	newHeap->sizeHeap = 0;
	newHeap->heapData = (int*)malloc(sizeof(int)*Max);
	assert(newHeap->heapData != NULL);
	return newHeap;
}
//移动调序
void moveData(Heap* heap, int cur)
{
	//只有一个的时候不需要排序
	while (cur > 1)
	{
		int max = heap->heapData[cur];
		int parentIndex = cur / 2;
		//当它的根比他小时交换，继续比较直到最后
		if ( max>heap->heapData[parentIndex] )
		{
			heap->heapData[cur] = heap->heapData[parentIndex];
			heap->heapData[parentIndex] = max;
			cur = parentIndex;
		}
		else
		{
			break;
		}
	}
}

int size(Heap* heap)
{
	return heap->sizeHeap == 0;
}


void push(Heap* heap, int data)//向上渗透
{
	//堆的数组0位置不放东西
	++heap->sizeHeap;
	heap->heapData[heap->sizeHeap] = data;
	//调整位置
	moveData(heap,heap->sizeHeap);
}

void pop(Heap* heap)//向下渗透
{
	int curPos = 1;
	int childIndex = curPos * 2;
	//删除时，从根开始，从左右2个子根中选出大的补上，一直到没有或者超出范围为止，
	//然后把最后一个位置，直接放到最后不能动的位置
	while (childIndex <= heap->sizeHeap)
	{
		int temp = heap->heapData[childIndex];
		if (childIndex + 1 <= heap->sizeHeap&&temp < heap->heapData[childIndex + 1])
		{
			temp = heap->heapData[childIndex++];
		}
		heap->heapData[curPos] = temp;
		curPos = childIndex ;
		childIndex *= 2;
	}
	heap->heapData[curPos] = heap->heapData[heap->sizeHeap];
	heap->sizeHeap--;
}
int main()
{
	Heap* heap = createHeap();
	push(heap, 5);
	push(heap, 2);
	push(heap, 6);
	push(heap, 8);
	push(heap, 1);

	for (int i = 1; i <=heap->sizeHeap; i++)
	{
		printf("%d ",heap->heapData[i]);
	}
	putchar('\n');
	pop(heap);
	for (int i = 1; i <= heap->sizeHeap; i++)
	{
		printf("%d ", heap->heapData[i]);
	}
	while (1);
	return 0;
}