#include "snake.h"

//���ù��
void SetConsorCursorPosition(int x, int y)
{
	COORD pos = { x,y };//�ṹ��
	//��ȡ����̨
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
//��Ϸ����
void welcome()
{
	SetConsoleTitle(L"̰����");
	system("mode con cols=100 lines=30");
	SetConsorCursorPosition(40, 15);
	printf("��ӭ����\n");
	system("pause");
	system("cls");
	setPlayGame();
}

//��Ϸ�߿�
void setPlayGame()
{
	for (int i = 0; i < 58; i += 2)
	{
		SetConsorCursorPosition(i, 0);
		printf("��");//ռ2��
		SetConsorCursorPosition(i, 26);
		printf("��");
	}
	for (int i = 0; i < 26; i++)
	{
		SetConsorCursorPosition(0, i);
		printf("��");
		SetConsorCursorPosition(56, i);
		printf("��");
	}
}
//��������
void dScore()
{
	SetConsorCursorPosition(65, 15);
	printf("�÷�:%d �� ", g_socre);
	SetConsorCursorPosition(65, 16);
	printf("�ٶ�Ϊ%d",speed);
}
//�����߽��
Snake* createSnakeNode(int x,int y)
{
	Snake* snake = (Snake*)malloc(sizeof(Snake));
	assert(snake!=NULL);
	snake->next = NULL;
	snake->x = x;
	snake->y = y;
	return snake;
}
//ͷ��
void insertSnake(Snake** snake,int x,int y)
{
	Snake* newSnakeNode=createSnakeNode(x, y);
	newSnakeNode->next = *snake;
	*snake = newSnakeNode;
}
//��
void createSnake(Snake* snakeFront)
{
	for (int i = 1; i <= 3; i++)
	{
		insertSnake(&snakeFront, 20+i*2, 13);
	}
	printSnake(snakeFront);
}
//ɾ����β��βɾ��
void deletTailSnake(Snake** snake)

{
	Snake* newNode = (*snake);
	Snake* newNodet = newNode->next;

		while (newNodet->next)
		{
			newNode = newNodet;
			newNodet = newNode->next;
		}
		newNode->next = newNodet->next;
		SetConsorCursorPosition(newNodet->x, newNodet->y);
		printf("  ");
		free(newNodet);
		newNodet = NULL;
}
////�ߵ��ƶ�
//void moveSnake(Snake* snake, int ch)
//{
//	int x = 0, y = 0;
//	switch (ch)
//	{
//	case 72:			//��
//		y = snake->y - 1;
//		x = snake->x;
//		break;
//	case 80:			//��
//		y = snake->y + 1;
//		x = snake->x;
//		break;
//	case 75:			//��
//		y = snake->y;
//		x = snake->x - 2;
//		break;
//	case 77:			//��
//		y = snake->y;
//		x = snake->x + 2;
//		break;
//	}
//	insertSnake(&snake,x,y);
//	deletTailSnake(&snake);
//	printSnake(snake);
//}
////������
//void controlSnake(Snake* snakeFront)
//{
//	int ch=0;
//	while (1)
//	{
//		if (_kbhit())
//		{
//			getch();
//			ch = _getch();
//		}
//		if(ch!=0)
//		moveSnake(snakeFront ch);
//	}
//
//}
//��ӡ��
void printSnake(Snake* snake)
{
	Snake* pMove = snake;
	while (pMove)
	{
		SetConsorCursorPosition(pMove->x, pMove->y);
		printf("��");
		pMove = pMove->next;
	}
	SetConsorCursorPosition(20,14);
}

//����ʳ��
void createFood(Snake* snakeFront)
{
	while (1)
	{
		int t = 1;
		int xx = rand() % 54 + 2;
		int x = xx % 2 ? xx - 1 : xx;
		int y = rand() % 24 + 1;
		Snake* pMove = snakeFront;
		while (pMove)
		{
			if (pMove->x == x && pMove->y == y)
			{
				t = 0;
				break;
			}
			pMove = pMove->next;
		}
		if (t == 1)
		{
			food.x = x;
			food.y = y;
			SetConsorCursorPosition(food.x, food.y);
			printf("��");
			break;
		}
	}

}
//�ж�
int judge(Snake* snakeFront)
{
	if (snakeFront->x == 56 || snakeFront->y == 1 || snakeFront->x == 2 || snakeFront->y == 25)
	{
		MessageBox(NULL, L"shibai", L"sgsghs", MB_OKCANCEL);
		return 1;
	}
	
	Snake* pMove = snakeFront->next;
	while (pMove)
	{
		if (pMove->x == snakeFront->x && pMove->y == snakeFront->y)
		{
			return 1;
		}
	}
	return 0;
}
//���ع��
void hideCursor()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ȡ���
	CONSOLE_CURSOR_INFO c;
	GetConsoleCursorInfo(h,&c);
	c.bVisible = FALSE;
	SetConsoleCursorInfo(h,&c);
}
int main()
{
	hideCursor();
	Snake* snakeFront = createSnakeNode(20, 13);
	srand((unsigned)time(NULL));
	welcome();
	
	//createSnake(snakeFront);
	for (int i = 1; i <= 3; i++)
	{
		insertSnake(&snakeFront, 20 + i * 2, 13);
	}
	printSnake(snakeFront);
	//
	int ch = 0;
	createFood(snakeFront);
	while (1)
	{
		dScore();
		/*	controlSnake(snakeFront);*/
		int x = 0, y = 0;
		if (_kbhit())
		{
			ch=getch();
			ch = _getch();
		}
		if (ch ==72||ch==80||ch==75||ch==77)
		{
			switch (ch)
			{
			case 72:			//��
				y = (snakeFront)->y - 1;
				x = snakeFront->x;
				break;
			case 80:			//��
				y = snakeFront->y + 1;
				x = snakeFront->x;
				break;
			case 75:			//��
				y = snakeFront->y;
				x = snakeFront->x - 2;
				break;
			case 77:			//��
				y = snakeFront->y;
				x = snakeFront->x + 2;
				break;
				
			}
			insertSnake(&snakeFront, x, y);
			deletTailSnake(&snakeFront);
			printSnake(snakeFront);
			Sleep(200-speed);
		}
		if (snakeFront->x == 56 || snakeFront->y == 1 || snakeFront->x == 2 || snakeFront->y == 25)
		{

			MessageBox(NULL, L"��Ϸʧ��", L"̰����", MB_OKCANCEL);
			break;
		}
		int b = 0;
		Snake* pMove = snakeFront->next;
		while (pMove)
		{
			if (pMove->x == snakeFront->x && pMove->y == snakeFront->y)
			{
				b = 1;
			}
			pMove = pMove->next;
		}
		if (b == 1)
		{
			break;
		}

		if (snakeFront->x == food.x && snakeFront->y == food.y)
		{
			insertSnake(&snakeFront, food.x, food.y);
			createFood(snakeFront);
			g_socre += 10;
			speed += 50;
		}
	}
	while (1);
	return 0;
}