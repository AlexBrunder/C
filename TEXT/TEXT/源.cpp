#include <stdio.h>
#include <stdlib.h>
//- - - - -ͼ���ڽӱ�洢��ʾ�� ��������
#define MAX 100   //��󶥵���
typedef struct ArcNode   //�߽��
{
    int adjvex;  //�߶���λ��	  
    struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode  //����
{
    char data;
    ArcNode* firstarc;
}VNode;
typedef struct
{
    VNode AdjList[MAX];
    int vexnum, arcnum;  //ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

int LocateVex(ALGraph G, char v) //����v����Ϣ���ҵ���Ӧ����
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
    printf("���붥�����ͱ���");
    scanf_s("%d%d", &G->vexnum, &G->arcnum);

    printf("���붥�����ݣ�");
    for (int c = 0; c < G->vexnum; ++c)
    {
        scanf_s(" %c", &G->AdjList[c].data,1);  //%cǰ��ո�����������οհ׷���
        G->AdjList[c].firstarc = NULL;       //����"%c"����ʱ���ո�͡�ת���ַ�������Ϊ��Ч�ַ�
    }
    printf("����ߵ���������\n");
    for (int k = 0; k < G->arcnum; ++k)
    {
        scanf_s(" %c %c",&v1,1,&v2,1);
        i = LocateVex(*G, v1);  //ȷ������λ��
        j = LocateVex(*G, v2);

        ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));  //p1����߱�ͷ��
        p1->adjvex = i;
        p1->nextarc = G->AdjList[j].firstarc;  //����ǰ�巨
        G->AdjList[j].firstarc = p1;

        ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = j;
        p2->nextarc = G->AdjList[i].firstarc;
        G->AdjList[i].firstarc = p2;
    }
    return 0;
}

void output_AL(ALGraph G)  //���
{
    for (int i = 0; i < G.vexnum; i++)
    {
        printf("����%c", G.AdjList[i].data);
        ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
        p = G.AdjList[i].firstarc;
        while (p != NULL)
        {
            printf("->%d", p->adjvex); //����±�
            //printf("->%c",G.AdjList[p->adjvex].data);  //�������Ԫ��
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
