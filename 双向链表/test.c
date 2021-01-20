#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

int main()
{
	doublelist* list = creta_doubleList();
	menu();
	int select = -1;
	int index = -1;
	int data = -1;
	Node* ret = NULL;
	while (1)
	{
		printf("\nselect>\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入数据,以-1结束\n");
			//while (scanf("%d", &data)&&data!=-1)
			//{
			//	Front_list(list,data);//头插
			//}
			for (int i = 0; i < 20; i++)
			{
				Front_list(list, i);//头插
			}
			break;
		case 2:
			printf("请输入数据,以-1结束\n");
			while (scanf("%d", &data) && data != -1)
			{
				Tail_list(list, data);//尾插
			}
			break;
		case 3:
			deleteFront_list(list);//头删
			break;
		case 4:
			deleteTail_list(list);//尾删
			break;
		case 5:
			printf("先数据后位置\n");
			while (scanf("%d",&data ) && data != -1)
			{
				scanf("%d", &index);
				insertT_list(list, data,index);//指定数据插入(前)
			}
			break;
		case 6:
			printf("先数据后位置\n");
			while (scanf("%d", &data) && data != -1)
			{
				scanf("%d", &index);
				insertT_list(list,data,index);//指定数据插入(后)
			}
			break;
		case 7:
			show(list);//从头开始打印
			break;
		case 8:
			sort(list);//排序
			break;
		case 9:
			scanf("%d", &data);
			ret=find(list,data);//查找指定元素
			printf("\n%d ",ret->data);
			break;
		case 10:
			clean_list(list);//清空链表
			break;
		case 11:
			destory(&list);//销毁链表
			break;
		case 12:
			printf(" 长度为%d ", size(list));
			break;
		case 13:
			printf("请输入要删除数据,以-1结束\n");
			while (scanf("%d", &index) && index != -1)
			{
				deleteInsert_list(list, index);//指定删除
			}
			break;
		case 14:
			reverse(list);//翻转
			break;
		}
	}

	while (1);
	return 0;
}