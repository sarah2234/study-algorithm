#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> cards;
	for (int i = 1; i <= n; i++)
	{
		cards.push(i);
	}

	while (cards.size() != 1)
	{
		cards.pop();
		int temp = cards.front();
		cards.pop();
		cards.push(temp);
	}
	cout << cards.front() << endl;

	return 0;
}
