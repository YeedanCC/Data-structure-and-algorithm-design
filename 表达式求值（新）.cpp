#include<stdio.h>
#include<stdlib.h>
#define init_size 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FLASE 0
typedef int Status;
typedef char elemtype;
//���ȼ����ձ� 
int priority[7][7]={{1,1,-1,-1,-1,1,1},{1,1,-1,-1,-1,1,1},{1,1,1,1,-1,1,1},{1,1,1,1,-1,1,1},{-1,-1,-1,-1,-1,0,-2},{1,1,1,1,-2,1,1},{-1,-1,-1,-1,-1,-2,0}};
typedef struct
{
	elemtype *base;
	elemtype *top;
	int stacksize;
}sqstack;
sqstack yunsuanfu,num;//�����������
Status InitStack(sqstack &s)//����һ��ջ 
{
	s.base=(elemtype*)malloc(init_size*sizeof(elemtype));
	if(!s.base)
	{
		exit(OVERFLOW);
	}
	s.top=s.base;
	s.stacksize=init_size;
	return OK;
}
Status push(sqstack &s,elemtype c)//Ԫ����ջ 
{
	*(s.top)=c;
	s.top++;
}
Status empty(sqstack s)//�п� 
{
	if(s.top==s.base)
	{
		return TRUE;
	}
	else
	{
		return FLASE;
	}
}
Status pop(sqstack &s,elemtype &e)//����ջ��Ԫ�� 
{
	if(s.base==s.top)
	{
		return ERROR;
	}
	else
	{
		s.top--;
		e=(*(s.top));
		return OK;
	}
}
Status gettop(sqstack s,elemtype &e)//��ȡջ��Ԫ�� 
{
	if(empty(s))
	{
		return ERROR;
	}
	else
	{
		e=*(s.top-1);
		return OK;
	}
}
Status precede(elemtype a,elemtype b)//�����ȼ� 
{
	int i,j;
	switch(a)
	{
		case'+':i=0;break;
		case'-':i=1;break;
		case'*':i=2;break;
		case'/':i=3;break;
		case'(':i=4;break;
		case')':i=5;break;
		case'#':i=6;break;
	}
	switch(b)
	{
		case'+':j=0;break;
		case'-':j=1;break;
		case'*':j=2;break;
		case'/':j=3;break;
		case'(':j=4;break;
		case')':j=5;break;
		case'#':j=6;break;
	}
	return priority[i][j];
}
char Operator(elemtype a,elemtype theta,elemtype b)//��������
{
	int num1,num2,ans;
	elemtype sum;
	num1=a-'0';
	num2=b-'0';
	switch(theta)
	{
		case'+':ans=num1+num2;break;
		case'-':ans=num2-num1;break;
		case'*':ans=num1*num2;break;
		case'/':ans=num2/num1;break;
	}
	sum='0'+ans;
	return sum;
} 
int main()
{
	int count=0;
	elemtype temp,temp1;//��ʱװջ���ַ�,װ�����ַ� 
	int sum; 
	char a1,b1,result;
	InitStack(yunsuanfu);
	InitStack(num);
	elemtype str[100];
	scanf("%s",&str);
	push(yunsuanfu,'#');
	while(1)
	{
		if(str[count]>='0' && str[count]<='9')//���������ջ 
		{
			push(num,str[count]);
			count++;
		}
		else
		{
			gettop(yunsuanfu,temp);
			sum=precede(temp,str[count]);//�Ƚ������ջ���ַ��͵�ǰ�ַ� 
			switch(sum)
			{
				case -1://���ȼ��� 
				{
					push(yunsuanfu,str[count]);
					count++;
					break;
				}
				case 0://ȥ���ţ��������� 
				{
					pop(yunsuanfu,temp1);
					count++;
					break;
				}
				case 1:
				{
					pop(yunsuanfu,temp1);
					pop(num,a1);
					pop(num,b1);
					result=Operator(a1,temp1,b1);
					push(num,result);
				}
			}
		}
		if(str[count]=='\0')
		{
			break;
		}
	}
	gettop(num,result);
	printf("%c",result);
//	gettop(num,c);
//	printf("����ջ��Ԫ����%c\n",c);
//	gettop(yunsuanfu,c);
//	printf("�����ջ��Ԫ����%c\n",c);
//	while(!empty(num))
//	{
//		pop(num,c);
//		printf("%c ",c);
//	}
//	printf("\n");
//	while(!empty(yunsuanfu))
//	{
//		pop(yunsuanfu,c);
//		printf("%c ",c);
//	}
//	printf("\n");
}

