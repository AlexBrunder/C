#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode,*LinkList;

Lnode *L;

//链表的初始化
int luck( LinkList A)
{
	int result;
	L = (LinkList)malloc(sizeof(Lnode));
	//把L作为A的头节点
	//把A作为链表的首元节点
	L->next = A;
	A->next = NULL;
	//判断链表为空吗？
	//listEmpty(L);
	//ClearList(L);
	result=find(L, 5);
	printf("result=%d\n", result);
	printf("L->next= %d\n",L->next);
	//销毁链表
	return 0;
}


//判断链表是否为空
/*int listEmpty(LinkList P)
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
*/

//删除单链表 头节点元素都没有了
int destory(LinkList P)
{
	while(P)
	{ 
		LinkList Q;
		Q = P;
		P = P->next;
		free(Q);
		
	}
	printf("销毁成功\n");
	return 0;
	
}

//清空链表 
int ClearList(LinkList p)
{
	LinkList q,o;
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

//求链表的表长
int ListLength(LinkList L)
{
	int i;
	LinkList p;
	p = L->next;
	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}


//查找第i个元素, L是表的地址 返回找到的第i个元素对应的值 找不到返回0
int find(LinkList L, int i)
{
	int r;
	int j=1;
	LinkList P;
	P = L->next;
	while (P && j < i)
	{
		P = P->next;
		j++;
	}
	if (!P || j > i) //当找不到时 返回0
	{
		return r = 0;
	}
	r = P->data;
}

//头插法  这是一个创建表的方法 n代表的是表的长度，最后返回表的地址 L
LinkList Him(int n)
{ 
	int i;
	LinkList p;
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	for (i = n; i > 0; i--)
	{
		p = (LinkList)malloc(sizeof(Lnode));
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//尾插法  int n 有多少个元素 返回表的地址 L
LinkList TiM(int n)
{
	int i;
	LinkList r;
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	r = L;
	for (i = 0; i < n; i++)
	{
		LinkList p= (LinkList)malloc(sizeof(Lnode));
		p->next = NULL;
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	return L;
}

//在第i个元素之前插入新的节点
int insertNewOne(LinkList L, int i, int e) //L 要插入的表 int i 在第几个元素之前插入  int e 插入的数据是多少  
{
	LinkList p;
	int j = 0;
	p = L;
	while (p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) //判断i是否合法
	{
		return 0;
	}
	LinkList new=(LinkList)malloc(sizeof(Lnode));
	new->data = e;
	new->next = p->next;
	p->next = new;
	return 1;
}

//删除节点 返回被删除的值  L删除的表， i第几个节点
int delete(LinkList L, int i) 
{
	//找到第i个节点
	LinkList p;
	int j = 0;
	p = L;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	LinkList q;
	q = p->next;
	p->next = q->next;
	int e;
	e = q->data;
	free(q);

	return e;
}
int main() {
	LinkList B =TiM(6); //生成表长为6的链表	
	int a = insertNewOne(B, 7, 7);
	printf("\n%d\n", a);
	int C = find(B, 2); //查找第3个元素 并且返回他的值 找不到则返回0
	printf("\n%d\n", C);
	free(B);
	return 0;
}
