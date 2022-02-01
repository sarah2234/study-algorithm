#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int* a, int* b)
{
	if (a[1] > b[1] ||
		(a[1] == b[1] && a[2] > b[2]) ||
		(a[1] == b[1] && a[2] == b[2] && a[3] > b[3]))
		return true;
	else
		return false;
}

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
	sort(countries, countries + N, compare);
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

