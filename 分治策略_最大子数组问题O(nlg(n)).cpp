#include <iostream>
using namespace std;

int *FIND_MAX_CROSSING_SUBARRAY(int* A, int low, int mid, int high) {
	
	//���������в�ѯ�������������飬��mid���м䣩��low���ײ���
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

	//���������в�ѯ�������������飬��mid���м䣩��high��β����
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
	
	//�����������Ϊ��������ֵ
	if (low == high)
	{
		int subarray[] = { low,high,A[low] };
		return subarray;
	}
	//����������鲻Ϊ����
	else
	{
		int mid = (low + high) / 2;

		//��������������������飬��������ѭ�����β�ѯ
		int left_low = FIND_MAXIMUM_SUBARRAY(A, low, mid)[0];
		int left_high = FIND_MAXIMUM_SUBARRAY(A, low, mid)[1];
		int left_sum = FIND_MAXIMUM_SUBARRAY(A, low, mid)[2];

		//��������������������飬��������ѭ�����β�ѯ
		int right_low = FIND_MAXIMUM_SUBARRAY(A, mid+1, high)[0];
		int right_high = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high)[1];
		int right_sum = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high)[2];

		//������������������������������֮�䣬���β�ѯ
		int cross_low = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)[0];
		int cross_high = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)[1];
		int cross_sum = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)[2];
		
		//��������������������飬����ֵ
		if (left_sum > right_sum && left_sum > cross_sum)
		{
			int subarray[] = { left_low,left_high,left_sum };
			return subarray;
		}

		//��������������������飬����ֵ
		else if (right_sum > left_sum && right_sum > cross_sum)
		{
			int subarray[] = { right_low,right_high,right_sum };
			return subarray;
		}

		//������������������������������֮�䣬����ֵ
		else
		{
			int subarray[] = { cross_low,cross_high,cross_sum };
			return subarray;
		}
	}
}

int main() {
	int A[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,-7 };
	
	cout << "ԭ����A��";
	for (int i : A)
	{
		cout << i << " ";
	}
	cout << endl;

	int low = 1;
	int high = sizeof(A) / sizeof(A[0]);

	cout << "��������飺";
	for (int i = FIND_MAXIMUM_SUBARRAY(A, low, high)[0]; i <= FIND_MAXIMUM_SUBARRAY(A, low, high)[1]; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "���������Ԫ��֮�ͣ�" << FIND_MAXIMUM_SUBARRAY(A, low, high)[2] << endl;

	return 0;
}