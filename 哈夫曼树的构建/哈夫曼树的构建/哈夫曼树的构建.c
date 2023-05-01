#include<stdio.h>
#include<stdlib.h>
#define N 30 //叶子结点最大值
#define M 2*N-1 //所有结点最大值

typedef struct Huffamntree 
{
	int weight;
	int parent, lch, rch;
	int flag;
}HTNode, HuffmanTree[M];


//选择函数选择最小的权值
//参数：树的地址 
//返回值：int n最小权值的下标
int select(HuffmanTree ht, int n)//选择最小权值的结点下标
{
	int i, temp, min=0;
	for (i = 1; i <= n; i++)//设置初始下标和权值
	{
		if (ht[i].flag == 0)
		{
			temp = ht[i].weight;//初始权值
			min = i;//初始下标
			break;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (ht[i].flag == 0 && temp > ht[i].weight)//当节点未被选中 并且 temp的值大于遍历到的节点时
		{
			temp = ht[i].weight;    //将更小的节点中权值赋给temp
			min = i;                //更改更小节点的下标；
		}
	}
	ht[min].flag = 1;                //这里已经选出最小了，那么就将标志位改为1.表示选过了
	return min;
}


//参数：树的地址，权值的个数
void CreatHuffmanTree(HuffmanTree HT,int n)
{	 
	int m = 2 * n - 1;
	for (int i = n + 1; i <= m; i++)
	{
		int s1 = select(HT, i - 1); //(最小) //这里 -1 是为了跳过新生成的节点直接从 1 ~  前一个节点 开始遍历
		int s2 = select(HT, i - 1);//(次小)
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1;
		HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//初始化哈夫曼树的权值节点
//参数：结构体数组地址，节点个数
void huffinit(HuffmanTree HT,int n)
{
	if (n <= 1) { return NULL; }
	int m = 2 * n - 1; //数组有2n-1个元素，树有2n-1个节点
	for (int i = 1; i <= m; i++)
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
		HT[i].flag = 0;//这里的标志是指 0：未被选择构造树的  1：已经被选过了
	}
	printf("请输入%d个权值\n", n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &HT[i].weight);
	}//前n个节点已经构造完了，后面构造 n+1  到  2n-1 的节点

}


void printHuffmanTree(HuffmanTree ht, int n)//打印哈夫曼树
{
	printf("结点  weigh  parent Lchild Rchild\n");
	for (int i = 1; i <= 2*n-1; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n", i, ht[i].weight, ht[i].parent, ht[i].lch, ht[i].rch);
	}
	printf("\n");
}


void main() 
{
	HuffmanTree TREE;
	huffinit(TREE, 5);
	CreatHuffmanTree(TREE,5);
	printHuffmanTree(TREE,5);
	
}