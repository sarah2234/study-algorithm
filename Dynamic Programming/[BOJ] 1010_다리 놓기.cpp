#include <iostream>
#include <cstring>
using namespace std;

int memoization[30][30];
void CreateBridge(int n, int m, int curr);
int main()
{
	int t;
	int n, m;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < n; j++)
			memset(memoization[j], 0, sizeof(memoization[j]));
		CreateBridge(n, m, m - 1);
	}

	return 0;
}

void CreateBridge(int n, int m, int curr)
{
	if (curr + 1 == n)
	{
		for (int i = 0; i < m - n + 1; i++)
		{
 			memoization[curr][curr + i] = 1;
		}
	}
	
	if (curr != 0)
	{
		for (int i = 0; i < m - n + 1; i++)
		{
			for (int j = i; j < m - n + 1; j++)
			{
				memoization[curr - 1][curr - 1 + i] += memoization[curr][curr + j];
			}
		}
		CreateBridge(n, m, curr - 1);
	}
	else
	{
		int ans = 0;
		for (int i = 0; i < m - n + 1; i++)
		{
			ans += memoization[0][i];
		}
		cout << ans << "\n";
	}
}