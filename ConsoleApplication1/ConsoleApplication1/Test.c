/*<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main()
{
	FILE* file;
	char* str;
	int length;
	file = fopen("���.txt","rb");
	if (file == NULL)
	{
		perror("fopen");
		return 0;
	}
	fseek(file,0,SEEK_END);
	length = ftell(file);
	rewind(file);
	str = malloc(length + 1);
	if (str == NULL)
	{
		perror("malloc");
		return 0;
	}
	fread(str,length,1,file);
	str[length] = '\0';
	printf("%s\n", str);
	fclose(file);
	free(str);

	return 0;

}*/

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
	//listEmpty(L);
	ClearList(L);
	printf("L->next= %d\n", L->next);
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
	while (P)
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
	Lnode biao;
	biao.data = 1;

	//�ýṹ��ָ��ָ���½��Ľṹ��
	LinkList B = &biao;

	//���ṹ��ָ����뺯�� �����ڴ� �½�һ��������
	luck(B);
	//�ͷ��ڴ�
	free(L);
	return 0;
}
