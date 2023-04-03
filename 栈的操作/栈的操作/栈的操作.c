#include<stdio.h>
#include<stdlib.h>
//˳��ջ�Ĵ���
#define MAXSIZE 100
typedef struct {
	int *base; //ջ��ָ��
	int *top;  //ջ��ָ��
	int stacksize;//�������
}SqStack,*stack;

//��ջ�Ĵ���
typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;



//����һ��˳���ջ
//����ֵ����ջ��ָ��
stack InitStack()
{	
	stack S;
	S = (stack)malloc(sizeof(SqStack));
	S->base = (int*)malloc(MAXSIZE * sizeof(SqStack));
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return S;
}

//˳��ջ����ջ ������˳��ջ������
//����ֵ���µ�˳��ջ
stack StackPush(stack A,int e)
{
	if (A->top - A->base == A->stacksize)//˵��ջ���ˣ������ټ���Ԫ��
	{
		return 0;
	}
	*A->top = e;
	A->top++;
	return A;
}

//��˳��ջ�ĳ���
//������˳��ջ��ָ�룩
//����ֵ��һ������
int StackLength(stack S)
{
	return S->top - S->base;		
}

//�ж�ջ�Ƿ�Ϊ��
//������ջ��ַ
//����ֵ �գ�1  �� �ǿգ�0
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

//����˳��ջ ���޷���ֵ��
//������˳��ջ�ĵ�ַ
//�ͷţ�base���ڴ�
//��stacksize=0
//��base �� top ָ�� NULL
void DestoryStack(stack S)
{
	if (S->base)
	{
		free(S->base);
		S->stacksize = 0;
		S->base = S->top = NULL;
	}
}

//���˳��ջ 
//��Ȼ����ջ
void ClearStack(stack S)
{
	if (S->base)
	{
		S->top = S->base;
	}
}

//��ջ����ջ
//��ջû��ͷ�ڵ㣬ͷָ��ָ�����һ��Ԫ�ء�
//������ջָ�룬ֵ��������
LinkStack LinkStackPush(LinkStack S, int e)
{
	//����һ���½ڵ㣻
	LinkStack p = (LinkStack)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S;
	S = p;
	return S;
}

//��ջ�ĳ�ջ
//ͷָ��ָ�����һ��Ԫ�أ��½�һ��ָ��P��������ͷָ��
//��ͷָ��ָ����һ��Ԫ��
//�ͷ�ԭ����ָ��P��ָ����ڴ�
//������ջ�ĵ�ַ
//����ֵ����ɾ����Ԫ��
int LinkStackPop(LinkStack S)
{	int e;
	LinkStack p;
	p = S;
	e = S->data;
	free(p);
	return e;
}

//ȡջ����Ԫ��
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
	//˳��ջ�Ĳ���

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