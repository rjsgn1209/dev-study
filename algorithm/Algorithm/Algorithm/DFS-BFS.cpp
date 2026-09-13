
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

int FindMinDistance(
	const vector<vector<int>>& graph,
	int start,
	int target)
{
	// 구현
	queue<int> q;
	vector<int> distance(graph.size(), -1);

	q.push(start);
	distance[start] += 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (node == target)
		{
			return distance[node];
		}

		for (int next : graph[node])
		{
			if (distance[next] == -1)
			{
				q.push(next);
				distance[next] = distance[node] + 1;
			}
		}
	}

	return -1;
}

bool CanReach(const vector<vector<int>>& graph,
	int start,
	int target);

bool DFS(
	const vector<vector<int>>& graph,
	int node,
	int target,
	vector<bool>& visited)
{
	// 구현
	if (node == target)
	{
		return true;
	}

	visited[node] = true;

	for (int next : graph[node])
	{
		if (!visited[next])
		{
			if (DFS(graph, next, target, visited))
			{
				return true;
			}
		}
	}

	return false;
}

bool CanReach(
	const vector<vector<int>>& graph,
	int start,
	int target)
{
	// DFS로 구현
	vector<bool> visited(graph.size(), false);

	return DFS(graph, start, target, visited);
}

void dfsBfsBasic()
{
	//int node = 1;
	//vector<vector<int>> graph = {
	//{},        // 0번 미사용
	//{2, 3},    // 1
	//{1, 4, 5}, // 2
	//{1, 6},    // 3
	//{2},       // 4
	//{2},       // 5
	//{3}        // 6
	//};
	//vector<bool> visited(graph.size(), false);
	////DFS(node, graph, visited);
	//BFS(node, graph, visited);

	//vector<vector<int>> graph = {
	//{1, 2},       // 0
	//{0, 3, 4},    // 1
	//{0, 4},       // 2
	//{1, 5},       // 3
	//{1, 2, 5},    // 4
	//{3, 4, 6},    // 5
	//{5}           // 6
	//};
	//int res = FindMinDistance(graph, 0, 6);

	vector<vector<int>> graph = {
	{1, 2},
	{0, 3, 4},
	{0, 4},
	{1, 5},
	{1, 2, 5},
	{3, 4, 6},
	{5}
	};
	bool res = CanReach(graph, 0, 6);
}