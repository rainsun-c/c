#include "LinkStack.h"
#include<malloc.h>
#include<stdio.h>
#include<assert.h>
LinkStack* createLinkStack()
{
	LinkStack* s = calloc(1, sizeof(LinkStack));
	assert(s != NULL);
	s->front = calloc(1, sizeof(Node));
	assert(s->front != NULL);
	s->size = 0;
	return s;
}
static Node* createNode(Data val)
{
	Node* newNode = calloc(1, sizeof(Node));
	if (!newNode)
	{
		return NULL;
	}
	newNode->data = val;
	return newNode;
}
void push(LinkStack* s, Data val)
{
	Node* newNode = createNode(val);
	newNode->next = s->front->next;
	s->front->next = newNode;
	s->size++;
}
void pop(LinkStack* s)
{
	assert(!empty(s));
	Node* delNode = s->front->next;
	s->front->next = delNode->next;
	free(delNode);
	s->size--;
}
Data top(LinkStack* s)
{
	assert(!empty(s));
	return s->front->next->data;
}
int size(LinkStack* s)
{
	return s->size;
}
bool empty(LinkStack* s)
{
	return s->size == 0;
}
