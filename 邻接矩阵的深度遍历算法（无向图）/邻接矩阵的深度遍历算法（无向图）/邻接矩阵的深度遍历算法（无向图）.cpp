#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxInt 0//表示极大值
#define MVNum 100    //表示最大的顶点数


typedef struct {
	char vexs[MVNum];//顶点表
	int arcs[MVNum][MVNum]; //矩阵表
	int vexnum, arcnum;     //当前 点数 和 边数
}AMGraph;

int vis[MVNum] = { 0 }; //创建一个标记表表示某个元素已经被遍历过了 0：未被遍历    1：已被遍历
//邻接矩阵的深度遍历算法
//参数 图，int v 从第几个开始找（注意对应的下标为v-1）
void DFS(AMGraph G, int v)
{
	vis[v-1] = 1;
	printf("%c ", G.vexs[v-1]);
	for (int w = 0; w < G.vexnum; w++)
	{
		if ((vis[w]==0) && (G.arcs[v-1][w]==1)) //当标记表中未被遍历，且， 矩阵表中表示为有值或者1的元素（表示有边）
		{
			DFS(G, w+1);
		}
	}

}

//查找对应顶点在 顶点表中的下标
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


//构建无向网（矩阵表示法）
void CreateUDN(AMGraph& graph)
{
	char v1, v2;
	int w;
	printf("请输入你的总顶点数\n");
	scanf_s("%d", &graph.vexnum);
	printf("请输入你的总边数\n");
	scanf_s("%d", &graph.arcnum);


	//依次输入顶点表
	printf("请依次输入你的顶点\n");
	for (int i = 0; i < graph.vexnum; i++)
	{
		scanf_s(" %c", &graph.vexs[i], MVNum);
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
		scanf_s(" %c %c %d", &v1, 1, &v2, 1, &w);
		int m = LocateVex(graph, v1);
		int n = LocateVex(graph, v2);
		graph.arcs[m][n] = w;   /*因为无向网是沿着对角线对称的所以 可以让对应的另外一边相等*/
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
	//PrintAMGraph(G);
	DFS(G,2);
	return 0;
}
/*
测试数据（只需要输入矩阵的前一半的元素值）
6
6
A B C D E F
A B 1
A C 1
A D 1
B E 1
C E 1
D F 1

从第二个开始遍历的结果为
B A C E D F
/  2->1->3->4->5->6  /
*/
