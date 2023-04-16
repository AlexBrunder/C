#include<stdio.h>
#include <stdlib.h>
//二叉树中节点的定义
typedef struct Data
{
	char data;
	struct Data* Ltree;
	struct Data* Rtree;
}Data;
//二叉树的定义

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

//先序遍历的算法（输出节点的值）DLR
//参数：树的地址
//返回值：0：为空值 1：成功
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
	int m=0, n=0;
	if(T==NULL)
	{
		return 0;//深度为0
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

//计算叶子节点的个数
//参数：树的地址
//返回值：个数int
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
