#define Wide 3
#define High 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game();//��Ϸ������
void menu();//��Ϸ�˵�
void Initianlization(char Lattice[][High], int wide, int high);//��ʼ��
void people(char Lattice[][High] , int wide, int high);//�˲���
void print(char Lattice[][High], int wide, int high);//��ӡ��ͼ
void camoputer(char Lattice[][High], int wide, int high);//���Բ���
char judgement(char Lattice[][High], int wide, int high);//�жϽ��
int judg(char Lattice[][High], int wide, int high);