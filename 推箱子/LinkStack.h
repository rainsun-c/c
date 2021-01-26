#pragma once
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


#include<stdbool.h>

	struct Point
	{
		int r;			//记录行和列
		int c;
		int dada;		//记录对应下标的数据
	};
	typedef struct _State
	{
		struct Point pos[3];
	}Data, State;
	/*******/
	//typedef int Data;

	typedef struct _Node
	{
		Data data;
		struct _Node* next;
	}Node;

	typedef struct _LinkStack
	{
		int size;
		Node* front;
	}LinkStack;

	LinkStack* createLinkStack();
	void push(LinkStack* s, Data val);
	void pop(LinkStack* s);
	Data top(LinkStack* s);
	int size(LinkStack* s);
	bool empty(LinkStack* s);

#ifdef __cplusplus
}
#endif // __cplusplus