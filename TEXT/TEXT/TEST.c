#include<stdio.h>
#include<stdlib.h>

//二叉树中节点的定义start
typedef struct Data
{
	char data;
	struct Data* Ltree;
	struct Data* Rtree;
}Data;
//二叉树的定义end

//定义链栈结点
typedef struct LinkStackNode
{
	Data* node;
	struct LinkStackNode* next;
}LinkStackNode, * LsNode;

//定义链栈
typedef struct Linkstack
{
	LsNode top;                 //定义栈顶指针，栈顶是允许插入和删除的一端
	LsNode base;                //定义栈底指针，是不允许进行插入和删除元素的一端
}LinkStack, * Ls;

// 创建一个空栈
void InitStack(Ls mystack);

//向栈中插入元素e
void InsertStack(Ls mystack, Data* e);     //向栈中插入元素不存在栈满问题但存在栈空问题，只能在栈顶处插入元素

//若栈不空则删除栈顶元素，并将栈顶元素的值作为函数返回值返回
Data* PopStack(Ls mystack);

void InitStack(Ls mystack)
{
	mystack->top = mystack->base = (LsNode)malloc(sizeof(LinkStackNode));
	mystack->base->next = NULL;
	printf("创建空栈成功\n");
}



void InsertStack(Ls mystack, Data* e)            /*新加入的节点永远为第一个节点，头指针为最后一个节点*/
{
	LsNode p = (LsNode)malloc(sizeof(LinkStackNode));    //新建一个栈节点，栈节点中的数据为树
	if (!p)                                              
	{
		printf("ERROR：申请内存失败\n");
		return;
	}
	p->node = e;                                          //将数据传入数据节点
	p->next = mystack->top;                               //将新节点中的next域指向栈顶
	mystack->top = p;                                     //修改栈顶为新节点的地址
}



Data* PopStack(Ls mystack)
{
	if (mystack->top->next != NULL)                   /* 栈的头指针指向最后一个节点，最后一个节点中的next域为空值，栈顶是第一个节点 */
	{
		LsNode temp;//栈节点指针  栈节点：包括树的指针，指向下一个节点的指针
		Data* t;    //新建一个指向树的指针

		temp = mystack->top; //将栈顶的指针（栈的第一个节点的地址） 赋值给temp。temp指向了栈的第一个节点
		t = temp->node;      //t保存了第一一个栈节点的数据（树）

		mystack->top = mystack->top->next;    //将栈顶指针修改为 指向下一个节点
		free(temp);                           //释放栈顶    

		return t;                             //返回栈顶节点的数据
	}
	return NULL;

}

/*       二叉树创建算法start                */
/*                                          */
//创建节点的算法
//返回值：一个节点的地址
//参数：一个char数
Data* CreatData(char a)
{
	Data* Ndata = (Data*)malloc(sizeof(Data));
	Ndata->data = a;
	Ndata->Ltree = NULL;
	Ndata->Rtree = NULL;
	return Ndata;
}


//按照先序排序的方式创建二叉树
// 按先序的顺序输入节点，空节点用 # 表示
//参数：树的地址
//返回值：新树的地址
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

//先序遍历的算法（输出节点的值）DLR
//参数：树的地址
//返回值：0：为空值 1：成功
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

//中序遍历的算法（输出节点的值）LDR
//参数：树的地址
//返回值：0：为空值 1：成功
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


//后序遍历的算法（输出节点的值）LRD
//参数：树的地址
//返回值：0：为空值 1：成功
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

//计算二叉树的深度算法
//参数：树的地址
//返回值：树的深度int
int Depth(Data* T)
{
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;//深度为0
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

//计算叶子节点的个数
//参数：树的地址
//返回值：个数int
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


	//中序遍历，先遍历左子树，在遍历根结点，最后遍历右子树，对左右子树的遍历也遵循左根右的原则
	//利用栈来实现中序遍历的非递归算法


	Data* m = root;

	//先判断二叉树是不是为空
	if (!root)
	{
		return;
	}

	while (1)
	{
		//根结点入栈
		Data* temp;

		if (m)
		{
			InsertStack(mystack, m);
			m = m->Ltree;                        //先沿着左子树深入直到到达左子树为空的结点
		}
		else
		{
			temp = PopStack(mystack);
			//当到达左子树为空的结点，将当前结点元素进行退栈，即输出当前结点的值，然后继续访问当前节点的右子树。
			//整个过程是不断重复地过程即沿着左子树深入直至为空，然会输出当前栈顶元素的值，然会返回上一结点元素，然后继续访问当前节点的右子树，所以有后深入的先返回的特性，
			//可以运用站的特性实现此算法，而实现返回上一个结点是通过退栈这一操作完成的
			printf("%c", temp->data);
			m = temp->Rtree;

		}
		if ((mystack->top == mystack->base) && m == NULL) //当栈为空 和 遍历为到空 时 结束循环；
		{
			break;
		}
	}
}


void main()
{
	Data* FirstTree = (Data*)malloc(sizeof(Data));/*按照线序遍历的顺序构造树*/
	FirstTree = CreatePreTree(FirstTree);
	printf("\n");
	LinkStack Stack;
	Ls ls= &Stack;
	InitStack(ls);  //构造一个空栈
	MiddleOrderTraverse(FirstTree, ls);
	printf("\n");
	MidOrderTraverse(FirstTree);
}
