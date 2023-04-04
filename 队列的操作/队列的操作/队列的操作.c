#include<stdio.h>
#include<stdlib.h>

//˳����еĶ���
#define MAXQSIZE 100
typedef struct {
	int* base;
	int length;
	int front;
	int rear;
}SqQueue,*Squeue;

//�����еĶ���
typedef struct Qnode {
	int data;
	struct Qnode* next;
}Qnode,*QuenePtr;

typedef struct {
	QuenePtr front; //ͷ�ڵ㣬ָ��ͷ�ڵ�
	QuenePtr rear;  //β�ڵ㣬ָ�����һ��Ԫ��
}LinkQueue;

//��ʼ�����еĲ���
//����ֵ�����еĵ�ַ
//����:��
Squeue Initqueue()
{
	Squeue Q;
	Q = (Squeue)malloc(sizeof(SqQueue));
	Q->base = (int*)malloc(MAXQSIZE * sizeof(int));
	Q->front = Q->rear = 0;
	Q->length = 0;
	return Q;
}

//���еĲ��� ���еĲ���ʵ�ڶ��е�β�����е�
//���������еĵ�ַ�������ֵ
//����ֵ���µĶ��е�ַ
Squeue inserE(Squeue SU, int e)
{
	if((SU->rear +1)%MAXQSIZE ==SU->front)
	{
		return SU;
	}
	*(SU->base+SU->length) = e;
	SU->rear = (SU->rear + 1) % MAXQSIZE;
	SU->length++;
	return SU;
}

//ɾ��Ԫ�أ�˳����дӶ�ͷɾ��Ԫ��
//ɾ�����֮��ͷָ��++
//���������еĵ�ַ
//����ֵ����ɾ����Ԫ��
int deleE(Squeue SU)
{
	int x;
	x = *(SU->base + SU->front);
	SU->front = (SU->front + 1) % MAXQSIZE;
	return x;
}

//�����еĳ�ʼ��
//��������
//����ֵ�������еĵ�ַ;
LinkQueue* InitQueue()
{
	LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Q->front = Q->rear = (QuenePtr)malloc(sizeof(Qnode));
	Q->front->next = NULL;
	return Q;
}

//�����е���Ӳ���
//�����е���ӣ�ֻ���ڶ�β���У�
//�����������еĵ�ַ����ӵ�ֵ��
//����ֵ���µĶ��еĵ�ַ��
LinkQueue* EnQueue(LinkQueue *SU,int e)
{
	//�½�һ���ڵ㲢��nextΪ��ֵ
	QuenePtr p=(QuenePtr)malloc(sizeof(Qnode));
	p->data = e;
	p->next = NULL;
	//β�������nextָ���µĽڵ�
	SU->rear->next = p;
	//����βָ���ָ��
	SU->rear = p;
	return SU;
	
}

//�����еĳ��Ӳ���
//�����еĳ��ӣ�ֻ���ڶ�ͷ���У�Ҳ������Ԫ�ڵ�
//�����������еĵ�ַ��
//����ֵ���µĶ��еĵ�ַ��
LinkQueue* DeQueue(LinkQueue* SU)
{
	if (SU->front = SU->rear)
	{
		return SU;
	}
	QuenePtr p = (QuenePtr)malloc(sizeof(Qnode));//��ʼ������
	p = SU->front->next; //��ȡ��Ԫ�ڵ�ĵ�ַ
	int e = p->data;      //������Ԫ�ڵ��Ԫ��
	SU->front->next = p->next;  //����ͷ�ڵ��е�next������ָ����һ��Ԫ��(��Ԫ�ڵ�ĺ�һ������)  

	if (SU->rear == p) //���βָ����ڣ�ͷ�ڵ���nextָ�����һ���ڵ㣨ɾ���������һ��Ԫ�أ�      
	{
		SU->rear = SU->front; //��ͷͷָ�� �����ڡ� βָ�루�ն��У�
	}

	free(p);//ɾ����Ԫ�ڵ�
	return SU;
}

//�������еĶ�ͷԪ��
//ͷָ��ָ��ľ���ͷ�ڵ㣬ͷ�ڵ��д洢����Ԫ�ڵ�ĵ�ַ��
//�����������еĵ�ַ��
//����ֵ��int e 
int getHead(LinkQueue *SU)
{
	return SU->front->next->data;
}

void main()
{
	/*˳����в���
	Squeue W;
	W = Initqueue();
	W=inserE(W, 6); 
	W = inserE(W, 7);
	int a = deleE(W);
	printf("%d\n", W->front);
	printf("a=%d\n", a);
	*/

	//��ʽ���в���
	LinkQueue* Q = InitQueue();
	int b[10];
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &b[i]);
	}
	
	for (int i = 0; i < 10; i++)
	{
		Q = EnQueue(Q, b[i]);
	}
	//Q = DeQueue(Q);
	int e = getHead(Q);
	//printf("%d\n", Q->front->next->data);
	printf("��ͷ��Ԫ��Ϊ��%d\n", e);
	QuenePtr index = (QuenePtr)malloc(sizeof(Qnode));
	index = Q->front->next;//��ȡ��Ԫ�ڵ�ĵ�ַ
	for (int i = 0; i < 10; i++)
	{
		printf("��ĵ�%d��Ԫ��Ϊ��%d\n", i+1,index->data);
		index = index->next;
	}
}


