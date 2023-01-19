#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�������ݽṹ��lengthΪ˳���ʵ��Ԫ�ظ���
#define MAXSIZE 50

typedef struct
{
	int elem[MAXSIZE];
	int length;
}SeqList;

//------------------����˳���------------------
void create(SeqList* s)
{
	int n,i=0;
	s->length = 0;
	printf("����˳����Ԫ��:\n");
	do
	{   scanf("%d", &n);
		s->elem[i] = n;
		i++;
		s->length++;
	}while(n!=0);
	s->elem[i-1] = NULL;
	s->length = s->length-1;
}


//--------------------�ϲ��㷨--------------------
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
	//����LA�ȱ�LB��ʱ������LAʣ�µ�Ԫ�ظ�����LC
	while (i < LA->length)
	{
		LC->elem[k] = LA->elem[i];
		i++; k++;
	}
		//����LB�ȱ�LA��ʱ������LAʣ�µ�Ԫ�ظ�����LC
	while (j < LB->length)
	{
		LC->elem[k] = LB->elem[j];
		j++; k++;
	}
	LC->length = LA->length + LB->length;
}
//ɾ���ظ�������
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
//--------------------�������Ԫ��--------------------
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
		printf("˳���LA��Ԫ��Ϊ:\n");
		print(&LA);
		printf("˳���LB��Ԫ��Ϊ:\n");
	    print(&LB);
	printf("--------------��ʼ�ϲ�˳���------------\n");
	merge(&LA, &LB, &LC);
	printf("�ϲ����LC��Ԫ��Ϊ:\n");
	print(&LC);
	printf("ɾ���ظ�Ԫ�غ��LC\n"); 
	delete_elem(&LC) ;
	print(&LC);
	return 0;
}

//La=3, 5, 8, 11 Lb=2, 6, 8, 9, 11, 15, 20 Lc=2, 3, 5, 6, 8, 8, 9, 11, 11, 15, 20 
