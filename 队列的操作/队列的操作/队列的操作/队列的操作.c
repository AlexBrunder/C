#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 100
typedef struct {
	int* base;
	int length;
	int front;
	int rear;
}SqQueue,*Squeue;

//��ʼ�����еĲ���
//����ֵ�����еĵ�ַ
//����:��
Squeue Initqueue()
{
	Squeue Q;
	Q = (Squeue)malloc(sizeof(SqQueue));
	Q->base = (int*)malloc(MAXQSIZE * sizeof(int));
	Q->front = Q->rear = 0;
	Q->length = 0;
	return Q;
}

//���еĲ��� ���еĲ���ʵ�ڶ��е�β�����е�
//���������еĵ�ַ�������ֵ
//����ֵ���µĶ��е�ַ
Squeue inserE(Squeue SU, int e)
{
	*(SU->base+SU->length) = e;
	SU->rear = (SU->rear + 1) % MAXQSIZE;
	SU->length++;
	return SU;
}

void main()
{
	Squeue W;
	W = Initqueue();
	int n = 6;
	W=inserE(W, n);
	W = inserE(W, 7);

	printf("%d\n", *W->base+1);

}


