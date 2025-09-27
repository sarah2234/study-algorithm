#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

// 백준 2178. 미로 탐색

struct Node
{
	int x;
	int y;
	int dist;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	
	cin >> n >> m;

	vector<vector<int>> maze(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	queue<Node> q;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	for (int i = 0; i < n; i++)
	{
		string avail;
		cin >> avail;

		for (int j = 0; j < m; j++)
		{
			maze[i][j] = avail[j] - '0';
		}
	}

	// bfs
	q.push({ 0, 0 ,1 });
	visited[0][0] = true;

	while (!q.empty())
	{
		Node curr = q.front(); q.pop();

		if (curr.x == n - 1 && curr.y == m - 1)
		{
			cout << curr.dist;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}

			if (maze[nx][ny] == 0)
			{
				continue;
			}

			if (visited[nx][ny])
			{
				continue;
			}

			visited[nx][ny] = true;
			q.push({ nx, ny, curr.dist + 1 });
		}
	}


	return 0;
}
