#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
typedef struct lnode
{
	int num;
	struct lnode *next;
}change,*linklist;
linklist head,tail;

void createlist(int m)
{
	int i;
	linklist p,q;
	head=(linklist)malloc(sizeof(change));
	q=(linklist)malloc(sizeof(change));
	head->next=q;
	q->num=1;
	for(i=2;i<=m;i++)
	{
		p=(linklist)malloc(sizeof(change));
		p->num=i;
		q->next=p;
		q=p;
	}
	p->next=head->next;
}

void outlist(int s,int n,int m)
{
	int i,j;
	linklist p,q;
	p = head->next;
	for(j=1;j<s;j++)
	{
		p=p->next;
    }
    //printf("sp = %d\n",p->num);
    for(i=1;i<n-1;i++)
    {
    	p=p->next;
    	
	}
	//printf("np = %d\n",p->num);
	if(s==1)
	{
		q=p;
		printf("%d ",q->num);
		q=p->next;
		while(p->num !=m)
	{
		if(q->num!=1) printf("%d ",q->num);
		p->next=q->next;
	//	printf("pnn=%d qn = %d\n",p->next->num,q->next->num);
		for(i=1;i<=n-1;i++)
		{
			p=p->next;
		}
		q=p->next;
	}
	}
	else q=p->next;
	/*if (q==p)
	{
		printf("%d ",q->num);
		p->next=q->next;
		for(i=1;i<=n-1;i++)
		{
			p=p->next;
		}
		q=p->next;
	}
	printf("%d\n",q->num);
	}*/

	while(q!=p)
	{
		printf("%d ",q->num);
		p->next=q->next;
	//	printf("pnn=%d qn = %d\n",p->next->num,q->next->num);
		for(i=1;i<=n-1;i++)
		{
			p=p->next;
		}
		q=p->next;
	}
	printf("%d\n",q->num);
}

int main()
{
	int m,s,n;
	printf("输入总数m，第s个结点开始，输出计数到n结点的编号");
	scanf("%d%d%d",&m,&s,&n);
	createlist(m);
	printf("出队的编号");
	outlist(s,n,m);
	return 0;
}

 
