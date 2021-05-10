#include <iostream>
using namespace std;

void mergeSort(int *A,int n1,int n2) {

	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	//将数组分为左右两个数组
	
	L[n1] = R[n2] = INT_MAX; //左右数组在末端添加一个最大无穷来进行最后的数值比较

	for (int  i = 0; i < n1; i++)
	{
		L[i] = A[i];
	}
	cout << "L(分治-左):";
	for (int  i = 0; i < n1; i++)
	{
		cout << L[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < n2; i++)
	{
		R[i] = A[i + n2];
	}
	cout << "R(分治-右):";
	for (int i = 0; i < n1; i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;

	int x = 0, y = 0;
	for (int i = 0; i < n1+n2; i++) //左右数组比较且合并
	{
		if (L[x] <= R[y])
		{
			A[i] = L[x];
			x++;
		}
		else
		{
			A[i] = R[y];
			y++;
		}
	}
}

int main() {
	int A[] = { 2,4,5,7,1,2,3,6 };
	cout << "A(排序前):";
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << endl;
	int n = sizeof(A) / sizeof(A[0]); 
	int n1 = n / 2;
	int n2 = n - n1;
	mergeSort(A,n1,n2);
	cout << "A(排序后):";
	for (int x : A)
	{
		cout << x << " ";
	}
	return 0;
}