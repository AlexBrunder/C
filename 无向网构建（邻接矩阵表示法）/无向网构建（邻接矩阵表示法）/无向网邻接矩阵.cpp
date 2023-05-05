#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxInt 0//表示极大值
#define MVNum 100    //表示最大的顶点数


typedef struct {
	int vexs[MVNum];//顶点表
	int arcs[MVNum][MVNum]; //矩阵表
	int vexnum, arcnum;     //当前 点数 和 边数
}AMGraph;


//查找对应顶点在 顶点表中的下标
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


//构建无向网（矩阵表示法）
void CreateUDN(AMGraph& graph)
{
	int v1, v2;
	int w;
	printf("请输入你的总顶点数\n");
	scanf_s("%d", &graph.vexnum);
	printf("请输入你的总边数\n");
	scanf_s("%d", &graph.arcnum);


	//依次输入顶点表
	printf("请依次输入你的顶点\n");
	for (int i = 0; i < graph.vexnum; i++)
	{
		scanf_s("%d", &graph.vexs[i]);
	}

	//初始化矩阵表 将他全部设置为极大值，表示没有边
	for (int i = 0; i < graph.vexnum; i++)
	{
		for (int j = 0; j < graph.vexnum; j++)
		{
			graph.arcs[i][j] = MaxInt;
		}
	}


	//构造邻接矩阵
	
	for (int k = 0; k < graph.arcnum; k++)
	{
		printf("请输入你的一条边所依附的顶点\n");
		printf("请输入你的另外一条边所依附的顶点\n");
		printf("请输入这条边的权值\n");
		scanf_s("%d%d%d",&v1,&v2,&w);
		int m = LocateVex(graph,v1);
		int n= LocateVex(graph,v2);
		graph.arcs[m][n] = w;   /*因为无向网是沿着对角线对称的所以 可以让对应的另外一边相等*/
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
测试数据（只需要输入矩阵的前一半的元素值）
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
