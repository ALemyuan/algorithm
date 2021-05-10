#include <iostream>
using namespace std;

void instertion_sort_small_to_large(int* A);
void instertion_sort_large_to_small(int* A);

int main() {
	int A[] = { 2,3,1,5,4 };
	
	instertion_sort_small_to_large(A);//插入排序，小到大
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << endl;

	instertion_sort_large_to_small(A);//大到小
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

void instertion_sort_small_to_large(int *A) {
	int i, j;
	int key;
	for ( i = 1; i < sizeof(A) + 1; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key) //当前一个数大于后一个数
		{
			A[j + 1] = A[j];  //后一个数的值赋为前一个数的值（小->大）
			j = j - 1;
		}
		A[j + 1] = key; //把小的值调至最前面
	}
}

void instertion_sort_large_to_small(int* A) {
	int i, j;
	int key;
	for (i = 1; i < sizeof(A) + 1; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 && key > A[j])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

