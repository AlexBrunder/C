#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

//�������нڵ�Ķ���start
typedef struct Data
{
	char data;
	struct Data* Ltree;
	struct Data* Rtree;
}Data;
//�������Ķ���end

//˳����еĶ���
#define MAXQSIZE 100
typedef struct {
	Data base[MAXQSIZE];
	int length;
	int front;
	int rear;
}SqQueue, * Squeue;


/*        ���е��㷨start                   */

// ��ʼ�����еĲ���
//����ֵ�����еĵ�ַ
//����:��
/*
Squeue Initqueue()
{
	Squeue Q = (Squeue)malloc(sizeof(SqQueue));
	Q->base = (Data**)malloc(MAXQSIZE * sizeof(Data*));
	Q->front = Q->rear = 0;
	Q->length = 0;
	return Q;
}
*/

//���еĲ��� ���еĲ���ʵ�ڶ��е�β�����е�
//���������еĵ�ַ�������ֵ
void inserE(Squeue SU, Data e)
{
	SU->rear = (SU->rear + 1) % MAXQSIZE;
	SU->base[SU->rear] = e;
	SU->length++;
}

//ɾ��Ԫ�أ�˳����дӶ�ͷɾ��Ԫ��
//ɾ�����֮��ͷָ��++
//���������еĵ�ַ
void deleE(Squeue SU)
{
	SU->front = (SU->front + 1) % MAXQSIZE;
}

//�ж϶����Ƿ�Ϊ��
//������ ���е�ַ
//����ֵ��Ϊ���ǣ�1   ��Ϊ�գ�0
int Sqempty(Squeue SU)
{
	if (SU->front == SU->rear)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
/*        ���е��㷨end                     */




/*       �����������㷨start                */
/*                                          */

//������������ķ�ʽ����������
// �������˳������ڵ㣬�սڵ��� # ��ʾ
//���������ĵ�ַ
//����ֵ�������ĵ�ַ
Data* CreatePreTree(Data* T)
{

	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (Data*)malloc(sizeof(Data));
		T->data = ch;
		T->Ltree = CreatePreTree(T->Ltree);
		T->Rtree = CreatePreTree(T->Rtree);
	}
	return T;
}

void LevelOrder(Data* b)
{   
	SqQueue qu; //ջ             /*��ʼ��ջ*/
  	qu.front = 0;
	qu.rear = 0;
	Data* p=(Data*)malloc(sizeof(Data));//���ڵ�ָ��
	int i;
	inserE(&qu, *b);
	while (!(i=Sqempty(&qu)))
	{
		*p = qu.base[qu.front + 1];
		printf("%c", p->data);
		deleE(&qu);
		if (p->Ltree != NULL)
		{
			inserE(&qu, *p->Ltree);
		}
		if (p->Rtree != NULL)
		{
			inserE(&qu, *p->Rtree);
		}
	}
}
void main()
{
	Data* T=(Data*)malloc(sizeof(Data));
	T = CreatePreTree(T);
	LevelOrder(T);
	
}