#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode,*LinkList;

Lnode *L;

//����ĳ�ʼ��
int luck( LinkList A)
{
	int result;
	L = (LinkList)malloc(sizeof(Lnode));
	//��L��ΪA��ͷ�ڵ�
	//��A��Ϊ�������Ԫ�ڵ�
	L->next = A;
	A->next = NULL;
	//�ж�����Ϊ����
	//listEmpty(L);
	//ClearList(L);
	result=find(L, 5);
	printf("result=%d\n", result);
	printf("L->next= %d\n",L->next);
	//��������
	return 0;
}


//�ж������Ƿ�Ϊ��
/*int listEmpty(LinkList P)
{
	if (P->next)
	{
		printf("����Ϊ��\n");
		return 0;
	}
	else
	{
		printf("����Ϊ��\n");
		return 1;
	}
}
*/

//ɾ�������� ͷ�ڵ�Ԫ�ض�û����
int destory(LinkList P)
{
	while(P)
	{ 
		LinkList Q;
		Q = P;
		P = P->next;
		free(Q);
		
	}
	printf("���ٳɹ�\n");
	return 0;
	
}

//������� 
int ClearList(LinkList p)
{
	LinkList q,o;
	//����ͷ�ڵ�
	q = p->next;
	while (q)
	{
		//��oָ����һ���ڵ�
		o = q;
		q = q->next;
		
		//�ͷų�ͷ�ڵ����Ԫ���ڴ�
		free(o);
		//���£�ֱ��qָ�����һ���ڵ� ֱ��null
		//�����qʵ���Ͼ�����Ԫ�ڵ�
	}
	//�����ͷ�ڵ�ָ���ֵ
	p->next = NULL;
	return 0;
}

//������ı�
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


//���ҵ�i��Ԫ��, L�Ǳ�ĵ�ַ �����ҵ��ĵ�i��Ԫ�ض�Ӧ��ֵ �Ҳ�������0
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
	if (!P || j > i) //���Ҳ���ʱ ����0
	{
		return r = 0;
	}
	r = P->data;
}

//ͷ�巨  ����һ��������ķ��� n������Ǳ�ĳ��ȣ���󷵻ر�ĵ�ַ L
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
		LinkList p= (LinkList)malloc(sizeof(Lnode));
		p->next = NULL;
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	return L;
}

//�ڵ�i��Ԫ��֮ǰ�����µĽڵ�
int insertNewOne(LinkList L, int i, int e) //L Ҫ����ı� int i �ڵڼ���Ԫ��֮ǰ����  int e ����������Ƕ���  
{
	LinkList p;
	int j = 0;
	p = L;
	while (p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) //�ж�i�Ƿ�Ϸ�
	{
		return 0;
	}
	LinkList new=(LinkList)malloc(sizeof(Lnode));
	new->data = e;
	new->next = p->next;
	p->next = new;
	return 1;
}

//ɾ���ڵ� ���ر�ɾ����ֵ  Lɾ���ı� i�ڼ����ڵ�
int delete(LinkList L, int i) 
{
	//�ҵ���i���ڵ�
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
	LinkList B =TiM(6); //���ɱ�Ϊ6������	
	int a = insertNewOne(B, 7, 7);
	printf("\n%d\n", a);
	int C = find(B, 2); //���ҵ�3��Ԫ�� ���ҷ�������ֵ �Ҳ����򷵻�0
	printf("\n%d\n", C);
	free(B);
	return 0;
}
