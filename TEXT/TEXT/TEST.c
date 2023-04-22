#include<stdio.h>
#include<stdlib.h>

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
	Data** base;
	int length;
	int front;
	int rear;
}SqQueue, * Squeue;


/*        队列的算法start                   */

// 初始化队列的操作
//返回值：队列的地址
//参数:无
Squeue Initqueue()
{
	Squeue Q;
	Q = (Squeue)malloc(sizeof(SqQueue));
	Q->base = (Data**)malloc(MAXQSIZE * sizeof(Data*));
	Q->front = Q->rear = 0;
	Q->length = 0;
	return Q;
}

//队列的插入 队列的插入实在队列的尾部进行的
//参数：队列的地址，插入的值
//返回值：新的队列地址
void inserE(Squeue SU, Data* e)
{
	if ((SU->rear + 1) % MAXQSIZE == SU->front)
	{
		return SU;
	}
	*(SU->base + SU->length) = e;
	SU->rear = (SU->rear + 1) % MAXQSIZE;
	SU->length++;

}

//删除元素，顺序队列从队头删除元素
//删除完成之后头指针++
//参数：队列的地址
//返回值：被删除的元素
Data* deleE(Squeue SU)
{
	Data* x;
	x = *(SU->base + SU->front);
	SU->front = (SU->front + 1) % MAXQSIZE;
	printf("%c", x->data);
	return x;
}

//判断队列是否为空
//参数： 队列地址
//返回值：为空是：1   不为空：0
int Sqempty(Squeue SU)
{
	if (SU->base == SU->front )
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
//创建节点的算法
//返回值：一个节点的地址
//参数：一个char数
Data* CreatData(char a)
{
	Data* Ndata = (Data*)malloc(sizeof(Data));
	Ndata->data = a;
	Ndata->Ltree = NULL;
	Ndata->Rtree = NULL;
	return Ndata;
}


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
		T = CreatData(ch);
		T->Ltree = CreatePreTree(T->Ltree);
		T->Rtree = CreatePreTree(T->Rtree);
	}
	return T;
}

//先序遍历的算法（输出节点的值）DLR
//参数：树的地址
//返回值：0：为空值 1：成功
int PreOrderTraverse(Data* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		printf("%c", T->data);
		PreOrderTraverse(T->Ltree);
		PreOrderTraverse(T->Rtree);
	}
}

//中序遍历的算法（输出节点的值）LDR
//参数：树的地址
//返回值：0：为空值 1：成功
int MidOrderTraverse(Data* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		MidOrderTraverse(T->Ltree);
		printf("%c", T->data);
		MidOrderTraverse(T->Rtree);

	}
}


//后序遍历的算法（输出节点的值）LRD
//参数：树的地址
//返回值：0：为空值 1：成功
int BackOrderTraverse(Data* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		BackOrderTraverse(T->Ltree);
		BackOrderTraverse(T->Rtree);
		printf("%c\n", T->data);
	}
}

//计算二叉树的深度算法
//参数：树的地址
//返回值：树的深度int
int Depth(Data* T)
{
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;//深度为0
	}
	else
	{
		m = Depth(T->Ltree);
		n = Depth(T->Rtree);
		if (m > n)
		{
			return m + 1;
		}
		else
		{
			return n + 1;
		}
	}
}

//计算叶子节点的个数
//参数：树的地址
//返回值：个数int
void LeadCount(Data* T, int* i)
{
	if (T == NULL)
	{
		return 0;
	}
	if (T->Ltree == NULL && T->Rtree == NULL)
	{
		(*i)++;
	}
	LeadCount(T->Ltree, i);
	LeadCount(T->Rtree, i);
}

void LevelOrder(Data* b)
{
	Data* p = (Data*)malloc(sizeof(Data));  Squeue qu; //树节点的指针，栈指针
	int i;
	qu = Initqueue();
	inserE(qu, b);
	while (!(i = Sqempty(qu)))
	{
		p = deleE(qu);
		if (p->Ltree != NULL)
		{
			inserE(qu, p->Ltree);
		}
		if (p->Rtree != NULL)
		{
			inserE(qu, p->Rtree);
		}
	}
}
void main()
{
	Data* T = (Data*)malloc(sizeof(Data));
	T = CreatePreTree(T);
	LevelOrder(T);
}