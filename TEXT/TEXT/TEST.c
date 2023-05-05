#include <stdio.h>
#include <stdlib.h>
#define MAXInt 0//��ʾ����ֵ������Ȩֵ�������� 
#define MVNum 100 //��󶥵���
//�ڽӾ����취 
typedef struct
{
	int vex[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;
}AMGraph;


int LocateVex(AMGraph G,int v) //��ѯ����V��ͼG�е��±�λ��
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vex[i])
			return i;
	}
}
void CreateUDN(AMGraph G)//���������� 
{
	int w;//Ȩֵ��Ϣ
	int v1, v2;//ĳ������������������ 
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	for (int i = 0; i < G.vexnum; i++)
		scanf_s("%d", &G.vex[i]);
	for (int i = 0; i < G.vexnum; i++)//��ʼ���ڽӾ�������Ԫ�س�ʼ��Ϊ����ֵ 
		for (int j = 0; j < G.arcnum; j++)
			G.arcs[i][j] = MAXInt;
	for (int i = 0; i < G.arcnum; i++)//�����ʾ�������������֮���Ȩֵ���ɱߵĸ����������� 
	{
		scanf_s("%d%d%d", &v1, &v2, &w);
		int m = LocateVex(G, v1);
		int n = LocateVex(G, v2);
		G.arcs[m][n] = w;
		G.arcs[n][m] = G.arcs[m][n];//���������еĶԳƾ��� 
	}
}
void PrintAMGraph(AMGraph G)
{
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
	printf("�ڽӾ���Ϊ��\n");
	PrintAMGraph(G);
	return 0;
}
/*
�������ݣ�ֻ��Ҫ��������ǰһ���Ԫ��ֵ��
5 6
1 2 3 4 5
1 2 3
1 4 6
2 3 2
2 5 8
3 1 1
3 4 5
*/