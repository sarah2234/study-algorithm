#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> coordinate;
	for (int i = 0, x, y; i < n; i++)
	{
		cin >> x >> y;
		coordinate.push_back(make_pair(x, y));
	}
	sort(coordinate.begin(), coordinate.end(), compare);
	for (auto i : coordinate)
		cout << i.first << " " << i.second << "\n";
	return 0;
}