#include <iostream>
using namespace std;

int *FIND_MAX_CROSSING_SUBARRAY(int* A, int low, int mid, int high) {
	
	//左子数组中查询自身的最大子数组，从mid（中间）到low（首部）
	int left_sum = INT_MIN;
	int sum = 0;
	int max_left = 0;
	for (int i = mid; i > low; i--)
	{
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	//右子数组中查询自身的最大子数组，从mid（中间）到high（尾部）
	int right_sum = INT_MIN;
	sum = 0;
	int max_right = 0;
	for (int i = mid + 1; i < high; i++)
	{
		sum = sum + A[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}

	int Cross[] = { max_left, max_right, left_sum + right_sum };
	return Cross;
}

int* FIND_MAXIMUM_SUBARRAY(int* A, int low, int high) {
	
	//当最大子数组为自身，返回值
	if (low == high)
	{
		int subarray[] = { low,high,A[low] };
		return subarray;
	}
	//当最大子数组不为自身，
	else
	{
		int mid = (low + high) / 2;

		//当最大子数组在左子数组，调用自身，循环分治查询
		int left_low = FIND_MAXIMUM_SUBARRAY(A, low, mid)[0];
		int left_high = FIND_MAXIMUM_SUBARRAY(A, low, mid)[1];
		int left_sum = FIND_MAXIMUM_SUBARRAY(A, low, mid)[2];

		//当最大子数组在右子数组，调用自身，循环分治查询
		int right_low = FIND_MAXIMUM_SUBARRAY(A, mid+1, high)[0];
		int right_high = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high)[1];
		int right_sum = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high)[2];

		//当最大子数组在左子数组和右子数组之间，分治查询
		int cross_low = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)[0];
		int cross_high = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)[1];
		int cross_sum = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)[2];
		
		//当最大子数组在左子数组，返回值
		if (left_sum > right_sum && left_sum > cross_sum)
		{
			int subarray[] = { left_low,left_high,left_sum };
			return subarray;
		}

		//当最大子数组在右子数组，返回值
		else if (right_sum > left_sum && right_sum > cross_sum)
		{
			int subarray[] = { right_low,right_high,right_sum };
			return subarray;
		}

		//当最大子数组在左子数组和右子数组之间，返回值
		else
		{
			int subarray[] = { cross_low,cross_high,cross_sum };
			return subarray;
		}
	}
}

int main() {
	int A[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,-7 };
	
	cout << "原数组A：";
	for (int i : A)
	{
		cout << i << " ";
	}
	cout << endl;

	int low = 1;
	int high = sizeof(A) / sizeof(A[0]);

	cout << "最大子数组：";
	for (int i = FIND_MAXIMUM_SUBARRAY(A, low, high)[0]; i <= FIND_MAXIMUM_SUBARRAY(A, low, high)[1]; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "最大子数组元素之和：" << FIND_MAXIMUM_SUBARRAY(A, low, high)[2] << endl;

	return 0;
}