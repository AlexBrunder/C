#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MVNum 100
//����ڵ� ��������
typedef struct VNode {
	int data; //������Ϣ
	struct ArcNode* firstarc; //ָ���Ӧ�߽ڵ㣨�߽ڵ��д洢��Ӧ�Ķ�����Ϣ��
}VNode,AdjList[MVNum];

//����ߣ������ڵ�
typedef struct ArcNode {
	int adjvex; //��������ָ��Ķ����ڶ��������λ��
	struct ArcNode* nextarc;//ָ����һ���߽ڵ��ָ��
	int info;      //���Ȩֵ
}ArcNode;


//����ͼ�ڵ�
typedef struct {
	VNode AdjList[MVNum];    //�൱�ڶ�����Ϣ���飨�ṹ�����飩
	int vexnum, arcnum;    //��ǰ�Ķ����� �� �ߣ��������� ��Ҫ��������
}ALGraph;

//���Ҷ�����Ӧֵ���±�
//������ͼ,Ҫ�ҵ�ֵ
//����ֵ��int �±�
int LocateVex(ALGraph G, int v) //����v����Ϣ���ҵ���Ӧ����
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.AdjList[i].data == v)
		{
			return i;
		}
	}
}

//���ڽӱ�������ͼ�㷨
void CreateUDG(ALGraph &G)
{
	int v1, v2;
	int m, n;
	printf("�������ж��ٶ�����\n");
	scanf_s("%d",&G.vexnum);
	printf("�������ж��ٱߣ�������\n");
	scanf_s("%d",&G.arcnum);

	for (int i = 0; i < G.vexnum; i++)
	{  
		//���������ֵ
		scanf_s("%d",&G.AdjList[i].data);
		G.AdjList[i].firstarc = NULL;
	}


	for (int k = 0; k < G.arcnum; k++)
	{
		printf("������һ������������������\n");
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


//�����Ӧ���ڽӱ�
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