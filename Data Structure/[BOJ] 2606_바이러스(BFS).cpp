#include<iostream>
#include <queue>
using namespace std;

typedef struct Node
{
	int key;
	struct Node** adjacentKey;
	bool visited;
}Node;
Node** graph;
int virusCnt, cmpNum, connectNum;
queue<Node*> bfsQueue;

void InsertEdge(int a, int b);
void BFS(Node* curr);
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

	BFS(graph[0]);
	cout << virusCnt << "\n";

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

void BFS(Node* curr)
{
	curr->visited = true;
	for (int i = 0; i < cmpNum; i++)
	{
		if (curr->adjacentKey[i] != nullptr)
		{
			virusCnt++;
			bfsQueue.push(curr->adjacentKey[i]);
			curr->adjacentKey[i]->visited = true;
		}
	}

	while (!bfsQueue.empty())
	{
		Node* node = bfsQueue.front();
		bfsQueue.pop();
		for (int i = 0; i < cmpNum; i++)
		{
			if (node->adjacentKey[i] != nullptr)
			{
				if (!node->adjacentKey[i]->visited)
				{
					virusCnt++;
					bfsQueue.push(node->adjacentKey[i]);
					node->adjacentKey[i]->visited = true;
				}
			}
		}
	}
}
