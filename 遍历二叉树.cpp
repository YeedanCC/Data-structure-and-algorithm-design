#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std; 

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;//������������� 

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
}//�����������ĺ��� 

void PreOrderTraverse ( BiTree t )
{ //���ö������������������ visit( )�Ƿ��ʽ��ĺ���
//���㷨���������TΪ�����ָ��Ķ�����
	if (t) 
	{ //����������Ϊ��
	cout<<t->data;
	PreOrderTraverse(t->lchild); //�������T��������
	PreOrderTraverse(t->rchild); //�������T��������
}
} //PreOrderTraverse


void InOrderTraverse ( BiTree t )
{ // ���ö������������������ visit( )�Ƿ��ʽ��ĺ���
// ���㷨���������TΪ�����ָ��Ķ�����
if ( t )// ����������Ϊ��
{ 
InOrderTraverse ( t->lchild); // �������T��������
cout<<t->data;
InOrderTraverse ( t->rchild); // �������T��������
} } //InOrderTraverse

void PostOrderTraverse ( BiTree t) 
{ // ���ö������������������ visit( )�Ƿ��ʽ��ĺ���
// ���㷨���������TΪ�����ָ��Ķ�����
if ( t )
{ // ����������Ϊ��
PostOrderTraverse ( t->lchild); // �������������
PostOrderTraverse ( t->rchild); // �������������
cout<<t->data; // ���ʸ����
} } //PostOrderTraverse

int main()
{
	BiTree t;
	buildtree(t);
	cout<<"��������Ϊ";
	PreOrderTraverse (t) ;
	cout<<endl;
	cout<<"��������Ϊ";
	InOrderTraverse (t);
	cout<<endl;
	cout<<"��������Ϊ";
	PostOrderTraverse(t);
	cout<<endl;
	return 0;
}
