#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//定义数据结构，length为顺序表实际元素个数
#define MAXSIZE 50

typedef struct
{
	int elem[MAXSIZE];
	int length;
}SeqList;

//------------------创建顺序表------------------
void create(SeqList* s)
{
	int n,i=0;
	s->length = 0;
	printf("输入顺序表的元素:\n");
	do
	{   scanf("%d", &n);
		s->elem[i] = n;
		i++;
		s->length++;
	}while(n!=0);
	s->elem[i-1] = NULL;
	s->length = s->length-1;
}


//--------------------合并算法--------------------
void merge(SeqList* LA, SeqList* LB, SeqList* LC)
{
	int i, j, k;
	i=0; j=0; k=0;
	while (i < LA->length && j < LB->length)
	{
		if (LA->elem[i] <= LB->elem[j])
		{
			LC->elem[k] = LA->elem[i];
			i++; k++;
		}
		else
		{
			LC->elem[k] = LB->elem[j];
			j++; k++;
		}
	}
	//当表LA比表LB长时，将表LA剩下的元素赋给表LC
	while (i < LA->length)
	{
		LC->elem[k] = LA->elem[i];
		i++; k++;
	}
		//当表LB比表LA长时，将表LA剩下的元素赋给表LC
	while (j < LB->length)
	{
		LC->elem[k] = LB->elem[j];
		j++; k++;
	}
	LC->length = LA->length + LB->length;
}
//删除重复的数字
void delete_elem(SeqList* L) 
{
  int i, k=0;
  for(i=1;i < L->length;i++)
  {
  	if( L->elem[i] == L->elem[i-1])
   {
   		for(k=i+1 ; k < L->length ; k++)
   		{
		   L->elem[k-1]=L->elem[k];
	    }
	    L->length--;
	    i=0;
    }
    else continue;
  }
	
}
//--------------------输出所有元素--------------------
void print(SeqList* L)
{
	int i;
	for (i=0 ; i < L->length ; i++)
		printf("%d  ", L->elem[i]);
	printf("\n");
}
 
int main()
{
	SeqList LA, LB, LC;
	create(&LA);
	create(&LB);
		printf("顺序表LA的元素为:\n");
		print(&LA);
		printf("顺序表LB的元素为:\n");
	    print(&LB);
	printf("--------------开始合并顺序表------------\n");
	merge(&LA, &LB, &LC);
	printf("合并结果LC的元素为:\n");
	print(&LC);
	printf("删除重复元素后的LC\n"); 
	delete_elem(&LC) ;
	print(&LC);
	return 0;
}

//La=3, 5, 8, 11 Lb=2, 6, 8, 9, 11, 15, 20 Lc=2, 3, 5, 6, 8, 8, 9, 11, 11, 15, 20 
