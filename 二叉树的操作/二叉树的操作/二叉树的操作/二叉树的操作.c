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

//先序遍历的算法（输出节点的值）
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

void main()
{
	Data* FirstTree =(Data*)malloc(sizeof(Data));
	FirstTree = CreatData('a');
	FirstTree= CreatePreTree(FirstTree,0);
	printf("\n");
	int i = PreOrderTraverse(FirstTree);
}
