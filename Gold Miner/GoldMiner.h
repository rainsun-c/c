#pragma once
#define Stuff_Max 8  //��Ʒ����
#define PI 3.1426926
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
IMAGE img[12];       //����12��ͼƬ
using namespace std;
enum state
{
	extend,//�쳤
	shorten,//����
	nomal,//����
	left,//��
	right,//��
};
typedef struct _Role//��ɫ
{
	int x;//λ��
	int y;
	int width;//��ɫ���
	int height;//��ɫ�߶�
	byte w :1;//��ɫ�ϣ��¿���
}Role;
typedef struct _Hook//����
{
	double x;//���ӿ�ʼ����
	double y;
	double enx;//���ӽ�������
	double endy;
	double angle;//����ת���Ƕ�
	double vx;   //�ٶȷ������쳤����ʲô�ٶ�������
	double vy;
	int state;//״̬
	int dir;//����
	double len;//���ӳ���
	int index;//ץ����Ʒ����
}Hook;
typedef struct _Stuff//��Ʒ
{
	int size;      //��Ʒ��С
	double place_x;//λ��ָ��
	double plaxe_y;
	int type;      //����
	bool exsit;	   //�Ƿ����
	int worth;     //��Ʒ��ֵ
}stf;
Role* role = (Role*)calloc(1, sizeof(Role));//������ɫ
Hook* hook = (Hook*)calloc(1, sizeof(Hook));//��������
stf stuf[Stuff_Max];//������Ʒ
int score = 0;//ͳ�Ʒ���
void init_IMAGE();//����ͼƬ
void chartlet();//��ͼ
void init_role();//��ɫ��ʼ��
void init_stste();//���ӳ�ʼ��
void swing(double angle);//���ӵİڶ�
void flex(double speed);//���ӵ�����
void grab();//ץȡ��Ʒ���ж�