#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std; 

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;//定义的数据类型 

void buildtree(BiTree &t)
{
	char ch;
	cin>>ch;
	if(ch=='*') t=NULL;
	else{
		if((t=(BiTree)malloc(sizeof(BiTNode))))
		{
		t->data=ch;
		buildtree(t->lchild);
		buildtree(t->rchild);}
	}
}//建立二叉树的函数 

void PreOrderTraverse ( BiTree t )
{ //采用二叉链表存贮二叉树， visit( )是访问结点的函数
//本算法先序遍历以T为根结点指针的二叉树
	if (t) 
	{ //若二叉树不为空
	cout<<t->data;
	PreOrderTraverse(t->lchild); //先序遍历T的左子树
	PreOrderTraverse(t->rchild); //先序遍历T的右子树
}
} //PreOrderTraverse


void InOrderTraverse ( BiTree t )
{ // 采用二叉链表存贮二叉树， visit( )是访问结点的函数
// 本算法中序遍历以T为根结点指针的二叉树
if ( t )// 若二叉树不为空
{ 
InOrderTraverse ( t->lchild); // 中序遍历T的左子树
cout<<t->data;
InOrderTraverse ( t->rchild); // 中序遍历T的右子树
} } //InOrderTraverse

void PostOrderTraverse ( BiTree t) 
{ // 采用二叉链表存贮二叉树， visit( )是访问结点的函数
// 本算法后序遍历以T为根结点指针的二叉树
if ( t )
{ // 若二叉树不为空
PostOrderTraverse ( t->lchild); // 后序遍历左子树
PostOrderTraverse ( t->rchild); // 后序遍历右子树
cout<<t->data; // 访问根结点
} } //PostOrderTraverse

int main()
{
	BiTree t;
	buildtree(t);
	cout<<"先序序列为";
	PreOrderTraverse (t) ;
	cout<<endl;
	cout<<"中序序列为";
	InOrderTraverse (t);
	cout<<endl;
	cout<<"后序序列为";
	PostOrderTraverse(t);
	cout<<endl;
	return 0;
}
