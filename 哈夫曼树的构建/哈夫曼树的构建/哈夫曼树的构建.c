#include<stdio.h>
#include<stdlib.h>
#define N 30 //Ҷ�ӽ�����ֵ
#define M 2*N-1 //���н�����ֵ

typedef struct Huffamntree 
{
	int weight;
	int parent, lch, rch;
	int flag;
}HTNode, HuffmanTree[M];


//ѡ����ѡ����С��Ȩֵ
//���������ĵ�ַ 
//����ֵ��int n��СȨֵ���±�
int select(HuffmanTree ht, int n)//ѡ����СȨֵ�Ľ���±�
{
	int i, temp, min=0;
	for (i = 1; i <= n; i++)//���ó�ʼ�±��Ȩֵ
	{
		if (ht[i].flag == 0)
		{
			temp = ht[i].weight;//��ʼȨֵ
			min = i;//��ʼ�±�
			break;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (ht[i].flag == 0 && temp > ht[i].weight)//���ڵ�δ��ѡ�� ���� temp��ֵ���ڱ������Ľڵ�ʱ
		{
			temp = ht[i].weight;    //����С�Ľڵ���Ȩֵ����temp
			min = i;                //���ĸ�С�ڵ���±ꣻ
		}
	}
	ht[min].flag = 1;                //�����Ѿ�ѡ����С�ˣ���ô�ͽ���־λ��Ϊ1.��ʾѡ����
	return min;
}


//���������ĵ�ַ��Ȩֵ�ĸ���
void CreatHuffmanTree(HuffmanTree HT,int n)
{	 
	int m = 2 * n - 1;
	for (int i = n + 1; i <= m; i++)
	{
		int s1 = select(HT, i - 1); //(��С) //���� -1 ��Ϊ�����������ɵĽڵ�ֱ�Ӵ� 1 ~  ǰһ���ڵ� ��ʼ����
		int s2 = select(HT, i - 1);//(��С)
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1;
		HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//��ʼ������������Ȩֵ�ڵ�
//�������ṹ�������ַ���ڵ����
void huffinit(HuffmanTree HT,int n)
{
	if (n <= 1) { return NULL; }
	int m = 2 * n - 1; //������2n-1��Ԫ�أ�����2n-1���ڵ�
	for (int i = 1; i <= m; i++)
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
		HT[i].flag = 0;//����ı�־��ָ 0��δ��ѡ��������  1���Ѿ���ѡ����
	}
	printf("������%d��Ȩֵ\n", n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &HT[i].weight);
	}//ǰn���ڵ��Ѿ��������ˣ����湹�� n+1  ��  2n-1 �Ľڵ�

}


void printHuffmanTree(HuffmanTree ht, int n)//��ӡ��������
{
	printf("���  weigh  parent Lchild Rchild\n");
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