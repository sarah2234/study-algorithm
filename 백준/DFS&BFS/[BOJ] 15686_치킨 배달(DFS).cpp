#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// 15686. 치킨 배달
// 조합 C(13, M) + 백트래킹 => DFS
int n, m;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<int> selected;
int ans = 1e9;

void dfs(int index, int cnt)
{
	if (cnt == m)
	{
		int totalDist = 0;

		for (const auto& h : houses)
		{
			int minDist = 1e9;

			for (int i : selected)
			{
				auto& c = chickens[i];
				int dist = abs(h.first - c.first) + abs(h.second - c.second);
				minDist = min(minDist, dist); // 선택한 모든 치킨집 중 가장 가까운 거리 찾기
			}

			totalDist += minDist;
		}

		ans = min(totalDist, ans);
		return;
	}

	for (int i = index; i < chickens.size(); i++)
	{
		selected.emplace_back(i);
		dfs(i + 1, cnt + 1);
		selected.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int city;

			cin >> city;

			if (city == 1)
				houses.emplace_back(i, j);
			else if (city == 2)
				chickens.push_back({ i,j });
		}
	}

	dfs(0, 0);

	cout << ans;

	return 0;
}
