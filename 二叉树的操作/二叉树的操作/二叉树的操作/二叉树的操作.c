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
	Data* p= (Data*)malloc(sizeof(Data));
	if (a <6)
	{ 
		char ch;
		scanf_s("%c", &ch);
		a++;
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
	}
	return T;
}

//����������㷨������ڵ��ֵ��
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

void main()
{
	Data* FirstTree =(Data*)malloc(sizeof(Data));
	FirstTree = CreatData('a');
	FirstTree= CreatePreTree(FirstTree,0);
	printf("\n");
	int i = PreOrderTraverse(FirstTree);
}
