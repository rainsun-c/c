#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include <assert.h>
#include"LinkStack.h"
#define SPACE  0	//空地
#define WALL   1	//墙
#define DEST   2	//目的地
#define BOX    3	//箱子
#define PLAYER 6	//玩家


//定义一个栈
LinkStack* ls = NULL;

IMAGE k;
typedef struct _Key
{
	int x;		//位置
	int y;
	int width;	//宽
	int height;	//高
	char* str;  //文字
	COLORREF color;//颜色
}Key;
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
	assert(newKey->str != NULL);
	strcpy(newKey->str, str);
	return newKey;
}
void drawKey(Key* key)
{

	setfillcolor(key->color);
	settextstyle(35, 0, "楷体");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(key->x, key->y, key->x + key->width, key->height + key->y);
	outtextxy(key->x + 20, key->y + 10, key->str);
}
void display()
{
	loadimage(&k, "./1.jpg", getwidth(), getheight());
	putimage(0, 0, &k);
	settextcolor(GREEN);
	settextstyle(50, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(230, 100, "推 箱 子");
}

int jugde(Key* key, MOUSEMSG m)
{
	if (m.x >= key->x && m.y >= key->y && m.x < key->x + key->width && m.y < key->y + key->height)
	{
		key->color = RED;
		return 1;
	}
	key->color = YELLOW;
	return 0;
}
//鼠标是否点下去
int click(Key* key, MOUSEMSG m)
{
	if (jugde(key, m) && m.uMsg == WM_LBUTTONDOWN)
	{
		return 1;
	}
	return 0;
}

int initGround()
{
	char str[20] = "开始";
	char str1[20] = "退出";
	Key* key1 = createKey(280, 200, 100, 50, str, YELLOW);
	Key* key2 = createKey(280, 300, 100, 50, str1, YELLOW);
	display();
	drawKey(key1);
	drawKey(key2);
	while (1)
	{
		BeginBatchDraw();
		drawKey(key1);
		drawKey(key2);	
		EndBatchDraw();
		MOUSEMSG m = GetMouseMsg();
		
		if (click(key1, m))
		{
			free(key1);
			free(key2);

			return 1;
		}
		if (click(key2, m))
		{
			return 0;
		}
	
	}
}

int level = 0;
int  map[3][10][10] =
{
{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,0,1,2,1,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,0},
		{0,1,1,1,3,3,0,2,1,0},
		{0,1,2,3,6,0,1,1,1,0},
		{0,1,1,1,1,3,1,0,0,0},
		{0,0,0,0,1,2,1,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,1,1,0,0},
		{0,1,0,0,1,1,0,0,1,0},
		{1,0,2,3,0,0,3,2,0,1},
		{1,0,0,0,6,0,0,0,0,1},
		{0,1,0,0,3,0,0,0,1,0},
		{0,0,1,0,0,3,0,1,0,0},
		{0,0,0,1,2,2,1,0,0,0},
		{0,0,0,0,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,2,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,1,0,0,3,3,0,2,1,0},
		{0,1,2,3,6,0,0,0,1,0},
		{0,1,0,0,0,3,0,0,1,0},
		{0,1,0,0,0,2,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0}
	}

};
IMAGE img_res[6];
void svaeState(int r, int c, int dir);
void rollBack();
void loagImg()
{
	for (int i = 0; i < 6; i++)
	{
		char fileName[20] = "";
		sprintf(fileName, "./images/%d.bmp", i);
		loadimage(img_res + i, fileName);
	}
}
void gameDraw()
{
	char score[10] = "";
	sprintf(score, "第%d关:", level + 1);
	outtextxy(20, 20, score);
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			int x = k * 64;
			int y = i * 64;
			switch (map[level][i][k])
			{
			case SPACE:
				putimage(x, y, img_res);
				break;
			case WALL:
				putimage(x, y, img_res + 1);
				break;
			case DEST:
				putimage(x, y, img_res + 2);
				break;
			case BOX:
				putimage(x, y, img_res + 3);
				break;
			case PLAYER:
				putimage(x, y, img_res + 4);
				break;
			case BOX + DEST:
				putimage(x, y, img_res + 5);
				break;
			case PLAYER + DEST:
				putimage(x, y, img_res + 5);
				break;
			}
		}
	}
}
void move()
{
	int i, k;
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[level][i][k] == PLAYER || map[level][i][k] == PLAYER + DEST)
			{
				goto end;
			}
		}
	}
end:
	char key = _getch();	//返回两次 -32  按键
	if (key != -32 && key != 32)
	{
		svaeState(i, k, key);
	}

	switch (key)
	{
	case 72:
		//玩家的前面是空地
		if (map[level][i - 1][k] == SPACE || map[level][i - 1][k] == DEST)
		{
			map[level][i - 1][k] += PLAYER;
			map[level][i][k] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[level][i - 1][k] == BOX || map[level][i - 1][k] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[level][i - 2][k] == SPACE || map[level][i - 2][k] == DEST)
			{
				map[level][i - 2][k] += BOX;
				map[level][i - 1][k] += (-BOX + PLAYER);
				map[level][i][k] -= PLAYER;
			}
		}
		break;
	case 80:
		//玩家的前面是空地
		if (map[level][i + 1][k] == SPACE || map[level][i + 1][k] == DEST)
		{
			map[level][i + 1][k] += PLAYER;
			map[level][i][k] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[level][i + 1][k] == BOX || map[level][i + 1][k] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[level][i + 2][k] == SPACE || map[level][i + 2][k] == DEST)
			{
				map[level][i + 2][k] += BOX;
				map[level][i + 1][k] += (-BOX + PLAYER);
				map[level][i][k] -= PLAYER;
			}
		}
		break;
	case 75:
		//玩家的前面是空地
		if (map[level][i][k - 1] == SPACE || map[level][i][k - 1] == DEST)
		{
			map[level][i][k - 1] += PLAYER;
			map[level][i][k] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[level][i][k - 1] == BOX || map[level][i][k - 1] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[level][i][k - 2] == SPACE || map[level][i][k - 2] == DEST)
			{
				map[level][i][k - 2] += BOX;
				map[level][i][k - 1] += (-BOX + PLAYER);
				map[level][i][k] -= PLAYER;
			}
		}
		break;
	case 77:
		//玩家的前面是空地
		if (map[level][i][k + 1] == SPACE || map[level][i][k + 1] == DEST)
		{
			map[level][i][k + 1] += PLAYER;
			map[level][i][k] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[level][i][k + 1] == BOX || map[level][i][k + 1] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[level][i][k + 2] == SPACE || map[level][i][k + 2] == DEST)
			{
				map[level][i][k + 2] += BOX;
				map[level][i][k + 1] += (-BOX + PLAYER);
				map[level][i][k] -= PLAYER;
			}
		}
		break;
	case 32:
		rollBack();
		break;
	}
}
//判断地图里面有没有箱子
int Jude()
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (map[level][i][k] == BOX)
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	initgraph(640, 640);
	char str[20] = "开始";
	char str1[20] = "退出";
	Key* key1 = createKey(280, 200, 100, 50, str, YELLOW);
	Key* key2 = createKey(280, 300, 100, 50, str1, YELLOW);
	display();
	drawKey(key1);
	drawKey(key2);
	ls = createLinkStack();
	loagImg();
	int ret = 0;
	HWND hWnd = GetHWnd();
	while (1)
	{
		BeginBatchDraw();
		drawKey(key1);
		drawKey(key2);
		EndBatchDraw();
		MOUSEMSG m = GetMouseMsg();
		if (click(key1, m))
		{
			while (1)
			{
				gameDraw();
				move();
				gameDraw();
				if (Jude() == 1)
				{
					level++;
					while (!empty(ls))
					{
						pop(ls);
					}
					if (level < 3)
					{
						ret = MessageBox(hWnd, "是否继续", "推箱子", MB_OKCANCEL);
						if (ret != IDOK)
						{
							break;
						}
					}
					else
					{
						ret = MessageBox(hWnd, "恭喜通关", "推箱子", MB_OK);
						if (ret == IDOK)
						{
							exit(666);
						}
					}
				}
			}
		}

		if (click(key2, m))
		{
			return 0;
		}
	}
	closegraph();
	system("pause");
	return 0;
}

void svaeState(int r, int c, int dir)
{
	State t;
	memset(&t, 0, sizeof(State));
	switch (dir)
	{
	case 72:
		for (int i = 0; i < 3; i++)
		{
			t.pos[i].r = r - i;	//3 2 1 
			t.pos[i].c = c;
			t.pos[i].dada = map[level][t.pos[i].r][t.pos[i].c];
		}
		break;
	case 80:
		for (int i = 0; i < 3; i++)
		{
			t.pos[i].r = r + i;
			t.pos[i].c = c;
			t.pos[i].dada = map[level][t.pos[i].r][t.pos[i].c];
		}
		break;
	case 75:
		for (int i = 0; i < 3; i++)
		{
			t.pos[i].r = r;
			t.pos[i].c = c - i;
			t.pos[i].dada = map[level][t.pos[i].r][t.pos[i].c];
		}
		break;
	case 77:
		for (int i = 0; i < 3; i++)
		{
			t.pos[i].r = r;
			t.pos[i].c = c + i;
			t.pos[i].dada = map[level][t.pos[i].r][t.pos[i].c];
		}
		break;
	}
	//入栈
	push(ls, t);//error C2664: “void push(LinkStack *,Data)”: 无法将参数 2 从“State”转换为“Data”
}
void rollBack()
{
	if (empty(ls))
		return;
	State t = top(ls);
	for (int i = 0; i < 3; i++)
	{
		map[level][t.pos[i].r][t.pos[i].c] = t.pos[i].dada;
	}
	pop(ls);
}