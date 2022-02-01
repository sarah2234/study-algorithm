#include <stdio.h>
#include <string.h>

int sort[10];
void QuickSort(int startIndex, int endIndex);
int Partition(int p, int r);
void Swap(int a, int b);
int main()
{
	char n[11];
	scanf("%s", n);
	for (int i = 0; i < strlen(n); i++)
	{
		sort[i] = n[i] - '0';
	}
	QuickSort(0, strlen(n) - 1);
	for (int i = 0; i < strlen(n); i++)
	{
		printf("%d", sort[i]);
	}

	return 0;
}

void QuickSort(int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
		return;
	int pivot = Partition(startIndex, endIndex);
	QuickSort(startIndex, pivot - 1);
	QuickSort(pivot + 1, endIndex);
}

int Partition(int startIndex, int endIndex)
{
	int pivot = startIndex;
	int lastBiggerNumIndex = startIndex;
	for (int i = startIndex + 1; i <= endIndex; i++)
	{
		if (sort[i] > sort[pivot])
		{
			lastBiggerNumIndex++;
			Swap(lastBiggerNumIndex, i);
		}
	}
	Swap(lastBiggerNumIndex, pivot);
	return lastBiggerNumIndex;
}

void Swap(int a, int b)
{
	int temp = sort[a];
	sort[a] = sort[b];
	sort[b] = temp;
}