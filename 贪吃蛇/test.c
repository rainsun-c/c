#include "snake.h"

//设置光标
void SetConsorCursorPosition(int x, int y)
{
	COORD pos = { x,y };//结构体
	//获取控制台
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
//游戏界面
void welcome()
{
	SetConsoleTitle(L"贪吃蛇");
	system("mode con cols=100 lines=30");
	SetConsorCursorPosition(40, 15);
	printf("欢迎进入\n");
	system("pause");
	system("cls");
	setPlayGame();
}

//游戏边框
void setPlayGame()
{
	for (int i = 0; i < 58; i += 2)
	{
		SetConsorCursorPosition(i, 0);
		printf("■");//占2格
		SetConsorCursorPosition(i, 26);
		printf("■");
	}
	for (int i = 0; i < 26; i++)
	{
		SetConsorCursorPosition(0, i);
		printf("■");
		SetConsorCursorPosition(56, i);
		printf("■");
	}
}
//文字设置
void dScore()
{
	SetConsorCursorPosition(65, 15);
	printf("得分:%d 分 ", g_socre);
	SetConsorCursorPosition(65, 16);
	printf("速度为%d",speed);
}
//创建蛇结点
Snake* createSnakeNode(int x,int y)
{
	Snake* snake = (Snake*)malloc(sizeof(Snake));
	assert(snake!=NULL);
	snake->next = NULL;
	snake->x = x;
	snake->y = y;
	return snake;
}
//头插
void insertSnake(Snake** snake,int x,int y)
{
	Snake* newSnakeNode=createSnakeNode(x, y);
	newSnakeNode->next = *snake;
	*snake = newSnakeNode;
}
//蛇
void createSnake(Snake* snakeFront)
{
	for (int i = 1; i <= 3; i++)
	{
		insertSnake(&snakeFront, 20+i*2, 13);
	}
	printSnake(snakeFront);
}
//删除蛇尾（尾删）
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
////蛇的移动
//void moveSnake(Snake* snake, int ch)
//{
//	int x = 0, y = 0;
//	switch (ch)
//	{
//	case 72:			//上
//		y = snake->y - 1;
//		x = snake->x;
//		break;
//	case 80:			//下
//		y = snake->y + 1;
//		x = snake->x;
//		break;
//	case 75:			//左
//		y = snake->y;
//		x = snake->x - 2;
//		break;
//	case 77:			//右
//		y = snake->y;
//		x = snake->x + 2;
//		break;
//	}
//	insertSnake(&snake,x,y);
//	deletTailSnake(&snake);
//	printSnake(snake);
//}
////控制蛇
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
//打印蛇
void printSnake(Snake* snake)
{
	Snake* pMove = snake;
	while (pMove)
	{
		SetConsorCursorPosition(pMove->x, pMove->y);
		printf("■");
		pMove = pMove->next;
	}
	SetConsorCursorPosition(20,14);
}

//生成食物
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
			printf("★");
			break;
		}
	}

}
//判断
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
//隐藏光标
void hideCursor()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//获取光标
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
			case 72:			//上
				y = (snakeFront)->y - 1;
				x = snakeFront->x;
				break;
			case 80:			//下
				y = snakeFront->y + 1;
				x = snakeFront->x;
				break;
			case 75:			//左
				y = snakeFront->y;
				x = snakeFront->x - 2;
				break;
			case 77:			//右
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

			MessageBox(NULL, L"游戏失败", L"贪吃蛇", MB_OKCANCEL);
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