#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <assert.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
typedef struct _Key
{
	int x;		//λ��
	int y;		
	int width;	//��
	int height;	//��
	char* str;  //����
	COLORREF color;//��ɫ
}Key;
//rectangle(x,y,xx,yy)
//��������
Key* createKey(int x, int y, int wide, int high, char* str, COLORREF color)
{
	Key* newKey = (Key*)malloc(sizeof(Key));
	assert(newKey != NULL);
	newKey->color = color;
	newKey->height = high;
	newKey->width = wide;
	newKey->x = x;
	newKey->y = y;
	newKey->str = (char*)malloc(strlen(str) + 1);
	assert(newKey->str!=NULL);
	strcpy(newKey->str,str);
	return newKey;
}
//���ư���
void drawKey(Key* key)
{
	
	setfillcolor(key->color);
	settextstyle(35,0,"����");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(key->x, key->y, key->x + key->width, key->height + key->y);
	outtextxy(key->x + 20, key->y + 10, key->str);
}
//�ж�����ǲ����������Χ
int jugde(Key* key, MOUSEMSG m)
{
	if (m.x >= key->x&&m.y >= key->y&&m.x < key->x + key->width&&m.y < key->y + key->height)
	{
		key->color = RED;
		return 1;
	}
	key->color = YELLOW;
	return 0;
}
//����Ƿ����ȥ
int click(Key* key, MOUSEMSG m)
{
	if (jugde(key, m) && m.uMsg == WM_LBUTTONDOWN)
	{
		return 1;
	}
	return 0;
}
int main()
{
	initgraph(800,600);
	IMAGE img;
	Key* key1 = createKey(200, 200, 180, 50, "��ʼ", YELLOW);
	Key* key2 = createKey(200, 250, 180, 50, "��ͣ", YELLOW);
	Key* key3 = createKey(200, 300, 180, 50, "����", YELLOW);
	Key* key4 = createKey(200, 350, 180, 50, "�ر�", YELLOW);
	loadimage(&img, "./1.jpg", 800, 600);
	putimage(0,0,&img);
	while (1)
	{
		drawKey(key1);
		drawKey(key2);
		drawKey(key3);
		drawKey(key4);
		MOUSEMSG m=GetMouseMsg();
		BeginBatchDraw();
		if (click(key1, m))
		{
			mciSendString("open 1.mp3",0,0,0);
			mciSendString("play 1.mp3",0,0,0);
		}
		if (click(key2, m))
		{
			mciSendString("pause 1.mp3", 0, 0, 0);
		}
		if (click(key3, m))
		{
			mciSendString("resume 1.mp3", 0, 0, 0);
		}
		if (click(key4, m))
		{
			mciSendString("close 1.mp3", 0, 0, 0);

		}
		drawKey(key1);
		EndBatchDraw();
	}
	closegraph();
	while (1);
	return 0;
}