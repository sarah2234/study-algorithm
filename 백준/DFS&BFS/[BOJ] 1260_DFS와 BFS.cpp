#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node
{
	int key;
	vector<struct Node*> adjacent;
	bool visited;
} Node;
int n, m, v;
Node** graph;

bool compare(Node* a, Node* b)
{
	return a->key < b->key;
}

void DFS(Node* curr);
void BFS(Node* start);
int main()
{
	cin >> n >> m >> v;
	graph = new Node * [n];
	for (int i = 0; i < n; i++)
	{
		Node* temp = new Node();
		temp->key = i + 1;
		temp->visited = false;
		graph[i] = temp;
	}
	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		graph[a - 1]->adjacent.push_back(graph[b - 1]);
		graph[b - 1]->adjacent.push_back(graph[a - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		sort(graph[i]->adjacent.begin(), graph[i]->adjacent.end(), compare);
	}

	DFS(graph[v - 1]);
	for (int i = 0; i < n; i++)
	{
		graph[i]->visited = false;
	}
	cout << endl;
	BFS(graph[v - 1]);

	return 0;
}

void DFS(Node* curr)
{
	if (curr->visited)
		return;

	curr->visited = true;
	cout << curr->key << " ";
	for (Node* temp : curr->adjacent)
	{
		DFS(temp);
	}
}

void BFS(Node* start)
{
	queue<Node*> bfsQueue;
	cout << start->key << " ";
	start->visited = true;
	for (Node* temp : start->adjacent)
	{
		bfsQueue.push(temp);
		temp->visited = true;
	}

	while (bfsQueue.size() != 0)
	{
		Node* curr = bfsQueue.front();
		bfsQueue.pop();
		cout << curr->key << " ";
		for (Node* temp : curr->adjacent)
		{
			if (!temp->visited)
			{
				temp->visited = true;
				bfsQueue.push(temp);
			}
		}
	}
}
