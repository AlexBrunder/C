#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

//顺序表的定义
typedef struct {
	int elem[MAXSIZE];
	int length;
}SqList, * list;


//链表的结构定义
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * LinkList;

Lnode* L;



//创建一个顺序表 将数组的名字 p 数组p存放的是你要存储的数据
//返回表的地址
list creatList(int* p)
{
	int i;
	list L = (list)malloc(sizeof(SqList));
	L->length = 0;
	for (i = 0; i < MAXSIZE; i++)
	{
		L->elem[i] = *(p + i);
		if (L->elem[i] != NULL)
		{
			L->length++;
		}

	}
	return L;
}

//创建一个链表 
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
		LinkList p = (LinkList)malloc(sizeof(Lnode));
		p->next = NULL;
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	return L;
}

//有序表的合并--用 线性表 来实现  (只能用于非递减的有序表，可以有相等的情况) 
//传入的参数： 顺序表A,顺序表B. 返回值： 合并后的表C （指针）
list Mergelist(list A, list B)
{
	int* pa, * pb,*pc;
	int* pa_last, * pb_last;
	pa = A->elem;
	pb = B->elem;
	list C = (list)malloc(sizeof(SqList));
	C->length = A->length + B->length;
	pc = C->elem;
	pa_last = pa + A->length - 1;
	pb_last = pb + B->length - 1;

	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
		{
			*(pc++) = *(pa++);
			
		}
		else
		{
			*(pc++) = *(pb++);
		}	
		if (*pa <= *pb)
		{
			*(pc++) = *(pa++);
		}
		else 
		{
			*(pc++) = *(pb++);
		}
		
	
	}
	if (pa > pa_last)//说明A表循环完了
	{
		while (pb <= pb_last) { *(pc++) = *(pb++); }
	}
	else if (pb > pb_last)//说明B表循环完了
	{
		while (pa <= pa_last) { *(pc++) = *(pa++); }
	}
	
	return C;


}

//有序表的合并--用 链表 来实现  (只能用于非递减的有序表，可以有相等的情况) 
//传入的参数： 顺序表A,顺序表B. 返回值： 合并后的表C （指针）
LinkList MergeList_L(LinkList A, LinkList B)
{
	Lnode* pa, * pb, * pc; //创建指针(指向节点)
	pa = A->next;          //pa指向A的首元节点
	pb = B->next;          //pb指向B的首元节点
	LinkList LC;              
	pc = LC = A;           //pc指向表C，表C指向表A;     其实就是pc指向表A 
	while (pa && pb)
	{
		if (pa->data <= pb->data)//当A表中的值小于B表中的值时
		{
			pc->next = pa;       //令pc的头节点中的next域指向较小的值（A表）
			pc = pa;             //pc指向 较小的节点（A表）
			pa = pa->next;		 //让pa指向下一个节点(较小节点的后一个节点)
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(B);
	return LC;
}



void main() {
	//线性表的测试
	/*
	list LA,LB,LC;
	
	int A[100] = { 1,7,8,8,12,14};
	int B[100] = { 2,4,6,8,10,11};
	LA = creatList(A);
	LB = creatList(B);
	LC = Mergelist(LA, LB);
	int i;
	for (i = 0;i < LC->length;i++)
	{
		printf("%d\n",LC->elem[i]);
	}
	printf("LC->length=%d\n",LC->length);
	*/
	
	LinkList A,B,C;
	A = TiM(3);
	B = TiM(3);
	C = MergeList_L(A, B);
	for (int i = 0;i < 6;i++)
	{
		C = C->next;
		printf("C->data = %d\n", C->data);
	}
	
 
}