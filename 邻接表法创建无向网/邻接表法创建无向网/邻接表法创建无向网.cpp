#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MVNum 100
//顶点节点 数组类型
typedef struct VNode {
	int data; //顶点信息
	struct ArcNode* firstarc; //指向对应边节点（边节点中存储对应的顶点信息）
}VNode,AdjList[MVNum];

//定义边（弧）节点
typedef struct ArcNode {
	int adjvex; //这条边所指向的顶点在顶点数组的位置
	struct ArcNode* nextarc;//指向下一个边节点的指针
	int info;      //存放权值
}ArcNode;


//定义图节点
typedef struct {
	VNode AdjList[MVNum];    //相当于顶点信息数组（结构体数组）
	int vexnum, arcnum;    //当前的顶点数 和 边（弧度数） 需要输入所得
}ALGraph;

//查找顶点表对应值的下标
//参数：图,要找的值
//返回值：int 下标
int LocateVex(ALGraph G, int v) //根据v点信息，找到相应坐标
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.AdjList[i].data == v)
		{
			return i;
		}
	}
}

//用邻接表创建无向图算法
void CreateUDG(ALGraph &G)
{
	int v1, v2;
	int m, n;
	printf("请输入有多少顶点数\n");
	scanf_s("%d",&G.vexnum);
	printf("请输入有多少边（弧）数\n");
	scanf_s("%d",&G.arcnum);

	for (int i = 0; i < G.vexnum; i++)
	{  
		//给顶点表赋初值
		scanf_s("%d",&G.AdjList[i].data);
		G.AdjList[i].firstarc = NULL;
	}


	for (int k = 0; k < G.arcnum; k++)
	{
		printf("请输入一条边依附的两个顶点\n");
		scanf_s("%d%d",&v1,&v2);
		m = LocateVex(G,v1);
		n = LocateVex(G,v2);
		ArcNode* p1=(ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = m;
		p1->nextarc = G.AdjList[n].firstarc;
		G.AdjList[n].firstarc = p1;

		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = n;
		p2->nextarc = G.AdjList[m].firstarc;
		G.AdjList[m].firstarc = p2;
	}
}


//输出对应的邻接表
void PrintfALG(ALGraph &G)
{
	ArcNode* p;
	
	printf("\n");
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%d ",G.AdjList[i].data);
		p = G.AdjList[i].firstarc;
		while (p)
		{
			printf("%d ", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}

int main()
{
	ALGraph graph;
	CreateUDG(graph);
	PrintfALG(graph);
	return 0;
}