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
			printf("������Ϸ\n");
			game();
			menu();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("����������������룡����\n");
			break;
		}
	}
	while (input);
	getch();
	return 0;
}