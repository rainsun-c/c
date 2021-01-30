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

//数据
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
//计数
int  count(char* str)
{
	int i = 0;
	while (str=strstr(str+4,"----"))
	{ //strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
	  //如果是，则该函数返回 str1字符串从 str2第一次出现的位置开始到 str1结尾的字符串
		i++;
	}
	return i;
}
//初始化结构
void init()
{
	userInfos.size = count(strt);
	userInfos.base = (struct Info*)malloc(sizeof(struct Info)*userInfos.size);
	assert(userInfos.base != NULL);
}
//分割并存储
void SeData(char* str)
{
	//先将把数据一个一个分割出来
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
	//再将每个数据的账号和密码分别分割出来
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
		strcpy(userInfos.base[index].passwd, subp + 4);//格式化输入
		px = px + strlen(px) + 1;//上字符串的长度（包括\0）
	}
}
//显示
void show()
{
	printf("QQ号\t\t密码\n");
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