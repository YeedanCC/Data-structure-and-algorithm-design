#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 256
int m[maxn][maxn];

void DoubleEvenMagic(int n)                  //双偶数阶幻方
{
    memset(m,0,sizeof(m));                   //幻方清零
    for(int i=1, x=0, y=0; i<=n*n; i++)      //依次按顺序赋初值
    {
        m[x][y]=i;
        y++;
        if(y>n-1) {x++; y-=n;}
    }
    for(int i=0; i<n; i++)                   //将幻方分解成m*m个4阶幻方，并将每个4阶幻方的对角线元素换成其互补数
        for(int j=0; j<n; j++)
            if(i%4==0 && j%4==0)             //左对角线
                for(int k=0; k<4; k++)
                    m[i+k][j+k]=(n*n+1)-m[i+k][j+k];
            else if(i%4==3 &&j%4==0)         //右对角线
                for(int k=0; k<4; k++)
                    m[i-k][j+k]=(n*n+1)-m[i-k][j+k];
}

bool Check(int n)
{
    int cnt=n*(n*n+1)/2;                                //每行每列以及对角线之和
    for(int i=0; i<n; i++)
    {
        int sum_row=0,sum_line=0;
        for(int j=0; j<n; j++)
            {
                sum_row+=m[i][j];                       //检查各行
                sum_line+=m[j][i];                      //检查各列
            }
        if(sum_row!=cnt || sum_line!=cnt) return false;
    }
    int sum_left=0,sum_right=0;
    for(int i=0; i<n; i++)
    {
        sum_left+=m[i][i];                              //检查左对角线
        sum_right+=m[n-i-1][i];                         //检查右对角线
    }
    if(sum_left!=cnt || sum_right!=cnt) return false;
    return true;
}

void print(int n)                                       //按格式输出
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
   
    if(!(n%4)) {DoubleEvenMagic(n); if(Check(n)) print(n);}     //输出双偶数阶幻方
    return 0;
}
