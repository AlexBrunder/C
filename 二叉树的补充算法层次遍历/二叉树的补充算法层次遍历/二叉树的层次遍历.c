#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

//二叉树中节点的定义start
typedef struct Data
{
	char data;
	struct Data* Ltree;
	struct Data* Rtree;
}Data;
//二叉树的定义end

//顺序队列的定义
#define MAXQSIZE 100
typedef struct {
	Data base[MAXQSIZE];
	int length;
	int front;
	int rear;
}SqQueue, * Squeue;


/*        队列的算法start                   */

// 初始化队列的操作
//返回值：队列的地址
//参数:无
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

//队列的插入 队列的插入实在队列的尾部进行的
//参数：队列的地址，插入的值
void inserE(Squeue SU, Data e)
{
	SU->rear = (SU->rear + 1) % MAXQSIZE;
	SU->base[SU->rear] = e;
	SU->length++;
}

//删除元素，顺序队列从队头删除元素
//删除完成之后头指针++
//参数：队列的地址
void deleE(Squeue SU)
{
	SU->front = (SU->front + 1) % MAXQSIZE;
}

//判断队列是否为空
//参数： 队列地址
//返回值：为空是：1   不为空：0
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
/*        队列的算法end                     */




/*       二叉树创建算法start                */
/*                                          */

//按照先序排序的方式创建二叉树
// 按先序的顺序输入节点，空节点用 # 表示
//参数：树的地址
//返回值：新树的地址
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
	SqQueue qu; //栈             /*初始化栈*/
  	qu.front = 0;
	qu.rear = 0;
	Data* p=(Data*)malloc(sizeof(Data));//树节点指针
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