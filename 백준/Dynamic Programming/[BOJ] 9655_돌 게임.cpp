#include <iostream>
using namespace std;

int SKWin[1001];
bool GetWinner(int n);
int main()
{
	int n;
	cin >> n;
	SKWin[1] = 1;
	SKWin[2] = -1;
	SKWin[3] = 1;
	SKWin[4] = -1;
	SKWin[5] = 1;
	SKWin[6] = -1;
	if (GetWinner(n) == true)
		cout << "SK\n";
	else
		cout << "CY\n";

	return 0;
}

bool GetWinner(int n)
{
	if (SKWin[n] == 1)
		return true;
	else if (SKWin[n] == -1)
		return false;
	for (int i = 2; i <= 6; i += 2)
	{
		if (GetWinner(n - i))
		{
			SKWin[n] = 1;
			return true;
		}
	}
	SKWin[n] = -1;
	return false;
}
