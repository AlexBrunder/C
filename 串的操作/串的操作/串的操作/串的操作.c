#include<stdio.h>
#include<stdlib.h>
#define CHUANKSIZE 80
#define MAXLEN 255 

//定义顺序串的结构
typedef struct {
	char chuank[MAXLEN + 1];//这里为了后面操作方便 数组下标为1才开始存储数据
	int length;
}SString;

//字符串的块链结构
typedef struct Chunk {
	char ch[CHUANKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;
	int curlen;
}LString;


//创建一个顺序表 将数组的名字 p 
//返回表的地址
SString* creatList(char* p)
{
	int i;
	SString* L = (SString*)malloc(sizeof(SString));
	L->length = 0;
	L->chuank[0] = 'L';
	for (i = 0; i < MAXLEN; i++) //让数组从下标1开始存储数据
	{
		L->chuank[i+1] = *(p + i);
		if (L->chuank[i+1] != NULL)
		{
			L->length++;
		}
	}
	return L;
}

//BF算法穷举法
int index_BF(SString* S, SString* T)//S为主串 T为子串
{
	int i = 1,j=1;    //i表示主串 ， j表示子串
	while (i <= S->length && j <= T->length)//直到匹配完为止
	{
		if (S->chuank[i] == T->chuank[j])//一个一个匹配
		{
			i++;
			j++;
		}
		else {
			i = i - j + 2;//让主串下标返回到上一个i的位置
			j = 1;        //字串重新开始匹配
		}
	}

	if (j >= T->length) //如果字串已经跑完了没有返回j=1
	{
		return i - T->length; //返回‘子串字符串’在主串中第一个字符 的位置
	}
	else { return 0; }//找不到返回0；
}

//KMP算法:生成一个next[j]数组保存，下一次匹配子串的下标位置
//参数：子串（数组）的名字  （char*指针）
//返回值next[j]
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
		printf("第%d个值为L->chuank[%d]=%c\n", i+1, i+1, S->chuank[i+1]);
	}
	int a = index_BF(S, T);
	printf("%d\n", a);
	free(S);
	free(T);
}