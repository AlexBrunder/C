#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

//˳���Ķ���
typedef struct {
	int elem[MAXSIZE];
	int length;
}SqList, * list;


//����Ľṹ����
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * LinkList;

Lnode* L;



//����һ��˳��� ����������� p ����p��ŵ�����Ҫ�洢������
//���ر�ĵ�ַ
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

//����һ������ 
//β�巨  int n �ж��ٸ�Ԫ�� ���ر�ĵ�ַ L
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

//�����ĺϲ�--�� ���Ա� ��ʵ��  (ֻ�����ڷǵݼ����������������ȵ����) 
//����Ĳ����� ˳���A,˳���B. ����ֵ�� �ϲ���ı�C ��ָ�룩
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
	if (pa > pa_last)//˵��A��ѭ������
	{
		while (pb <= pb_last) { *(pc++) = *(pb++); }
	}
	else if (pb > pb_last)//˵��B��ѭ������
	{
		while (pa <= pa_last) { *(pc++) = *(pa++); }
	}
	
	return C;


}

//�����ĺϲ�--�� ���� ��ʵ��  (ֻ�����ڷǵݼ����������������ȵ����) 
//����Ĳ����� ˳���A,˳���B. ����ֵ�� �ϲ���ı�C ��ָ�룩
LinkList MergeList_L(LinkList A, LinkList B)
{
	Lnode* pa, * pb, * pc; //����ָ��(ָ��ڵ�)
	pa = A->next;          //paָ��A����Ԫ�ڵ�
	pb = B->next;          //pbָ��B����Ԫ�ڵ�
	LinkList LC;              
	pc = LC = A;           //pcָ���C����Cָ���A;     ��ʵ����pcָ���A 
	while (pa && pb)
	{
		if (pa->data <= pb->data)//��A���е�ֵС��B���е�ֵʱ
		{
			pc->next = pa;       //��pc��ͷ�ڵ��е�next��ָ���С��ֵ��A��
			pc = pa;             //pcָ�� ��С�Ľڵ㣨A��
			pa = pa->next;		 //��paָ����һ���ڵ�(��С�ڵ�ĺ�һ���ڵ�)
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
	//���Ա�Ĳ���
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