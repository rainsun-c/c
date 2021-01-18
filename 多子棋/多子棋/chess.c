#define _CRT_SECURE_NO_WARNINGS

#include "games.h"
int main()
{
	int input = 0;
	menu();
	srand((unsigned int)time(NULL));
	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("进入游戏\n");
			game();
			menu();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误请重新输入！！！\n");
			break;
		}
	}
	while (input);
	getch();
	return 0;
}