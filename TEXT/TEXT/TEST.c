#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * LinkList;

Lnode* L;

//链表的初始化
int luck(LinkList A)
{
	L = (LinkList)malloc(sizeof(Lnode));
	//把L作为A的头节点
	//把A作为链表的首元节点
	L->next = A;
	A->next = NULL;
	//判断链表为空吗？
	listEmpty(L);
	//ClearList(L);
	//destory(L);
	printf("L->next= %d\n", L->next);
	//销毁链表
	return 0;
}


//判断链表是否为空
int listEmpty(LinkList P)
{
	if (P->next)
	{
		printf("链表不为空\n");
		return 0;
	}
	else
	{
		printf("链表为空\n");
		return 1;
	}
}

//删除单链表 头节点元素都没有了
int destory(LinkList P)
{
	while (P)
	{
		LinkList Q;
		Q = P;
		P = P->next;
		free(Q);

	}
	printf("销毁成功\n");
	

}

//清空链表 
int ClearList(LinkList p)
{
	LinkList q, o;
	//跳过头节点
	q = p->next;
	while (q)
	{
		//让o指向下一个节点
		o = q;
		q = q->next;

		//释放除头节点外的元素内存
		free(o);
		//更新，直到q指向最后一个节点 直到null
		//这里的q实际上就是首元节点
	}
	//最后让头节点指向空值
	p->next = NULL;
	return 0;
}

int main() {
	//初始化结构体给他赋值
	
	//让结构体指针指向新建的结构体
	LinkList B = (LinkList)malloc(sizeof(Lnode));
	B->data = 1;

	//将结构体指针带入函数 开辟内存 新建一个单链表
	luck(B);
	//释放内存
	free(L);
	return 0;
}
