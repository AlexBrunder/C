#include<stdio.h>
#include<stdlib.h>

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
	Data** base;
	int length;
	int front;
	int rear;
}SqQueue, * Squeue;


/*        ���е��㷨start                   */

// ��ʼ�����еĲ���
//����ֵ�����еĵ�ַ
//����:��
Squeue Initqueue()
{
	Squeue Q;
	Q = (Squeue)malloc(sizeof(SqQueue));
	Q->base = (Data**)malloc(MAXQSIZE * sizeof(Data*));
	Q->front = Q->rear = 0;
	Q->length = 0;
	return Q;
}

//���еĲ��� ���еĲ���ʵ�ڶ��е�β�����е�
//���������еĵ�ַ�������ֵ
//����ֵ���µĶ��е�ַ
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

//ɾ��Ԫ�أ�˳����дӶ�ͷɾ��Ԫ��
//ɾ�����֮��ͷָ��++
//���������еĵ�ַ
//����ֵ����ɾ����Ԫ��
Data* deleE(Squeue SU)
{
	Data* x;
	x = *(SU->base + SU->front);
	SU->front = (SU->front + 1) % MAXQSIZE;
	printf("%c", x->data);
	return x;
}

//�ж϶����Ƿ�Ϊ��
//������ ���е�ַ
//����ֵ��Ϊ���ǣ�1   ��Ϊ�գ�0
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
/*        ���е��㷨end                     */




/*       �����������㷨start                */
/*                                          */
//�����ڵ���㷨
//����ֵ��һ���ڵ�ĵ�ַ
//������һ��char��
Data* CreatData(char a)
{
	Data* Ndata = (Data*)malloc(sizeof(Data));
	Ndata->data = a;
	Ndata->Ltree = NULL;
	Ndata->Rtree = NULL;
	return Ndata;
}


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
		T = CreatData(ch);
		T->Ltree = CreatePreTree(T->Ltree);
		T->Rtree = CreatePreTree(T->Rtree);
	}
	return T;
}

//����������㷨������ڵ��ֵ��DLR
//���������ĵ�ַ
//����ֵ��0��Ϊ��ֵ 1���ɹ�
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

//����������㷨������ڵ��ֵ��LDR
//���������ĵ�ַ
//����ֵ��0��Ϊ��ֵ 1���ɹ�
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


//����������㷨������ڵ��ֵ��LRD
//���������ĵ�ַ
//����ֵ��0��Ϊ��ֵ 1���ɹ�
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

//���������������㷨
//���������ĵ�ַ
//����ֵ���������int
int Depth(Data* T)
{
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;//���Ϊ0
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

//����Ҷ�ӽڵ�ĸ���
//���������ĵ�ַ
//����ֵ������int
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
	Data* p = (Data*)malloc(sizeof(Data));  Squeue qu; //���ڵ��ָ�룬ջָ��
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