#include <iostream>
using namespace std;

void instertion_sort_small_to_large(int* A);
void instertion_sort_large_to_small(int* A);

int main() {
	int A[] = { 2,3,1,5,4 };
	
	instertion_sort_small_to_large(A);//��������С����
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << endl;

	instertion_sort_large_to_small(A);//��С
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
		while (j >= 0 && A[j] > key) //��ǰһ�������ں�һ����
		{
			A[j + 1] = A[j];  //��һ������ֵ��Ϊǰһ������ֵ��С->��
			j = j - 1;
		}
		A[j + 1] = key; //��С��ֵ������ǰ��
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

