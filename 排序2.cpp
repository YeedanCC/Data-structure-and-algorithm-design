#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXSIZE 100
using namespace std;

typedef int KeyType;

typedef struct {
	KeyType key; //�ؼ�����
}RedType;

typedef struct
{
	RedType r[MAXSIZE + 1];
	int length;
}SqList, * List;

//�۰�������� 
void BiInsertionSort(SqList& L)// BInsertSort
{
	for (int i = 2; i <= L.length; ++i)
	{
		L.r[0].key = L.r[i].key; // �� L.r[i] �ݴ浽 L.r[0]
		int low = 1;
		int high = i - 1;
		while (low <= high)
		{
			int m = (low + high) / 2; // �۰�
			if (L.r[0].key < L.r[m].key)
				high = m - 1; // ������ڵͰ���
			else low = m + 1; // ������ڸ߰���
		} //�� L.r[1..i-1]���۰���Ҳ���λ�ã�
		for (int j = i - 1; j >= high + 1; --j)
			L.r[j + 1] = L.r[j]; // ��¼����
		L.r[high + 1] = L.r[0]; // ����	
	} // for	
	for (int i = 1; i <= L.length; i++)
	{
		printf("%d ", L.r[i].key);
	}
}

//��������
int Partition(SqList& L, int low, int high) //һ�˿�������
{
	L.r[0] = L.r[low]; //���ӱ�ĵ�һ����¼�������¼
	int pivotkey = L.r[low].key;
	while (low < high)
	{ //�ӱ�����˽�������м�ɨ��
		while (low < high && L.r[high].key >= pivotkey)
			--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey)
			++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0]; //�������¼�ŵ���Ŧλ��
	return low; //��������λ��
}//Partition

void Qsort(SqList& L, int low, int high)
{//��˳���L�е�������L.r[low.. high]����������
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(L, low, high);
		Qsort(L, low, pivotloc - 1);
		Qsort(L, pivotloc + 1, high);
	}

}
void QuickSort(SqList& L)
{//��˳���L��������
	Qsort(L, 1, L.length);
}

//ѡ������ 
void SelectSort(SqList& L)
{ //��ѡ������
	for (int i = 1; i < L.length; ++i)
	{ //��L.r[i..L.length] ��ѡ��key��С�ļ�¼
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
	printf("�۰��������");
	BiInsertionSort(H);//�۰�������� 
	printf("\n��������");
	Qsort(H, 1, a-1);
	for (int i = 1; i <= H.length; i++)
	{
		printf("%d ", H.r[i].key);
	}
	printf("\nѡ������");
	SelectSort(H);
	for (int i = 1; i <= H.length; i++)
	{
		printf("%d ", H.r[i].key);
	}


}
/*49 38 65 97 76 13 27 49*/
