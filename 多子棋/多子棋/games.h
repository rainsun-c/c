#define Wide 3
#define High 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game();//游戏主程序
void menu();//游戏菜单
void Initianlization(char Lattice[][High], int wide, int high);//初始化
void people(char Lattice[][High] , int wide, int high);//人操作
void print(char Lattice[][High], int wide, int high);//打印地图
void camoputer(char Lattice[][High], int wide, int high);//电脑操作
char judgement(char Lattice[][High], int wide, int high);//判断结果
int judg(char Lattice[][High], int wide, int high);