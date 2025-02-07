//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	Graph(int numNodes);
	~Graph();
	void printAdjList();
	void addEdge(int node1, int node2, int wgt, bool dir = false);
	bool isConnected(int node1, int node2);
	void traverseDFS_rec(int startNode);
	void traverseDFS(int startNode);
	void traverseBFS(int startNode);
	void shortestPathDijkstras(int src);

private:
	void dfs(int startNode);
	int findUnvisitedNodeWithMinDistance();
	vector<map<int, int>> m_AdjList;
	int m_Size;
	vector<bool> visited;
	vector<int> dist;
	vector<int> prev;
};

Graph::Graph(int numNodes)
{
	m_Size = numNodes;
	m_AdjList.resize(numNodes);
}
Graph::~Graph() {}
void Graph::addEdge(int node1, int node2, int wgt, bool dir)
{
	m_AdjList[node1][node2] = wgt;
	if (!dir)
		m_AdjList[node2][node1] = wgt;
}

bool Graph::isConnected(int node1, int node2)
{
	return m_AdjList[node1].count(node2);
}

void Graph::dfs(int startNode)
{
	visited[startNode] = true;
	cout << startNode << " ";
	for (auto &neighbor : m_AdjList[startNode])
		if (!visited[neighbor.first])
			dfs(neighbor.first);
}

void Graph::traverseDFS_rec(int startNode)
{
	visited.assign(m_Size, false);
	dfs(startNode);
}

void Graph::traverseDFS(int startNode)
{
	visited.assign(m_Size, false);
	stack<int> st;
	st.push(startNode);
	while (!st.empty())
	{
		int currentNode = st.top();
		st.pop();
		if (!visited[currentNode])
		{
			cout << currentNode << " ";
			visited[currentNode] = true;
		}
		for (auto it = m_AdjList[currentNode].rbegin(); it != m_AdjList[currentNode].rend(); ++it)
			if (!visited[it->first])
				st.push(it->first);
	}
	cout << endl;
}

void Graph::traverseBFS(int startNode)
{
	visited.assign(m_Size, false);
	queue<int> queue;
	queue.push(startNode);
	while (!queue.empty())
	{
		int currentNode = queue.front();
		queue.pop();
		if (!visited[currentNode])
		{
			cout << currentNode << " ";
			visited[currentNode] = true;
		}
		for (auto &neighbor : m_AdjList[currentNode])
			if (!visited[neighbor.first])
				queue.push(neighbor.first);
	}
	cout << endl;
}

void Graph::shortestPathDijkstras(int src)
{
	visited.assign(m_Size, false);
	dist.assign(m_Size, INT_MAX);
	prev.assign(m_Size, -1);
	dist[src] = 0;
	for (int i = 0; i < m_Size - 1; ++i)
	{
		int u = findUnvisitedNodeWithMinDistance();
		visited[u] = true;
		for (auto &neighbor : m_AdjList[u])
		{
			int w = neighbor.first;
			int newDist = dist[u] + neighbor.second;
			if (!visited[w] && newDist < dist[w])
			{
				dist[w] = newDist;
				prev[w] = u;
			}
		}
	}
}

int Graph::findUnvisitedNodeWithMinDistance()
{
	int min = INT_MAX, minIndex = -1;
	for (int i = 0; i < m_Size; ++i)
		if (!visited[i] && dist[i] <= min)
			min = dist[i], minIndex = i;
	return minIndex;
}

void Graph::printAdjList()
{
	for (int i = 0; i < m_Size; ++i)
	{
		cout << "Node " << i << ": ";
		for (auto &neighbor : m_AdjList[i])
			cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
		cout << endl;
	}
}

int main() {
	Graph g(5);
	g.addEdge(0, 1, 2);
	g.addEdge(0, 4, 3);
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 2);
	g.addEdge(3, 4, 5);

	cout << "Adjacency List:" << endl;
	g.printAdjList();

	cout << "DFS Traversal:" << endl;
	g.traverseDFS(0);

	cout << "BFS Traversal:" << endl;
	g.traverseBFS(0);

	cout << "Shortest Path from Node 0:" << endl;
	g.shortestPathDijkstras(0);

	return 0;
}
