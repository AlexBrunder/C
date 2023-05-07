#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxInt 0//��ʾ����ֵ
#define MVNum 100    //��ʾ���Ķ�����


typedef struct {
	char vexs[MVNum];//�����
	int arcs[MVNum][MVNum]; //�����
	int vexnum, arcnum;     //��ǰ ���� �� ����
}AMGraph;


//���Ҷ�Ӧ������ ������е��±�
int LocateVex(AMGraph& G, char u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (u == G.vexs[i])
		{
			return i;
		}
	}
}


//�����������������ʾ����
void CreateUDN(AMGraph& graph)
{
	char v1, v2;
	int w;
	printf("����������ܶ�����\n");
	scanf_s("%d", &graph.vexnum);
	printf("����������ܱ���\n");
	scanf_s("%d", &graph.arcnum);


	//�������붥���
	printf("������������Ķ���\n");
	for (int i = 0; i < graph.vexnum; i++)
	{
		scanf_s(" %c", &graph.vexs[i],MVNum);
	}

	//��ʼ������� ����ȫ������Ϊ����ֵ����ʾû�б�
	for (int i = 0; i < graph.vexnum; i++)
	{
		for (int j = 0; j < graph.vexnum; j++)
		{
			graph.arcs[i][j] = MaxInt;
		}
	}


	//�����ڽӾ���
	for (int k = 0; k < graph.arcnum; k++)
	{
		printf("���������һ�����������Ķ���\n");
		printf("�������������һ�����������Ķ���\n");
		printf("�����������ߵ�Ȩֵ\n");
		scanf_s(" %c %c %d",&v1,1,&v2,1,&w);
		int m = LocateVex(graph,v1);
		int n= LocateVex(graph,v2);
		graph.arcs[m][n] = w;   /*��Ϊ�����������ŶԽ��߶ԳƵ����� �����ö�Ӧ������һ�����*/
		graph.arcs[n][m] = graph.arcs[m][n];
	}
}


void PrintAMGraph(AMGraph& G)
{
	printf("\n");
	for (int i = 0; i < G.vexnum; i++)
	{
		printf(" %c ", G.vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.vexs[i]);
		for (int j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.arcs[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	AMGraph G;
	CreateUDN(G);
	PrintAMGraph(G);
	return 0;
}
/*
�������ݣ�ֻ��Ҫ��������ǰһ���Ԫ��ֵ��
5 
6
A B C D E
A B 3
A D 6
B C 2
B E 8
C A 1
C D 5
*/
