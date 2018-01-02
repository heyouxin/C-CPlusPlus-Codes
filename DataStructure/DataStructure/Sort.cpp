#include <stdafx.h>
#include <stdio.h>
#define Swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAXSIZE 10	/*  用于要排序数组个数最大值，可根据需要修改 */
typedef struct
{
	int r[MAXSIZE];   
	int length;	/*  用于记录顺序表的长度 */
}SqList;

/*  交换 L 中数组 r 的下标为 i 和 j 的值 */
void swap(SqList *L, int i, int j)
{
	int temp = L->r[i]; 
	L->r[i] = L->r[j];
	L->r[j] = temp;
}


void print(SqList *L)
{
	int i;
	for (i = 0; i<L->length; i++)
		printf("%d,", L->r[i]);// 
	//printf("%d", L.r[i]); 
	printf("\n");
}

void print_2(SqList &L)
{
	int i;
	for (i = 0; i<L.length; i++)
		printf("%d,", L.r[i]);// 
							   //printf("%d", L.r[i]); 
	printf("\n");
}

void bubbleSort(SqList *l)
{
	int i, j, last;
	i = l->length - 1;
	while (i>0)
	{
		last = 0;
		for (j= 0; j <i; j++)
		{
			if (l->r[j+1]<l->r[j])
			{
				swap(l, j, j + 1);
				last = j;
			}

		}
		i = last;
	}
}

void bubbleSortSimple(SqList *l)
{
	int i, j;
	for ( i = 0; i < l->length; i++)
	{
		for (j = i + 1; j < l->length; j++)
		{
			if (l->r[i]>l->r[j])
			{
				swap(l, i, j );

			}
		}

	}

}




void InsSort(SqList *L, int h)
{
	int i, j, x;
	for (i = h; i < L->length; i += h)
	{
		x = L->r[i];
		for (j = i - h; j >= 0 && x < L->r[j]; j -= h)
			L->r[j + h] = L->r[j];
		
		L->r[j + h] = x;

	}


}

void shellSort(SqList *L)
{
	int i, incr = L->length;
	do {
		incr = incr / 3 + 1;
		for (i = 0; i < incr; i++)
			InsSort(L, incr);

	} while (incr > 1);
}

void InsertSort(SqList *L)
{
	int i, j, x;
	for ( i = 1; i < L->length; i++)
	{
		x = L->r[i];
		for (j= i-1; j>=0 && x < L->r[j]; j--)
			L->r[j + 1] = L->r[j];

	
		L->r[j + 1] = x;

	}
}


int partition(SqList *l, int left, int right)
{
	int i = left, j = right + 1;
	int pivot = l->r[left];
	do
	{
		do i++; while (l->r[i] < pivot);
		do j--; while (l->r[j] > pivot);
		if (i<j)
		{
			swap(l, i, j);
		}
	} while (i<j);
	swap(l, left, j);
	return j;
}

void qSort(SqList *l, int left, int right)
{

	int k;
	if (left < right)
	{
		k = partition(l, left, right);
		qSort(l, left, k - 1);
		qSort(l, k + 1, right);
	}

}
void quickSort(SqList *l)
{
	qSort(l, 0, l->length-1);
}

/*
void merge(SqList *l, int temp[], int i1, int j1, int i2, int j2, int *k)
{
	int i = i1, j = i2;
	while ((i <= j1) && (j <= j2))
	{
		if(l->r[i])
	}

}


void mergeSort(SqList *l)
{
	int temp[MAXSIZE];
	int i1, j1, i2, j2, i, k, size = 1;
	while (size<l->length)
	{
		i1 = 0;
		k = 0;
		while (i1+size<l->length)
		{
			i2 = i1 + size;
			j1 = i2 - 1;
			if (i2 + size - 1 > l->length - 1)
			{
				j2 = l->length - 1;

			}
			else
				j2 = i2 + size - 1;
			

		}

	}
}

*/


void selectSort(SqList *l)
{

	int small, i, j;
	for (i = 0; i < l->length ; i++)
	{
		small = i;
		for (j = i+1; j < l->length; j++)
		{
			if (l->r[j]<l->r[small])
			{
				small = j;

			}

		}
		swap(l, i, small);
	}
}

//堆排序
typedef int T;
typedef struct minheap {

	T Elements[MAXSIZE];
	int Size;
}MinHeap;
void AdjustDown(T heap[], int r, int n)
{
	int child = 2 * r; T temp = heap[r];
	while (child <= n) {
		if (child <n && heap[child] > heap[child + 1]) child++;
		if (temp <= heap[child]) break;
		heap[child / 2] = heap[child];
		child *= 2;
	}
	heap[child / 2] = temp;
}
void CreateHeap(MinHeap *hp)
{
	int i, n = hp->Size;
	for (i = n / 2; i>0; i--)
		AdjustDown(hp->Elements, i, n);
}




void HeapSort(MinHeap *hp)
{
	int i; T temp;
	for (i = hp->Size / 2; i>0; i--)			/*建堆*/
		AdjustDown(hp->Elements, i, hp->Size);

	for (i = hp->Size; i>1; i--) {			/*选择排序*/
		Swap(hp->Elements[1], hp->Elements[i], temp);
		AdjustDown(hp->Elements, 1, i - 1);
	}
}

void print(MinHeap *L)
{
	int i;
	for (i = 0; i<L->Size; i++)
		printf("%d,", L->Elements[i]);// 
									  //printf("%d", L.r[i]); 
	printf("\n");
}
/*

int main()
{
	//SqList *l=new SqList;
	//SqList l;
	MinHeap l;
	l = { {5,3,4,1,6,8,2,9 },8 };
	print(&l);
	//希尔排序
	//shellSort(&l);
	//直接插入排序
	//InsertSort(&l);
	//冒泡排序
	//bubbleSortSimple(&l);
	//快速排序
	//quickSort(&l);
	//简单选择排序
	//selectSort(&l);
	 
	HeapSort(&l);
	print(&l);


	//printf("%d",a[0]);

	return 0;
}

*/

