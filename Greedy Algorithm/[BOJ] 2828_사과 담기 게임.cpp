#include <iostream>
#include <vector>
using namespace std;

int moveCnt;
void MoveBasket(vector<bool>& screen, int applePos, int basketLength);
int main()
{
	int n, m, j; // m == basketLength
	cin >> n >> m >> j;
	vector<bool> screen;
	vector<int> pos;
	int x;
	for (int i = 0; i < j; i++)
	{
		cin >> x;
		pos.push_back(x - 1);
	}
	for (int i = 0; i < n; i++)
	{
		if (i < m)
			screen.push_back(true);
		else
			screen.push_back(false);
	}

	for (int i = 0; i < j; i++)
	{
		MoveBasket(screen, pos[i], m);
	}
	cout << moveCnt << "\n";
	return 0;
}

void MoveBasket(vector<bool>& screen, int applePos, int basketLength)
{
	if (screen[applePos] == true)
		return;

	int basketPos = 0;
	for (int i = 0; i < screen.size(); i++)
	{
		if (screen[i] == true)
		{
			basketPos = i;
			break;
		}
	}

	if (basketPos < applePos)
	{
		while (screen[applePos] != true)
		{
			screen[basketPos] = false;
			screen[basketPos + basketLength] = true;
			basketPos++;
			moveCnt++;
		}
	}
	else
	{
		while (screen[applePos] != true)
		{
			screen[basketPos + basketLength - 1] = false;
			screen[--basketPos] = true;
			moveCnt++;
		}
	}
}