#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxInt 0//��ʾ����ֵ
#define MVNum 100    //��ʾ���Ķ�����


typedef struct {
	int vexs[MVNum];//�����
	int arcs[MVNum][MVNum]; //�����
	int vexnum, arcnum;     //��ǰ ���� �� ����
}AMGraph;


//���Ҷ�Ӧ������ ������е��±�
int LocateVex(AMGraph& G, int u)
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
	int v1, v2;
	int w;
	printf("����������ܶ�����\n");
	scanf_s("%d", &graph.vexnum);
	printf("����������ܱ���\n");
	scanf_s("%d", &graph.arcnum);


	//�������붥���
	printf("������������Ķ���\n");
	for (int i = 0; i < graph.vexnum; i++)
	{
		scanf_s("%d", &graph.vexs[i]);
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
		scanf_s("%d%d%d",&v1,&v2,&w);
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
1 2 3 4 5
1 2 3
1 4 6
2 3 2
2 5 8
3 1 1
3 4 5
*/
