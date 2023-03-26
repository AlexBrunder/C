#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct {
	int elem[MAXSIZE];
	int length;
}SqList,*list;


//创建一个顺序表 将数组的名字 p 
//返回表的地址
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

//顺序表的取值 根据i的值返回 对应的元素    int i 是第几个元素 ，L是表的名字   
//成功返回对应的值，失败返回0.
int GetElem(int i,list L)
{
	if (i<1 || i > L->length)
	{
		return 0;
	}
	
	return L->elem[i-1];
}

//在顺序表中插入一个值 传入的参数  表的名字L, 在第几个元素插入i，插入的元素e
//插入成功返回对应的新的表地址，失败返回0.
list InsertList_sq(list L, int i, int e)
{
	int a=0;
	if (i<1 || i > L->length + 1)
	{
		return 0;
	}
	//当一元素插入顺序表时，插入位置之后的元素需要往后移动一位，为新元素腾出位置
	for( a=L->length-1; a>=i-1; a--)
	{ L->elem[a + 1] = L->elem[a]; }
	L->elem[i - 1] = e;
	L->length++;
	return L;
}


//删除某个元素 要删除某个元素的表L,删除第几个元素i
//删除成功返回新表L，不成功返回return 0 
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
//按值e查找 查找的表L,查找的值e
//成功：返回 对应的第几个length    失败：找不到返回0
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

//按i查找值，表L  第i个元素  
//成功：返回e  失败：返回0
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
