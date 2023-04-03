#include<stdio.h>
#include<stdlib.h>
//顺序栈的创建
#define MAXSIZE 100
typedef struct {
	int *base; //栈底指针
	int *top;  //栈顶指针
	int stacksize;//最大容量
}SqStack,*stack;

//链栈的创建
typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;



//创建一个顺序空栈
//返回值：空栈的指针
stack InitStack()
{	
	stack S;
	S = (stack)malloc(sizeof(SqStack));
	S->base = (int*)malloc(MAXSIZE * sizeof(SqStack));
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return S;
}

//顺序栈的入栈 参数：顺序栈，整数
//返回值：新的顺序栈
stack StackPush(stack A,int e)
{
	if (A->top - A->base == A->stacksize)//说明栈满了，不能再加入元素
	{
		return 0;
	}
	*A->top = e;
	A->top++;
	return A;
}

//求顺序栈的长度
//参数：顺序栈（指针）
//返回值：一个整数
int StackLength(stack S)
{
	return S->top - S->base;		
}

//判断栈是否为空
//参数：栈地址
//返回值 空：1  ， 非空：0
int StackEmpty(stack S)
{
	if (S->base == S->top)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

//销毁顺序栈 （无返回值）
//参数：顺序栈的地址
//释放：base的内存
//令stacksize=0
//令base 和 top 指向 NULL
void DestoryStack(stack S)
{
	if (S->base)
	{
		free(S->base);
		S->stacksize = 0;
		S->base = S->top = NULL;
	}
}

//清空顺序栈 
//仍然保存栈
void ClearStack(stack S)
{
	if (S->base)
	{
		S->top = S->base;
	}
}

//链栈的入栈
//链栈没有头节点，头指针指向最后一个元素。
//参数：栈指针，值（整数）
LinkStack LinkStackPush(LinkStack S, int e)
{
	//创建一个新节点；
	LinkStack p = (LinkStack)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S;
	S = p;
	return S;
}

//链栈的出栈
//头指针指向最后一个元素，新建一个指针P让他等于头指针
//让头指针指向下一个元素
//释放原来的指针P所指向的内存
//参数：栈的地址
//返回值：被删除的元素
int LinkStackPop(LinkStack S)
{	int e;
	LinkStack p;
	p = S;
	e = S->data;
	free(p);
	return e;
}

//取栈顶的元素
int getTop(LinkStack S)
{
	if (S != NULL)
	{
		return S->data;
	}
	else {
		return 0;
	}
		
}


void main()
{
	//顺序栈的部分

	/*
	stack newStack;
	newStack = InitStack();
	
	
	int i[5];
	for (int a=0; a < 5; a++)
	{
		scanf_s("%d", &i[a]);
		newStack = StackPush(newStack, i[a]);
	}
	printf("\n");

	ClearStack(newStack);
	printf("%d\n", *(newStack->base));
	
	*/
	/*
	for (int b=0; b < 5; b++)
	{
		printf("%d\n", *(newStack->base+b));
	}
	printf("\n");
	int length;
	length=StackLength(newStack);
	printf("%d\n",length);
	*/

	LinkStack S;
	S = (LinkStack)malloc(sizeof(StackNode));
	S = LinkStackPush(S, 8);
	S = LinkStackPush(S, 100);
	int e;
	e = getTop(S);
	printf("%d\n", e);
}