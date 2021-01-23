#define _CRT_SECURE_NO_WARNINGS

#define hash_count 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ϣ�ṹ������ģ�����洢�ṹ�� �ض��Ĺ�ϵ
/*
���ݺ͵�ַ��ӳ���ϵ->������ϵ��
��ѧ�еĺ�����ϵ
�����ݳ䵱��ַ y(x)=x��ֱ�Ӷ�ֵ���������ַ���������ĵ�ַ�����磺�����±꣨���Գ䵱��ַ��;
ȱ�㣺�˷��ڴ棬����������100���Ǿ�Ҫ�ŵ�100�ĵ�ַλ��

ȡ�෨�����ã�����ϣ��ַ��������Ԫ�ظ���
y=x%10;

��ϣ��ͻ��ԭ����ַ����Ԫ�صģ�
����취��
1��������ַ������û�п��ŵĵ�ַ���������ݡ������ϣ
2�����������Ը�Ԫ�أ�Ϊͷ��������

��ʽ��ϣ����������=����
*/
typedef struct _Data
{
	int first;
	char str[20];
}Data;
typedef struct hashtable
{
	Data** data;
	int divisor;     //ȡ�෨
	int hash_size;
}Hash;
Hash* createHash(int num)//�������б�
{
	Hash* hash = (Hash*)malloc(sizeof(Hash));
	if (hash == NULL)
	{
		return NULL;
	}
	hash->divisor = num;
	hash->data = (Data**)malloc(sizeof(Data)* (hash->divisor));
	if (hash->data == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < hash->divisor; i++)
	{
		hash->data[i] = NULL;
	}
	hash->hash_size = 0;
	return hash;
}
int Find(Hash* hash, int first)
{
	int pos = first%hash->divisor;
	int cur = pos;
	do
	{
		if (hash->data[pos] == NULL || /*hash->data[pos]->first*/ pos == first)
		{
			return pos;
		}
		pos = (pos + 1) % hash->divisor;
	} while (cur != pos);
	return pos;
}
void addHsah(Hash* hash, Data* data)//���
{
	int pos = Find(hash, data->first);
	if (hash->data[pos] == NULL)
	{
		hash->data[pos] = data;
		hash->hash_size++;
	}
	else
	{
		if (hash->data[pos]->first == data->first)
		{
			strcpy(hash->data[pos]->str, data->str);
		}
		else
		{
			printf("����\n");
		}

	}
}
void showHash(Hash* hash)
{
	for (int i = 0; i < hash->divisor; i++)
	{
		if (hash->data[i] == NULL)
		{
			printf("NULL\n");
		}
		else
		{
			printf("%d %s \n", hash->data[i]->first, hash->data[i]->str);
		}
	}
}
int main()
{
	Hash* hash = createHash(4);
	Data* num = (Data*)calloc(10, sizeof(Data));
	Data h[10] = { { 1, "����" }, { 3, "ԭ��" }, { 4, "��ѧ" }, { 2, "���洦y" }, { 1, "sxsgy" } };
	num = h;
	addHsah(hash, num);
	addHsah(hash, num + 1);
	addHsah(hash, num + 2);
	addHsah(hash, num + 3);
	addHsah(hash, num + 4);
	showHash(hash);
	while (1);
	return 0;
}