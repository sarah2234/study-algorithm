#include<iostream>
using namespace std;

typedef struct Node
{
	int key;
	struct Node** adjacentKey;
	bool visited;
}Node;
Node** graph;
int virusCnt, cmpNum, connectNum;

void InsertEdge(int a, int b);
void DFS(Node* curr);
int main()
{
	cin >> cmpNum >> connectNum;
	graph = new Node * [cmpNum];
	for (int i = 0; i < cmpNum; i++) // 초기화
	{
		Node* tmp = new Node();
		tmp->key = i + 1;
		tmp->adjacentKey = new Node*[cmpNum];
		for (int j = 0; j < cmpNum; j++)
		{
			tmp->adjacentKey[j] = nullptr;
		}
		tmp->visited = false;
		graph[i] = tmp;
	}
	for (int i = 0, a, b; i < connectNum; i++) // 간선 입력
	{
		cin >> a >> b;
		InsertEdge(a - 1, b - 1);
	}

	DFS(graph[0]);
	cout << virusCnt - 1 << "\n";

	for (int i = 0; i < cmpNum; i++)
	{
		delete graph[i];
	}
	delete[] graph;
	return 0;
}

void InsertEdge(int a, int b)
{
	graph[a]->adjacentKey[b] = graph[b];
	graph[b]->adjacentKey[a] = graph[a];
}

void DFS(Node* curr)
{
	if (curr->visited)
		return;

	virusCnt++;
	curr->visited = true;
	for (int i = 0; i < cmpNum; i++)
	{
		if (curr->adjacentKey[i] != nullptr)
			DFS(curr->adjacentKey[i]);
	}
}
