

#define _CRT_SECURE_NO_WARNINGS
#include "games.h"

void menu()
{
	printf("*************多子棋*************\n");
	printf("********1 begin   0 exit********\n");
	printf("********************************\n");
}
void people(char Lattice[][High], int wide, int high)//人操作
{
		int x = 0;
		int y = 0;
		while (1)
		{	printf("请输入坐标！！！x,y\n");
			scanf("%d,%d", &x, &y);
			if (x >= 1 && x <= wide&&y >= 0 && y <= high)
			{
				if (Lattice[x - 1][y - 1] == ' ')
				{
					Lattice[x - 1][y - 1] = '*';
					break;
				}
				else
				{
					printf("重新输入，此格已经被占用\n");
				}
			}
			else
			{
				printf("输入错误！！！重新输入\n");
			}
		}
}

void Initianlization(char Lattice[Wide][High], int wide, int high)//初始化
{
	int i = 0;
	int j = 0;
	int z = 0;
	for (i = 0; i < wide; i++)
	{
		for (j = 0; j < high; j++)
		{
			Lattice[i][j] = ' ';//九宫格用空格填充
		}
	}
}
void print(char Lattice[][High], int wide, int high)
{
	int i = 0;
	int j = 0;
	int z = 0;
	//打印地图
	for (i = 0; i < wide; i++)
	{
		for (j = 0; j < high; j++)
		{
			printf(" %c ", Lattice[i][j]);
			if (j < high - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < wide - 1)
		{
			for (z = 0; z < wide; z++)
			{
				printf("---");
				if (z < wide - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void camoputer(char Lattice[][High], int wide, int high)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % wide;
		y = rand() % high;
		if (x >= 0 && x < wide&&y >= 0 && y < high&&Lattice[x][y] == ' ')
		{

			Lattice[x][y] = '#';
			break;
		}
	}
}
int judg(char Lattice[][High], int wide, int high)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < wide; i++)
	{
		for (j = 0; j < high; j++)
		{
			if (Lattice[i][j] == ' ')
			{
				return 0;
			}
				
		}
	}
	return 1;
}
	void game()
	{
		char a='0';
		char Lattice[Wide][High] = { 0 };
		Initianlization(Lattice, Wide, High);//初始化
		print(Lattice, Wide, High);
		while (1)
		{
			people(Lattice, Wide, High);
			print(Lattice, Wide, High);
	        a=judgement(Lattice, Wide, High);
			if (a != 'c')
			{
				break;
			}
			camoputer(Lattice, Wide, High);
			print(Lattice, Wide, High);
			a=judgement(Lattice, Wide, High);
			if (a != 'c')
			{
				break;
			}

		}
		if (a == '*')
		{
			printf("winner is player\n");
		}
		if (a == '#')
		{
			printf("winner is computer\n");
		}
		if (a == 'q')
		{
			printf("no winner\n");
		}
	}
char judgement(char Lattice[][High], int wide, int high)//三子棋
	{
		int i = 0;
		for (i = 0; i < wide; i++)
		{
			if (Lattice[i][0] == Lattice[i][1] && Lattice[i][2] == Lattice[i][1] && Lattice[i][1] != ' ')
			{
				return Lattice[i][1];
			}
		}
		for (i = 0; i < wide; i++)
		{
			if (Lattice[0][i] == Lattice[1][i] && Lattice[2][i] == Lattice[1][i] && Lattice[1][i] != ' ')
			{
				return Lattice[1][i];
			}
		}
		if (Lattice[0][0] == Lattice[1][1] && Lattice[2][2] == Lattice[1][1] && Lattice[1][1] != ' ')
		{
			return Lattice[1][1];
		}
		if (Lattice[0][2] == Lattice[1][1] && Lattice[2][0] == Lattice[1][1] && Lattice[1][1] != ' ')
		{
			return Lattice[1][1];
		}
			if (1 == judg(Lattice, Wide, High))
			{
				return 'q';//平均
			}
			return 'c';//继续
		}
	
//char judgement(char Lattice[][High], int wide, int high)
//	{
//		int i = 0;
//		int j = 0;
//		int counts = 0;
//		for (i = 0; i < wide; i++)//行
//		{
//			for (j = 0; j < high; j++)
//			{
//				if (Lattice[i][j] != Lattice[i][high - 1])
//				{
//					break;
//				}
//				counts++;
//				if (counts == wide)
//				{
//					return Lattice[i][0];
//				}
//			}
//			counts = 0;
//		}
//
//		for (j = 0; j < high; j++)
//		{
//			for (i = 0; i < wide ; i++)
//			{
//				if (Lattice[i][j] != Lattice[i][wide - 1])
//				{
//					break;
//				}
//				counts++;
//				if (counts == wide)
//				{
//					return Lattice[i][0];
//				}
//			}
//			counts = 0;
//		//}		
//		for (i = 0, j = 0; i < wide, j < high; i++, j++)
//		{
//			if (Lattice[i][j] != Lattice[wide - 1][high - 1])
//				{
//				break;
//				}
//				counts++;
//				if (counts == wide)
//				{		
//				return Lattice[0][0];
//				}
//			counts=0;
//		}
//		for (i = 0, j = wide-1; i < high, j >=0; i++, j--)
//		{
//			if (Lattice[i][j] != Lattice[wide - 1][0])
//			{
//				break;
//			}
//			counts++;
//			if (counts == wide)
//			{
//				return Lattice[wide-1][0];
//			}
//			counts++;
//		}
//		if (1 == judg(Lattice, Wide, High))
//		{
//			return 'q';//平均
//		}
//		return 'c';//继续
//
//}