
#include <vector>
#include <queue>

using namespace std;

void DFS(
	int node,
	const vector<vector<int>>& graph,
	vector<bool>& visited)
{
	// 구현
	visited[node] = true;
	for (int next : graph[node])
	{
		if (!visited[next])
		{
			DFS(next, graph, visited);
		}
	}
}

void BFS(
	int start,
	const vector<vector<int>>& graph,
	vector<bool>& visited)
{
	queue<int> q;

	// 직접 구현
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int next : graph[node])
		{
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

void dfsBfsBasic()
{
	int node = 1;
	vector<vector<int>> graph = {
	{},        // 0번 미사용
	{2, 3},    // 1
	{1, 4, 5}, // 2
	{1, 6},    // 3
	{2},       // 4
	{2},       // 5
	{3}        // 6
	};
	vector<bool> visited(graph.size(), false);
	//DFS(node, graph, visited);
	BFS(node, graph, visited);
}