#include <stdio.h>
#include <stdlib.h>
#define MAXInt 0//表示极大值，用于权值（即网） 
#define MVNum 100 //最大顶点数
//邻接矩阵构造法 
typedef struct
{
	int vex[MVNum];//顶点表
	int arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;
}AMGraph;


int LocateVex(AMGraph G,int v) //查询顶点V在图G中的下标位置
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vex[i])
			return i;
	}
}
void CreateUDN(AMGraph G)//构建无向网 
{
	int w;//权值信息
	int v1, v2;//某条边依附的两个顶点 
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	for (int i = 0; i < G.vexnum; i++)
		scanf_s("%d", &G.vex[i]);
	for (int i = 0; i < G.vexnum; i++)//初始化邻接矩阵，所有元素初始化为极大值 
		for (int j = 0; j < G.arcnum; j++)
			G.arcs[i][j] = MAXInt;
	for (int i = 0; i < G.arcnum; i++)//这里表示输入的依附顶点之间的权值是由边的个数来决定的 
	{
		scanf_s("%d%d%d", &v1, &v2, &w);
		int m = LocateVex(G, v1);
		int n = LocateVex(G, v2);
		G.arcs[m][n] = w;
		G.arcs[n][m] = G.arcs[m][n];//无向网特有的对称矩阵 
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
	printf("邻接矩阵为：\n");
	PrintAMGraph(G);
	return 0;
}
/*
测试数据（只需要输入矩阵的前一半的元素值）
5 6
1 2 3 4 5
1 2 3
1 4 6
2 3 2
2 5 8
3 1 1
3 4 5
*/