#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * LinkList;

Lnode* L;

//����ĳ�ʼ��
int luck(LinkList A)
{
	L = (LinkList)malloc(sizeof(Lnode));
	//��L��ΪA��ͷ�ڵ�
	//��A��Ϊ�������Ԫ�ڵ�
	L->next = A;
	A->next = NULL;
	//�ж�����Ϊ����
	listEmpty(L);
	//ClearList(L);
	//destory(L);
	printf("L->next= %d\n", L->next);
	//��������
	return 0;
}


//�ж������Ƿ�Ϊ��
int listEmpty(LinkList P)
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

//ɾ�������� ͷ�ڵ�Ԫ�ض�û����
int destory(LinkList P)
{
	while (P)
	{
		LinkList Q;
		Q = P;
		P = P->next;
		free(Q);

	}
	printf("���ٳɹ�\n");
	

}

//������� 
int ClearList(LinkList p)
{
	LinkList q, o;
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

int main() {
	//��ʼ���ṹ�������ֵ
	
	//�ýṹ��ָ��ָ���½��Ľṹ��
	LinkList B = (LinkList)malloc(sizeof(Lnode));
	B->data = 1;

	//���ṹ��ָ����뺯�� �����ڴ� �½�һ��������
	luck(B);
	//�ͷ��ڴ�
	free(L);
	return 0;
}
