#include "GoldMiner.h"


void init_IMAGE()//加载图片
{
	for (int i = 0; i < 10; i++)
	{
		char str[1020] = "";
		sprintf_s(str, "./%d.jpg", i);
		loadimage(img+i,str);
	}
	loadimage(img + 10, "./bk.jpg", getwidth(), getheight());
}
void chartlet()//贴图
{
	cleardevice();
	putimage(0, 120, img + 10);//背景
	switch ((role->w)+1)//角色上下转动
	{
	case 1:
		putimage(role->x, role->y, img + 6);
		putimage(role->x, role->y, img + 7);
		break;
	case 2:
		putimage(role->x, role->y, img + 4);
		putimage(role->x, role->y, img + 5);
		break;
	}
	//钩子的绘制
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID,5);
	line((int)hook->x, (int)hook->y, (int)hook->enx, (int)hook->endy);
	solidcircle((int)hook->enx, (int)hook->endy, 5);
	//物品的绘制
	for (int i = 0; i < Stuff_Max; i++)
	{
		if (stuf[i].exsit == true)
		{
			switch (stuf[i].type)
			{
			case 0://金块
				putimage((int)stuf[i].place_x, (int)stuf[i].plaxe_y, img, SRCAND);
				putimage((int)stuf[i].place_x, (int)stuf[i].plaxe_y, img + 1, SRCPAINT);
				stuf[i].worth=5;//物品价值
				break;
			case 1://钱袋
				putimage((int)stuf[i].place_x, (int)stuf[i].plaxe_y, img + 2, SRCAND);
				putimage((int)stuf[i].place_x, (int)stuf[i].plaxe_y, img + 3, SRCPAINT);
				stuf[i].worth = 10;
				break;
			case 2://石头
				putimage((int)stuf[i].place_x, (int)stuf[i].plaxe_y, img + 8, SRCAND);
				putimage((int)stuf[i].place_x, (int)stuf[i].plaxe_y, img + 9, SRCPAINT);
				stuf[i].worth = 1;
				break;
			}
		}
		
	}
	//分数绘制
	char str[30] = "";
	sprintf(str, "分数：%d", score);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, "楷体");
	outtextxy(20, 20, str);
}
void init_role()//角色初始化
{
	role->height = 120;
	role->width = 140;
	role->x = (getwidth() - role->width)/2;//居中
	role->y = 0;
	role->w= 0;
}
bool size_line(Hook* hook)//求当前线的长度
{
	double size= sqrt((hook->enx - hook->x)*(hook->enx - hook->x) + (hook->endy - hook->y)*(hook->endy - hook->y));
	return size <= hook->len;
}
void init_stste()//初始化钩子
{
	hook->len = 50;
	hook->x = getwidth() / 2 -25;
	hook->y = role->height / 2 +35;
	hook->enx = hook->x;
	hook->endy = hook->y + hook->len;
	hook->angle = 0;
	hook->state = nomal;
	hook->vx = 0;
	hook->vy = 0;
	hook->index = -1;
}
void swing(int angle)//摆动
{
	if (hook->state == nomal)//正常状态下时转动，伸缩时不转
	{
		hook->endy = cos(PI / 180 * hook->angle)*hook->len + hook->y;
		hook->enx = sin(PI / 180 * hook->angle)*hook->len + hook->x;
		if (hook->angle > 80)
		{
			hook->dir = left;
		}
		else if (hook->angle< -80)
		{
			hook->dir = right;
		}

		if (hook->dir == right)
		{
			hook->angle += angle ;
		}
		else
		{
			hook->angle -= angle ;
		}
	}
}
void stuff()//物品
{
	//用随机数生成物品位置
	for (int i = 0; i < Stuff_Max; i++)
	{
		stuf[i].size = 50;
		stuf[i].place_x = rand() % (getwidth() - stuf[i].size);
		stuf[i].plaxe_y = rand() % (getheight() -150 ) + 150;	
		stuf[i].type = rand() % 3;
		stuf[i].exsit = true;
	}
}
void flex(int speed)//伸缩
{
	if ( GetAsyncKeyState(VK_SPACE ))//伸长
	{
		
		hook->state = extend;
		hook->vy = cos(PI / 180 * hook->angle)*speed;
		hook->vx = sin(PI / 180 * hook->angle)*speed;
	}
	if (hook->state == extend)
	{
		hook->endy += hook->vy;
		hook->enx += hook->vx;
		role->w++;
	}
	else if (hook->state == shorten)
	{
		hook->endy -= hook->vy;
		hook->enx -= hook->vx;
		if (size_line(hook))
		{
			hook->state = nomal;
		}
		role->w++;//角色上下转动
	}
	//边界
	if (( hook->enx >= getwidth() || hook->enx <= 0 ) || ( hook->endy >= getheight() || hook->endy <= 0 ))
	{
		hook->state = shorten;
	}
}
void grab()//抓取
{
	for (int i = 0; i < Stuff_Max; i++)
	{
		//根据图片大小来决定在哪个范围抓取
		if (stuf[i].type ==0 )
		{
			if ((stuf[i].exsit == true && hook->enx < (stuf[i].place_x + 100) && hook->enx < stuf[i].place_x+80) && (hook->endy < (stuf[i].plaxe_y + 90) && hook->endy < stuf[i].plaxe_y+70))
			{
				hook->index = i;
				break;
			}
		}
		if (stuf[i].type == 1||stuf[i].type==2 )
		{
			if ((stuf[i].exsit == true && hook->enx < (stuf[i].place_x + 47) && hook->enx < stuf[i].place_x + 27) && (hook->endy < (stuf[i].plaxe_y +43) && hook->endy < stuf[i].plaxe_y + 23))
			{
				hook->index = i;
				break;
			}
		}
	}
	if (hook->index != -1)
	{
		hook->state = shorten;//缩短
		stuf[hook->index].place_x = hook->enx-30;
		stuf[hook->index].plaxe_y = hook->endy-30;
		
		if (size_line(hook))
		{
			score += stuf[hook->index].worth;//统计分数
			stuf[hook->index].exsit = false;
			hook->index = -1;
			hook->state = nomal;//缩短
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	initgraph(1080, 640);
	init_role();//初始化角色
	init_stste();//初始化钩子
	stuff();//物品
	init_IMAGE();//加载图片
	BeginBatchDraw();//双缓冲
	while (1)
	{
		chartlet();//贴图
		FlushBatchDraw();//双缓冲
		flex(1);//伸缩
		swing(1);//摆动
		grab();//抓取
	}
	while (1);
	return 0;
}
