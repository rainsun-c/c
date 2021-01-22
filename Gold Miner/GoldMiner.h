#pragma once
#define Stuff_Max 8  //物品数量
#define PI 3.1426926
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
IMAGE img[12];       //定义12张图片
using namespace std;
enum state
{
	extend,//伸长
	shorten,//缩短
	nomal,//正常
	left,//左
	right,//右
};
typedef struct _Role//角色
{
	int x;//位置
	int y;
	int width;//角色宽度
	int height;//角色高度
	byte w :1;//角色上，下控制
}Role;
typedef struct _Hook//钩子
{
	double x;//钩子开始坐标
	double y;
	double enx;//钩子结束坐标
	double endy;
	double angle;//钩子转动角度
	double vx;   //速度分量（伸长是以什么速度增长）
	double vy;
	int state;//状态
	int dir;//方向
	double len;//钩子长度
	int index;//抓到物品号数
}Hook;
typedef struct _Stuff//物品
{
	int size;      //物品大小
	double place_x;//位置指标
	double plaxe_y;
	int type;      //类型
	bool exsit;	   //是否存在
	int worth;     //物品价值
}stf;
Role* role = (Role*)calloc(1, sizeof(Role));//创建角色
Hook* hook = (Hook*)calloc(1, sizeof(Hook));//创建钩子
stf stuf[Stuff_Max];//创建物品
int score = 0;//统计分数
void init_IMAGE();//加载图片
void chartlet();//贴图
void init_role();//角色初始化
void init_stste();//钩子初始化
void swing(double angle);//钩子的摆动
void flex(double speed);//钩子的伸缩
void grab();//抓取物品的判断