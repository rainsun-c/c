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
			printf("����������,��-1����\n");
			//while (scanf("%d", &data)&&data!=-1)
			//{
			//	Front_list(list,data);//ͷ��
			//}
			for (int i = 0; i < 20; i++)
			{
				Front_list(list, i);//ͷ��
			}
			break;
		case 2:
			printf("����������,��-1����\n");
			while (scanf("%d", &data) && data != -1)
			{
				Tail_list(list, data);//β��
			}
			break;
		case 3:
			deleteFront_list(list);//ͷɾ
			break;
		case 4:
			deleteTail_list(list);//βɾ
			break;
		case 5:
			printf("�����ݺ�λ��\n");
			while (scanf("%d",&data ) && data != -1)
			{
				scanf("%d", &index);
				insertT_list(list, data,index);//ָ�����ݲ���(ǰ)
			}
			break;
		case 6:
			printf("�����ݺ�λ��\n");
			while (scanf("%d", &data) && data != -1)
			{
				scanf("%d", &index);
				insertT_list(list,data,index);//ָ�����ݲ���(��)
			}
			break;
		case 7:
			show(list);//��ͷ��ʼ��ӡ
			break;
		case 8:
			sort(list);//����
			break;
		case 9:
			scanf("%d", &data);
			ret=find(list,data);//����ָ��Ԫ��
			printf("\n%d ",ret->data);
			break;
		case 10:
			clean_list(list);//�������
			break;
		case 11:
			destory(&list);//��������
			break;
		case 12:
			printf(" ����Ϊ%d ", size(list));
			break;
		case 13:
			printf("������Ҫɾ������,��-1����\n");
			while (scanf("%d", &index) && index != -1)
			{
				deleteInsert_list(list, index);//ָ��ɾ��
			}
			break;
		case 14:
			reverse(list);//��ת
			break;
		}
	}

	while (1);
	return 0;
}