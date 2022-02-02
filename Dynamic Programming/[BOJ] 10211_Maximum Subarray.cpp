#include <iostream>
using namespace std;

int findMaxSubArraySum(int array[], int low, int high);
int findMaxCrossingSubArraySum(int array[], int low, int mid, int high);

int main()
{
	int T, N;
	int* inputArray = NULL;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		inputArray = new int[N];

		int positiveCnt = 0, negativeCnt = 0;
		int sum = 0;
		int maxNegativeNum = -1001;
		for (int j = 0; j < N; j++)
		{
			cin >> inputArray[j];

			// 배열의 요소가 모두 양수인지 확인
			if (inputArray[j] >= 0)
			{
				positiveCnt++;
				sum += inputArray[j];
			}
			// 배열의 요소가 모두 음수인지 확인
			else
			{
				negativeCnt++;
				maxNegativeNum = max(inputArray[j], maxNegativeNum);
			}
		}

		if (positiveCnt == N)
			cout << sum << endl;
		else if (negativeCnt == N)
			cout << maxNegativeNum << endl;
		else
			cout << findMaxSubArraySum(inputArray, 0, N - 1) << endl;

		delete[] inputArray;
	}

	return 0;
}

int findMaxSubArraySum(int array[], int low, int high)
{
	// 베이스 케이스
	if (low == high)
		return array[low];

	int mid = (low + high) / 2;
	int leftSum = findMaxSubArraySum(array, low, mid);
	int rightSum = findMaxSubArraySum(array, mid + 1, high);
	int crossSum = findMaxCrossingSubArraySum(array, low, mid, high);
	
	if (leftSum >= rightSum && leftSum >= crossSum)
		return leftSum;
	else if (rightSum >= leftSum && rightSum >= crossSum)
		return rightSum;
	else
		return crossSum;
}

// 최대 부분 배열이 중간값에 걸쳐 있는지 확인
int findMaxCrossingSubArraySum(int array[], int low, int mid, int high)
{
	// 왼쪽 배열에서 최대 부분 배열의 왼쪽 경계 찾기
	int leftSum = 0;
	int sum = 0;
	for (int i = mid; i >= low; i--)
	{
		sum += array[i];
		if (max(sum, leftSum) == sum)
			leftSum = sum;
	}

	// 오른쪽 배열에서 최대 부분 배열의 오른쪽 경계 찾기
	int rightSum = 0;
	sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += array[i];
		if (max(sum, rightSum) == sum)
			rightSum = sum;
	}

	return leftSum + rightSum;
}