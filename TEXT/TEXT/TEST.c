#include<stdio.h>
#include<stdlib.h>

//�������нڵ�Ķ���start
typedef struct Data
{
	char data;
	struct Data* Ltree;
	struct Data* Rtree;
}Data;
//�������Ķ���end

//������ջ���
typedef struct LinkStackNode
{
	Data* node;
	struct LinkStackNode* next;
}LinkStackNode, * LsNode;

//������ջ
typedef struct Linkstack
{
	LsNode top;                 //����ջ��ָ�룬ջ������������ɾ����һ��
	LsNode base;                //����ջ��ָ�룬�ǲ�������в����ɾ��Ԫ�ص�һ��
}LinkStack, * Ls;

// ����һ����ջ
void InitStack(Ls mystack);

//��ջ�в���Ԫ��e
void InsertStack(Ls mystack, Data* e);     //��ջ�в���Ԫ�ز�����ջ�����⵫����ջ�����⣬ֻ����ջ��������Ԫ��

//��ջ������ɾ��ջ��Ԫ�أ�����ջ��Ԫ�ص�ֵ��Ϊ��������ֵ����
Data* PopStack(Ls mystack);

void InitStack(Ls mystack)
{
	mystack->top = mystack->base = (LsNode)malloc(sizeof(LinkStackNode));
	mystack->base->next = NULL;
	printf("������ջ�ɹ�\n");
}



void InsertStack(Ls mystack, Data* e)            /*�¼���Ľڵ���ԶΪ��һ���ڵ㣬ͷָ��Ϊ���һ���ڵ�*/
{
	LsNode p = (LsNode)malloc(sizeof(LinkStackNode));    //�½�һ��ջ�ڵ㣬ջ�ڵ��е�����Ϊ��
	if (!p)                                              
	{
		printf("ERROR�������ڴ�ʧ��\n");
		return;
	}
	p->node = e;                                          //�����ݴ������ݽڵ�
	p->next = mystack->top;                               //���½ڵ��е�next��ָ��ջ��
	mystack->top = p;                                     //�޸�ջ��Ϊ�½ڵ�ĵ�ַ
}



Data* PopStack(Ls mystack)
{
	if (mystack->top->next != NULL)                   /* ջ��ͷָ��ָ�����һ���ڵ㣬���һ���ڵ��е�next��Ϊ��ֵ��ջ���ǵ�һ���ڵ� */
	{
		LsNode temp;//ջ�ڵ�ָ��  ջ�ڵ㣺��������ָ�룬ָ����һ���ڵ��ָ��
		Data* t;    //�½�һ��ָ������ָ��

		temp = mystack->top; //��ջ����ָ�루ջ�ĵ�һ���ڵ�ĵ�ַ�� ��ֵ��temp��tempָ����ջ�ĵ�һ���ڵ�
		t = temp->node;      //t�����˵�һһ��ջ�ڵ�����ݣ�����

		mystack->top = mystack->top->next;    //��ջ��ָ���޸�Ϊ ָ����һ���ڵ�
		free(temp);                           //�ͷ�ջ��    

		return t;                             //����ջ���ڵ������
	}
	return NULL;

}

/*       �����������㷨start                */
/*                                          */
//�����ڵ���㷨
//����ֵ��һ���ڵ�ĵ�ַ
//������һ��char��
Data* CreatData(char a)
{
	Data* Ndata = (Data*)malloc(sizeof(Data));
	Ndata->data = a;
	Ndata->Ltree = NULL;
	Ndata->Rtree = NULL;
	return Ndata;
}


//������������ķ�ʽ����������
// �������˳������ڵ㣬�սڵ��� # ��ʾ
//���������ĵ�ַ
//����ֵ�������ĵ�ַ
Data* CreatePreTree(Data* T)
{

	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = CreatData(ch);
		T->Ltree = CreatePreTree(T->Ltree);
		T->Rtree = CreatePreTree(T->Rtree);
	}
	return T;
}

//����������㷨������ڵ��ֵ��DLR
//���������ĵ�ַ
//����ֵ��0��Ϊ��ֵ 1���ɹ�
int PreOrderTraverse(Data* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		printf("%c", T->data);
		PreOrderTraverse(T->Ltree);
		PreOrderTraverse(T->Rtree);
	}
}

//����������㷨������ڵ��ֵ��LDR
//���������ĵ�ַ
//����ֵ��0��Ϊ��ֵ 1���ɹ�
int MidOrderTraverse(Data* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		MidOrderTraverse(T->Ltree);
		printf("%c", T->data);
		MidOrderTraverse(T->Rtree);

	}
}


//����������㷨������ڵ��ֵ��LRD
//���������ĵ�ַ
//����ֵ��0��Ϊ��ֵ 1���ɹ�
int BackOrderTraverse(Data* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		BackOrderTraverse(T->Ltree);
		BackOrderTraverse(T->Rtree);
		printf("%c\n", T->data);
	}
}

//���������������㷨
//���������ĵ�ַ
//����ֵ���������int
int Depth(Data* T)
{
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;//���Ϊ0
	}
	else
	{
		m = Depth(T->Ltree);
		n = Depth(T->Rtree);
		if (m > n)
		{
			return m + 1;
		}
		else
		{
			return n + 1;
		}
	}
}

//����Ҷ�ӽڵ�ĸ���
//���������ĵ�ַ
//����ֵ������int
void LeadCount(Data* T, int* i)
{
	if (T == NULL)
	{
		return 0;
	}
	if (T->Ltree == NULL && T->Rtree == NULL)
	{
		(*i)++;
	}
	LeadCount(T->Ltree, i);
	LeadCount(T->Rtree, i);
}



void MiddleOrderTraverse(Data* root, Ls mystack)
{


	//����������ȱ������������ڱ�������㣬�������������������������ı���Ҳ��ѭ����ҵ�ԭ��
	//����ջ��ʵ����������ķǵݹ��㷨


	Data* m = root;

	//���ж϶������ǲ���Ϊ��
	if (!root)
	{
		return;
	}

	while (1)
	{
		//�������ջ
		Data* temp;

		if (m)
		{
			InsertStack(mystack, m);
			m = m->Ltree;                        //����������������ֱ������������Ϊ�յĽ��
		}
		else
		{
			temp = PopStack(mystack);
			//������������Ϊ�յĽ�㣬����ǰ���Ԫ�ؽ�����ջ���������ǰ����ֵ��Ȼ��������ʵ�ǰ�ڵ����������
			//���������ǲ����ظ��ع��̼���������������ֱ��Ϊ�գ�Ȼ�������ǰջ��Ԫ�ص�ֵ��Ȼ�᷵����һ���Ԫ�أ�Ȼ��������ʵ�ǰ�ڵ���������������к�������ȷ��ص����ԣ�
			//��������վ������ʵ�ִ��㷨����ʵ�ַ�����һ�������ͨ����ջ��һ������ɵ�
			printf("%c", temp->data);
			m = temp->Rtree;

		}
		if ((mystack->top == mystack->base) && m == NULL) //��ջΪ�� �� ����Ϊ���� ʱ ����ѭ����
		{
			break;
		}
	}
}


void main()
{
	Data* FirstTree = (Data*)malloc(sizeof(Data));/*�������������˳������*/
	FirstTree = CreatePreTree(FirstTree);
	printf("\n");
	LinkStack Stack;
	Ls ls= &Stack;
	InitStack(ls);  //����һ����ջ
	MiddleOrderTraverse(FirstTree, ls);
	printf("\n");
	MidOrderTraverse(FirstTree);
}
