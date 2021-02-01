#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include <conio.h>
#include <time.h>


unsigned int speed = 0;
unsigned int g_socre = 0;
typedef struct _Food
{
	int x;
	int y;
}Food;
typedef struct _Snake
{
	int x;
	int y;
	struct _Snake* next;
}Snake;
Food food = { 0 };
//游戏界面
void welcome();
//设置光标
void SetConsorCursorPosition(int x, int y);
//游戏边框
void setPlayGame();
//文字设置
void dScore();
//创建蛇结点
Snake* createSnakeNode(int x, int y);
//头插
void insertSnake(Snake** snake, int x, int y);
//蛇
void createSnake(Snake* snakeFront);
//打印蛇
void printSnake(Snake* snake);
//蛇的移动
//void moveSnake(Snake* snake, int x);
//删除蛇尾（尾删）
void deletTailSnake(Snake** snake);
//控制蛇
//void controlSnake(Snake** snake);
////蛇的移动
//void moveSnake(Snake* snake, int ch);
//生成食物
void createFood(Snake* snakeFront);
//判断
int judge(Snake* snakeFront);
//隐藏光标
void hideCursor();