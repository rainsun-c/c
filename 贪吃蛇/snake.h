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
//��Ϸ����
void welcome();
//���ù��
void SetConsorCursorPosition(int x, int y);
//��Ϸ�߿�
void setPlayGame();
//��������
void dScore();
//�����߽��
Snake* createSnakeNode(int x, int y);
//ͷ��
void insertSnake(Snake** snake, int x, int y);
//��
void createSnake(Snake* snakeFront);
//��ӡ��
void printSnake(Snake* snake);
//�ߵ��ƶ�
//void moveSnake(Snake* snake, int x);
//ɾ����β��βɾ��
void deletTailSnake(Snake** snake);
//������
//void controlSnake(Snake** snake);
////�ߵ��ƶ�
//void moveSnake(Snake* snake, int ch);
//����ʳ��
void createFood(Snake* snakeFront);
//�ж�
int judge(Snake* snakeFront);
//���ع��
void hideCursor();