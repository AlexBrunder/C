#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 100
typedef struct {
	int* base;
	int length;
	int front;
	int rear;
}SqQueue,*Squeue;

//初始化队列的操作
//返回值：队列的地址
//参数:无
Squeue Initqueue()
{
	Squeue Q;
	Q = (Squeue)malloc(sizeof(SqQueue));
	Q->base = (int*)malloc(MAXQSIZE * sizeof(int));
	Q->front = Q->rear = 0;
	Q->length = 0;
	return Q;
}

//队列的插入 队列的插入实在队列的尾部进行的
//参数：队列的地址，插入的值
//返回值：新的队列地址
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


