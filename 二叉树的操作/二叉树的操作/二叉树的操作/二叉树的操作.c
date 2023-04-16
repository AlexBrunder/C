#include<stdio.h>
#include <stdlib.h>
//�������нڵ�Ķ���
typedef struct Data
{
	char data;
	struct Data* Ltree;
	struct Data* Rtree;
}Data;
//�������Ķ���

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
Data* CreatePreTree(Data* T,int a)
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
		a++;
		T->Ltree = CreatePreTree(T->Ltree,a);
		T->Rtree = CreatePreTree(T->Rtree,a);
	}
	return T;
}

//����������㷨������ڵ��ֵ��DLR
//���������ĵ�ַ
//����ֵ��0��Ϊ��ֵ 1���ɹ�
int PreOrderTraverse(Data* T)
{
	if(T==NULL)
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
	int m=0, n=0;
	if(T==NULL)
	{
		return 0;//���Ϊ0
	}
	else
	{
		m = Depth(T->Ltree);
		n = Depth(T->Rtree);
		if (m > n)
		{
			return m+1;
		}
		else
		{
			return n+1;
		}
	}
}

//����Ҷ�ӽڵ�ĸ���
//���������ĵ�ַ
//����ֵ������int
void LeadCount(Data* T,int*i)
{
	if (T == NULL)
	{
		return 0;
	}
	if(T->Ltree == NULL && T->Rtree == NULL)
	{
		(*i)++;
	}	
    LeadCount(T->Ltree,i);
	LeadCount(T->Rtree, i);
}


void main()
{
	Data* FirstTree = (Data*)malloc(sizeof(Data));
	FirstTree = CreatePreTree(FirstTree, 0);
	printf("\n");
	int i = 0;
	int* p = &i;
	i = Depth(FirstTree, i);
}
