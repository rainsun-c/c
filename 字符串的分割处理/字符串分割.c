#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char strt[] = 
"632242946----chendaxue592256 \
462084800----13923917670 \
315984797----yu19880726. \
492942626----190186 \
495585175----ut36940258 \
492527893----13092446031 \
409966941----mo19841006 \
648483611----woan.kang \
497786869----wodeziyou \
847254279----198602240224 ";

//����
struct Info
{
	unsigned long long QQ;
	char passwd[20];
};
//
struct Infos
{
	struct Info* base;
	int size;
}userInfos;
//����
int  count(char* str)
{
	int i = 0;
	while (str=strstr(str+4,"----"))
	{ //strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
	  //����ǣ���ú������� str1�ַ����� str2��һ�γ��ֵ�λ�ÿ�ʼ�� str1��β���ַ���
		i++;
	}
	return i;
}
//��ʼ���ṹ
void init()
{
	userInfos.size = count(strt);
	userInfos.base = (struct Info*)malloc(sizeof(struct Info)*userInfos.size);
	assert(userInfos.base != NULL);
}
//�ָ�洢
void SeData(char* str)
{
	//�Ƚ�������һ��һ���ָ����
	char* p = str;
	int len = strlen(str);
	while (*p!=NULL)
	{
		if (*p == ' ')
		{
			*p = '\0';
		}
		p++;
	}
	//�ٽ�ÿ�����ݵ��˺ź�����ֱ�ָ����
	int index = 0;
	for (char* px = str; px < str + len;index++)
	{
		char* subStr = (char*)malloc(sizeof(char)*strlen(px)+1);
		assert(subStr != NULL);
		strcpy(subStr, px);
		char*subp = strstr(subStr, "----");
		if (subp != NULL)
		{
			*subp = '\0';
		}
		/*printf("%s %s\n",subStr,subp+4);*/
		sscanf(subStr, "%lld", &userInfos.base[index].QQ);
		strcpy(userInfos.base[index].passwd, subp + 4);//��ʽ������
		px = px + strlen(px) + 1;//���ַ����ĳ��ȣ�����\0��
	}
}
//��ʾ
void show()
{
	printf("QQ��\t\t����\n");
	for (int i = 0; i < userInfos.size; i++)
	{
		printf("%-lld\t%-s\n", userInfos.base[i].QQ, userInfos.base[i].passwd);
	}
}
int main()
{
	init();
	int a = count(strt);
	printf("%d",a);
	SeData(strt);
	show();
	system("pause");
	return 0;
}