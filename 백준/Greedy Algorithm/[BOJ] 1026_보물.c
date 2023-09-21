#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int* A, * B;
	int temp;
	int sum = 0;

	scanf("%d", &N);
	A = (int*)malloc(N * sizeof(int));
	B = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", A + i);
	}
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", B + i);
	}

	for (int i = 0; i < N - 1; i++) //오름차순
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) //내림차순
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (B[j] < B[j + 1])
			{
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		sum += A[i] * B[i];
	}
	printf("%d", sum);

	return 0;
}
