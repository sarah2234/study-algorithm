#include <iostream>
using namespace std;

void QuickSort(int** a, int p, int r);
int Partition(int** a, int p, int r);
void Swap(int*& a, int*& b);

int main()
{
	int N, K;
	int** countries;
	int ans = 0, same = 0;
	cin >> N >> K;
	countries = new int* [N];
	for (int i = 0; i < N; i++)
	{
		countries[i] = new int[4];
		cin >> countries[i][0] >> countries[i][1] >> countries[i][2] >> countries[i][3];
	}
	QuickSort(countries, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		if (K == countries[i][0])
		{
			ans = i;
			break;
		}
	}
	for (int i = 0; i < ans; i++)
	{
		if (countries[ans][1] == countries[i][1] &&
			countries[ans][2] == countries[i][2] &&
			countries[ans][3] == countries[i][3])
			same++;
	}
	cout << ans - same + 1;

	for (int i = 0; i < N; i++)
	{
		delete[] countries[i];
	}
	delete[] countries;
	return 0;
}

void QuickSort(int** a, int p, int r)
{
	if (p < r)
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}

int Partition(int** a, int p, int r)
{
	int* x = a[r]; // pivot
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j][1] > x[1] ||
			(a[j][1] == x[1] && a[j][2] > x[2]) ||
			(a[j][1] == x[1] && a[j][2] == x[2] && a[j][3] > x[3]))
			Swap(a[++i], a[j]);
	}
	Swap(a[i + 1], a[r]);
	return i + 1;
}

void Swap(int*& a, int*& b)
{
	int* temp = a;
	a = b;
	b = temp;
}