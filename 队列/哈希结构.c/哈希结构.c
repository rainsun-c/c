#define _CRT_SECURE_NO_WARNINGS

#define hash_count 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//哈希结构是无序的，随机存储结构， 特定的关系
/*
数据和地址的映射关系->函数关系，
数学中的函数关系
把数据充当地址 y(x)=x（直接定值法）抽象地址不是真正的地址，例如：数组下标（可以充当地址）;
缺点：浪费内存，例如数据是100，那就要放到100的地址位置

取余法（常用）：哈希地址个数大于元素个数
y=x%10;

哈希冲突：原来地址是有元素的，
解决办法：
1、开发地址法：把没有开放的地址给它存数据。数组哈希
2、数组链表：以该元素，为头开辟链表。

链式哈希（有序链表）=跳表
*/
typedef struct _Data
{
	int first;
	char str[20];
}Data;
typedef struct hashtable
{
	Data** data;
	int divisor;     //取余法
	int hash_size;
}Hash;
Hash* createHash(int num)//创建哈市表
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
void addHsah(Hash* hash, Data* data)//添加
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
			printf("满了\n");
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
	Data h[10] = { { 1, "赛号" }, { 3, "原神" }, { 4, "数学" }, { 2, "法规处y" }, { 1, "sxsgy" } };
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