#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define  MAX_LINE 4092340
#define MAX_Size  50
char** pp;
//�����ݷ���
void init()
{
	pp = (char**)calloc(MAX_LINE,sizeof(char*));
	if (pp == NULL)
	{
		perror("error");
		return;
	}
	FILE* rfp = fopen("QQ-9400W1.txt","r");
	if (rfp == NULL)
	{
		perror("error");
		return -1;
	}
	char str[50] = "";
	for (int i = 0; i < MAX_LINE; i++)
	{
		fgets(str, 50, rfp);

		pp[i] = (char*)calloc(MAX_Size, sizeof(char));
		if (pp[i] != NULL)
		{
			strcpy(pp[i],str);

		}
		else
		{
			printf("�ڴ�����ʧ��~~��~~\n");
		}
	}
	fclose(rfp);
	printf("�ڴ�������\n");
}
//�м���
int opateFile(char* fileName)
{
	FILE* pf = fopen(fileName, "r");
	if (pf == NULL)
	{
		perror("error");
		return -1;
	}
	char str[50] = "";
	int count = 0;
	while (!feof(pf))
	{
		fgets(str, 50, pf);
		count++;
	}
	fclose(pf);
	return count;
}
//һ������Ƕ���
int opateFileSize(char* fileName)
{
	FILE* pf = fopen(fileName, "r");
	if (pf == NULL)
	{
		perror("error");
		return -1;
	}
	char str[50] = "";
	int len = 0;
	while (!feof(pf))
	{
		fgets(str, 50, pf);//\n��һ��
		if (len<strlen(str))
		{
			len = strlen(str);
		}
	}
	fclose(pf);
	return len;
}
//����
void search(char* substr)
{
	for (int i = 0; i < MAX_LINE; i++)
	{
		if (strstr(pp[i], substr))
		{
			puts(pp[i]);
		}
	}
}
int main()
{
	//long long a = opateFile("QQ-9400W1.txt");
	//printf("%lld\n",a);
	//printf("%d", opateFileSize("QQ-9400W1.txt"));
	init();
	int cnt = 0;
	while (1)
	{
		char str[50] = " ";
		scanf_s("%s",str,50);
		search(str);
		printf("��%d�μ���:",cnt++);
	}
	system("pause");
	return 0;
}