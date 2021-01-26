#include <iostream>
#include <graphics.h>
#include <mmsystem.h>
#include <string>
#pragma comment (lib,"winmm.lib")
using namespace std;
class Key
{
public:
	Key(int x, int y, int wide, int high, string str, COLORREF color)
	{
		this->color = color;
		this->height = high;
		this->width = wide;
		this->x = x;
		this->y = y;
		this->str = str;
	}
	void drawKey()
	{
		setfillcolor(this->color);
		settextstyle(35, 0, "楷体");
		setlinecolor(BLACK);
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		fillrectangle(this->x, this->y, this->x + this->width, this->height + this->y);
		outtextxy(this->x + 20, this->y + 10, this->str.c_str());//加上.c_str()
	}
	int jugde(MOUSEMSG m)
	{
		if (m.x >= this->x&&m.y >= this->y&&m.x < this->x + this->width&&m.y < this->y + this->height)
		{
			this->color = RED;
			return 1;
		}
		this->color = YELLOW;
		return 0;
	}
	int click( MOUSEMSG m)
	{
		if (jugde(m) && m.uMsg == WM_LBUTTONDOWN)
		{
			return 1;
		}
		return 0;
	}
	COLORREF& getcolor()
	{
		return color;
	}
protected:
	int x;		//位置
	int y;
	int width;	//宽
	int height;	//高
	string str;  //文字
	COLORREF color;//颜色
};
//rectangle(x,y,xx,yy)

//绘制按键


int main()
{
	initgraph(800, 600);
	IMAGE img;
	Key* key1 = new Key(200, 200, 180, 50, "开始", YELLOW);
	Key* key2 = new Key(200, 250, 180, 50, "暂停", YELLOW);
	Key* key3 = new Key(200, 300, 180, 50, "继续", YELLOW);
	Key* key4 = new Key(200, 350, 180, 50, "关闭", YELLOW);
	loadimage(&img, "./1.jpg", 800, 600);
	putimage(0, 0, &img);
	while (1)
	{
		key1->drawKey();
		key2->drawKey();
		key3->drawKey();
		key4->drawKey();
		MOUSEMSG m = GetMouseMsg();
		BeginBatchDraw();
		if (key1->click(m))
		{
			mciSendString("open 1.mp3", 0, 0, 0);
			mciSendString("play 1.mp3", 0, 0, 0);
		}
		if (key2->click(m))
		{
			mciSendString("pause 1.mp3", 0, 0, 0);
		}
		if (key3->click(m))
		{
			mciSendString("resume 1.mp3", 0, 0, 0);
		}
		if (key4->click(m))
		{
			mciSendString("close 1.mp3", 0, 0, 0);

		}
		EndBatchDraw();
	}
	closegraph();
	while (1);
	return 0;
}