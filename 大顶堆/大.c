#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define Max 11
typedef struct _Heap
{
	int sizeHeap;
	int* heapData;
}Heap;

//������
Heap* createHeap()
{
	Heap* newHeap = (Heap*)malloc(sizeof(Heap));
	assert(newHeap!=NULL);
	newHeap->sizeHeap = 0;
	newHeap->heapData = (int*)malloc(sizeof(int)*Max);
	assert(newHeap->heapData != NULL);
	return newHeap;
}
//�ƶ�����
void moveData(Heap* heap, int cur)
{
	//ֻ��һ����ʱ����Ҫ����
	while (cur > 1)
	{
		int max = heap->heapData[cur];
		int parentIndex = cur / 2;
		//�����ĸ�����Сʱ�����������Ƚ�ֱ�����
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


void push(Heap* heap, int data)//������͸
{
	//�ѵ�����0λ�ò��Ŷ���
	++heap->sizeHeap;
	heap->heapData[heap->sizeHeap] = data;
	//����λ��
	moveData(heap,heap->sizeHeap);
}

void pop(Heap* heap)//������͸
{
	int curPos = 1;
	int childIndex = curPos * 2;
	//ɾ��ʱ���Ӹ���ʼ��������2���Ӹ���ѡ����Ĳ��ϣ�һֱ��û�л��߳�����ΧΪֹ��
	//Ȼ������һ��λ�ã�ֱ�ӷŵ�����ܶ���λ��
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