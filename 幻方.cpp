#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 256
int m[maxn][maxn];

void DoubleEvenMagic(int n)                  //˫ż���׻÷�
{
    memset(m,0,sizeof(m));                   //�÷�����
    for(int i=1, x=0, y=0; i<=n*n; i++)      //���ΰ�˳�򸳳�ֵ
    {
        m[x][y]=i;
        y++;
        if(y>n-1) {x++; y-=n;}
    }
    for(int i=0; i<n; i++)                   //���÷��ֽ��m*m��4�׻÷�������ÿ��4�׻÷��ĶԽ���Ԫ�ػ����以����
        for(int j=0; j<n; j++)
            if(i%4==0 && j%4==0)             //��Խ���
                for(int k=0; k<4; k++)
                    m[i+k][j+k]=(n*n+1)-m[i+k][j+k];
            else if(i%4==3 &&j%4==0)         //�ҶԽ���
                for(int k=0; k<4; k++)
                    m[i-k][j+k]=(n*n+1)-m[i-k][j+k];
}

bool Check(int n)
{
    int cnt=n*(n*n+1)/2;                                //ÿ��ÿ���Լ��Խ���֮��
    for(int i=0; i<n; i++)
    {
        int sum_row=0,sum_line=0;
        for(int j=0; j<n; j++)
            {
                sum_row+=m[i][j];                       //������
                sum_line+=m[j][i];                      //������
            }
        if(sum_row!=cnt || sum_line!=cnt) return false;
    }
    int sum_left=0,sum_right=0;
    for(int i=0; i<n; i++)
    {
        sum_left+=m[i][i];                              //�����Խ���
        sum_right+=m[n-i-1][i];                         //����ҶԽ���
    }
    if(sum_left!=cnt || sum_right!=cnt) return false;
    return true;
}

void print(int n)                                       //����ʽ���
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(j==n-1) printf("%4d\n",m[i][j]);
            else printf("%4d",m[i][j]);
}

int main()
{ 
    printf("8\n");
    ios::sync_with_stdio(false);
    int n=8;
   
    if(!(n%4)) {DoubleEvenMagic(n); if(Check(n)) print(n);}     //���˫ż���׻÷�
    return 0;
}
