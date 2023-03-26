#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct {
	int elem[MAXSIZE];
	int length;
}SqList,*list;


//����һ��˳��� ����������� p 
//���ر�ĵ�ַ
list creatList(int *p)
{
	int i;
	list L = (list)malloc(sizeof(SqList));
	L->length = 0;
	for (i = 0; i < MAXSIZE; i++)
	{
		L->elem[i]=*(p+i);
		if(L->elem[i]!=NULL)
		{ L->length++;}
		
	}
	return L;
}

//˳����ȡֵ ����i��ֵ���� ��Ӧ��Ԫ��    int i �ǵڼ���Ԫ�� ��L�Ǳ������   
//�ɹ����ض�Ӧ��ֵ��ʧ�ܷ���0.
int GetElem(int i,list L)
{
	if (i<1 || i > L->length)
	{
		return 0;
	}
	
	return L->elem[i-1];
}

//��˳����в���һ��ֵ ����Ĳ���  �������L, �ڵڼ���Ԫ�ز���i�������Ԫ��e
//����ɹ����ض�Ӧ���µı��ַ��ʧ�ܷ���0.
list InsertList_sq(list L, int i, int e)
{
	int a=0;
	if (i<1 || i > L->length + 1)
	{
		return 0;
	}
	//��һԪ�ز���˳���ʱ������λ��֮���Ԫ����Ҫ�����ƶ�һλ��Ϊ��Ԫ���ڳ�λ��
	for( a=L->length-1; a>=i-1; a--)
	{ L->elem[a + 1] = L->elem[a]; }
	L->elem[i - 1] = e;
	L->length++;
	return L;
}


//ɾ��ĳ��Ԫ�� Ҫɾ��ĳ��Ԫ�صı�L,ɾ���ڼ���Ԫ��i
//ɾ���ɹ������±�L�����ɹ�����return 0 
list deleteLs(list L, int i)
{
	int a;
	if(i<1 || i > L->length )
	{
		return 0;
	}
	for (a = i; a <= L->length - 1; a++)
	{
		L->elem[a - 1] = L->elem[a];
	}
	L->length--;
	return L;
}
//��ֵe���� ���ҵı�L,���ҵ�ֵe
//�ɹ������� ��Ӧ�ĵڼ���length    ʧ�ܣ��Ҳ�������0
int findE(list L, int e)
{
	int i;
	for (i = 0; i <= L->length - 1; i++)
	{
		if (L->elem[i] == e)
		{
			return i+1;
		}
	}
	return 0;
}

//��i����ֵ����L  ��i��Ԫ��  
//�ɹ�������e  ʧ�ܣ�����0
int finde(list L,int i)
{
	int e;
	if (i<1 || i > L->length)
	{
		return 0;
	}
	return L->elem[i - 1];;
}
void main() 
{
	int A[100] = { 1,2,3,1,4,6,8,8,9,67,4,45,4,54,54};
	list L = creatList(A);
	int a = finde(L,13);
	printf("\n%d\n", a);
	printf("\nL->length=%d\n", L->length);	
	free(L);
}
