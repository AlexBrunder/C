#include <stdio.h>
#include <stdlib.h>
//- - - - -图的邻接表存储表示－ －－－－
#define MAX 100   //最大顶点数
typedef struct ArcNode   //边结点
{
    int adjvex;  //边顶点位置	  
    struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode  //顶点
{
    char data;
    ArcNode* firstarc;
}VNode;
typedef struct
{
    VNode AdjList[MAX];
    int vexnum, arcnum;  //图的当前顶点数和边数
}ALGraph;

int LocateVex(ALGraph G, char v) //根据v点信息，找到相应坐标
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.AdjList[i].data == v)
            return i;
    }
    return -1;
}
int CreateUDG(ALGraph* G)
{
    char v1, v2;
    int i, j;
    ArcNode* p1, * p2;
    printf("输入顶点数和边数");
    scanf_s("%d%d", &G->vexnum, &G->arcnum);

    printf("输入顶点数据：");
    for (int c = 0; c < G->vexnum; ++c)
    {
        scanf_s(" %c", &G->AdjList[c].data);  //%c前面空格就是用来屏蔽空白符的
        G->AdjList[c].firstarc = NULL;       //在用"%c"输入时，空格和“转义字符”均作为有效字符
    }
    printf("输入边的两个顶点\n");
    for (int k = 0; k < G->arcnum; ++k)
    {
        scanf_s(" %c %c", &v1, &v2);
        i = LocateVex(*G, v1);  //确定顶点位置
        j = LocateVex(*G, v2);

        p1 = (ArcNode*)malloc(sizeof(ArcNode));  //p1插入边表头部
        p1->adjvex = i;
        p1->nextarc = G->AdjList[j].firstarc;  //链表前插法
        G->AdjList[j].firstarc = p1;

        p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = j;
        p2->nextarc = G->AdjList[i].firstarc;
        G->AdjList[i].firstarc = p2;
        free(p1);
        free(p2);
    }
    return 0;
}

void output_AL(ALGraph G)  //输出
{
    for (int i = 0; i < G.vexnum; i++)
    {
        printf("顶点%c", G.AdjList[i].data);
        ArcNode* p = G.AdjList[i].firstarc;
        while (p != NULL)
        {
            printf("->%d", p->adjvex); //输出下标
            //printf("->%c",G.AdjList[p->adjvex].data);  //输出顶点元素
            p = p->nextarc;
        }
        printf("\n");
    }
}
int main()
{
    ALGraph G;
    CreateUDG(&G);
    output_AL(G);
    return 0;
}
