#include<stdio.h>
#include<stdlib.h>

//顺序队列的定义
#define MAXQSIZE 100
typedef struct {
	int* base;
	int length;
	int front;
	int rear;
}SqQueue,*Squeue;

//链队列的定义
typedef struct Qnode {
	int data;
	struct Qnode* next;
}Qnode,*QuenePtr;

typedef struct {
	QuenePtr front; //头节点，指向头节点
	QuenePtr rear;  //尾节点，指向最后一个元素
}LinkQueue;

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
	if((SU->rear +1)%MAXQSIZE ==SU->front)
	{
		return SU;
	}
	*(SU->base+SU->length) = e;
	SU->rear = (SU->rear + 1) % MAXQSIZE;
	SU->length++;
	return SU;
}

//删除元素，顺序队列从队头删除元素
//删除完成之后头指针++
//参数：队列的地址
//返回值：被删除的元素
int deleE(Squeue SU)
{
	int x;
	x = *(SU->base + SU->front);
	SU->front = (SU->front + 1) % MAXQSIZE;
	return x;
}

//链队列的初始化
//参数：无
//返回值：链队列的地址;
LinkQueue* InitQueue()
{
	LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Q->front = Q->rear = (QuenePtr)malloc(sizeof(Qnode));
	Q->front->next = NULL;
	return Q;
}

//链队列的入队操作
//链队列的入队，只能在队尾进行；
//参数：链队列的地址，入队的值；
//返回值：新的队列的地址；
LinkQueue* EnQueue(LinkQueue *SU,int e)
{
	//新建一个节点并且next为空值
	QuenePtr p=(QuenePtr)malloc(sizeof(Qnode));
	p->data = e;
	p->next = NULL;
	//尾部几点的next指向新的节点
	SU->rear->next = p;
	//更改尾指针的指向
	SU->rear = p;
	return SU;
	
}

//链队列的出队操作
//链队列的出队，只能在队头进行；也就是首元节点
//参数：链队列的地址；
//返回值：新的队列的地址；
LinkQueue* DeQueue(LinkQueue* SU)
{
	if (SU->front = SU->rear)
	{
		return SU;
	}
	QuenePtr p = (QuenePtr)malloc(sizeof(Qnode));//初始化操作
	p = SU->front->next; //获取首元节点的地址
	int e = p->data;      //保存首元节点的元素
	SU->front->next = p->next;  //更改头节点中的next域让他指向下一个元素(首元节点的后一个几点)  

	if (SU->rear == p) //如果尾指针等于，头节点中next指向的下一个节点（删除的是最后一个元素）      
	{
		SU->rear = SU->front; //令头头指针 《等于》 尾指针（空队列）
	}

	free(p);//删除首元节点
	return SU;
}

//求链队列的队头元素
//头指针指向的就是头节点，头节点中存储了首元节点的地址；
//参数：链队列的地址；
//返回值：int e 
int getHead(LinkQueue *SU)
{
	return SU->front->next->data;
}

void main()
{
	/*顺序队列部分
	Squeue W;
	W = Initqueue();
	W=inserE(W, 6); 
	W = inserE(W, 7);
	int a = deleE(W);
	printf("%d\n", W->front);
	printf("a=%d\n", a);
	*/

	//链式队列部分
	LinkQueue* Q = InitQueue();
	int b[10];
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &b[i]);
	}
	
	for (int i = 0; i < 10; i++)
	{
		Q = EnQueue(Q, b[i]);
	}
	//Q = DeQueue(Q);
	int e = getHead(Q);
	//printf("%d\n", Q->front->next->data);
	printf("表头的元素为：%d\n", e);
	QuenePtr index = (QuenePtr)malloc(sizeof(Qnode));
	index = Q->front->next;//获取首元节点的地址
	for (int i = 0; i < 10; i++)
	{
		printf("表的第%d个元素为：%d\n", i+1,index->data);
		index = index->next;
	}
}


