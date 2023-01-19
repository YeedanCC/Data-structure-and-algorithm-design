#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXSIZE 100
using namespace std;

typedef int KeyType;

typedef struct {
	KeyType key; //关键字域
}RedType;

typedef struct
{
	RedType r[MAXSIZE + 1];
	int length;
}SqList, * List;

//折半插入排序 
void BiInsertionSort(SqList& L)// BInsertSort
{
	for (int i = 2; i <= L.length; ++i)
	{
		L.r[0].key = L.r[i].key; // 将 L.r[i] 暂存到 L.r[0]
		int low = 1;
		int high = i - 1;
		while (low <= high)
		{
			int m = (low + high) / 2; // 折半
			if (L.r[0].key < L.r[m].key)
				high = m - 1; // 插入点在低半区
			else low = m + 1; // 插入点在高半区
		} //在 L.r[1..i-1]中折半查找插入位置；
		for (int j = i - 1; j >= high + 1; --j)
			L.r[j + 1] = L.r[j]; // 记录后移
		L.r[high + 1] = L.r[0]; // 插入	
	} // for	
	for (int i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i].key);
	}
}

//快速排序
int Partition(SqList& L, int low, int high) //一趟快速排序
{
	L.r[0] = L.r[low]; //用子表的第一个记录作枢轴记录
	int pivotkey = L.r[low].key;
	while (low < high)
	{ //从表的两端交替地向中间扫描
		while (low < high && L.r[high].key >= pivotkey)
			--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey)
			++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0]; //将枢轴记录放到枢纽位置
	return low; //返回枢轴位置
}//Partition

void Qsort(SqList& L, int low, int high)
{//对顺序表L中的子序列L.r[low.. high]作快速排序
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(L, low, high);
		Qsort(L, low, pivotloc - 1);
		Qsort(L, pivotloc + 1, high);
	}

}
void QuickSort(SqList& L)
{//对顺序表L快速排序
	Qsort(L, 1, L.length);
}

//选择排序 
void SelectSort(SqList& L)
{ //简单选择排序
	for (int i = 1; i < L.length; ++i)
	{ //在L.r[i..L.length] 中选择key最小的记录
		int k = i;
		for (int j = i + 1; j <= L.length; j++)
			if (L.r[j].key < L.r[k].key) k = j;
		if (k != i) 
		{
			int midd;
			midd = L.r[i].key;
			L.r[i].key = L.r[k].key;
			L.r[k].key = midd;
		}
	}
}


int main()
{
	int i, a;
	int c[MAXSIZE], d;
	for (i = 0; i < MAXSIZE; i++)
	{
		scanf("%d", &c[i]);
		scanf("%c", &d);
		if (d == '\n') break;
	}


	SqList H;
	for (a = 1; a <= i + 1; a++)
	{
		H.r[a].key = c[a - 1];
	}

	H.length = a - 1;
	printf("折半插入排序：");
	BiInsertionSort(H);//折半插入排序 
	printf("\n快速排序：");
	Qsort(H, 1, a-1);
	for (int i = 1; i <= H.length; i++)
	{
		printf("%d ", H.r[i].key);
	}
	printf("\n选择排序：");
	SelectSort(H);
	for (int i = 1; i <= H.length; i++)
	{
		printf("%d ", H.r[i].key);
	}


}
/*49 38 65 97 76 13 27 49*/
