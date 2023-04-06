#include<stdio.h>
#include<stdlib.h>
#define CHUANKSIZE 80
#define MAXLEN 255 

//����˳�򴮵Ľṹ
typedef struct {
	char chuank[MAXLEN + 1];//����Ϊ�˺���������� �����±�Ϊ1�ſ�ʼ�洢����
	int length;
}SString;

//�ַ����Ŀ����ṹ
typedef struct Chunk {
	char ch[CHUANKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;
	int curlen;
}LString;


//����һ��˳��� ����������� p 
//���ر�ĵ�ַ
SString* creatList(char* p)
{
	int i;
	SString* L = (SString*)malloc(sizeof(SString));
	L->length = 0;
	L->chuank[0] = 'L';
	for (i = 0; i < MAXLEN; i++) //��������±�1��ʼ�洢����
	{
		L->chuank[i+1] = *(p + i);
		if (L->chuank[i+1] != NULL)
		{
			L->length++;
		}
	}
	return L;
}

//BF�㷨��ٷ�
int index_BF(SString* S, SString* T)//SΪ���� TΪ�Ӵ�
{
	int i = 1,j=1;    //i��ʾ���� �� j��ʾ�Ӵ�
	while (i <= S->length && j <= T->length)//ֱ��ƥ����Ϊֹ
	{
		if (S->chuank[i] == T->chuank[j])//һ��һ��ƥ��
		{
			i++;
			j++;
		}
		else {
			i = i - j + 2;//�������±귵�ص���һ��i��λ��
			j = 1;        //�ִ����¿�ʼƥ��
		}
	}

	if (j >= T->length) //����ִ��Ѿ�������û�з���j=1
	{
		return i - T->length; //���ء��Ӵ��ַ������������е�һ���ַ� ��λ��
	}
	else { return 0; }//�Ҳ�������0��
}

//KMP�㷨:����һ��next[j]���鱣�棬��һ��ƥ���Ӵ����±�λ��
//�������Ӵ������飩������  ��char*ָ�룩
//����ֵnext[j]
/*
int* KMP_index(SString* T,int next[])
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < n)
	{
		if (k == -1 || p[j] == p[k])
		{
			next[j + 1] = k + 1;
			j++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
	
	return next;
}*/


void main()
{
	char A[MAXLEN] = { 'a','b','c','b','b','h','f'};
	char B[MAXLEN] = { 'b','c' };
	SString* S = creatList(A);
	SString* T = creatList(B);
	printf("S->length = % d\n", S->length);
	for (int i = 0; i < S->length; i++)
	{
		printf("��%d��ֵΪL->chuank[%d]=%c\n", i+1, i+1, S->chuank[i+1]);
	}
	int a = index_BF(S, T);
	printf("%d\n", a);
	free(S);
	free(T);
}