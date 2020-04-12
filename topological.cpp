#include<bits/stdc++.h>

using namespace std;
template <typename T>
class graph {
	map<T, list<T>> adjList;
public:
	graph() {

	}
	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}
	void print() {
		for (auto i : adjList) {
			cout << i.first << "->";
			for (auto entry : i.second) {
				cout << entry << " ";
			}
			cout << endl;
		}
	}
	void bfs(T src) {
		queue<T>q;
		q.push(src);
		map<T, bool> visited;
		visited[src] = true;
		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto neighbour : adjList[node]) {
				if (!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
	void dfshelper(T node, map<T, bool>&visited, list<T>&ordering) {
		visited[node] = true;
		for (T neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfshelper(neighbour, visited, ordering);
			}
		}
		ordering.push_front(node);
	}
	void topological() {
		map<T, bool> visited;
		list<T> ordering;
		for (auto i : adjList) {
			T node = i.first;
			if (!visited[node]) {
				dfshelper(node, visited, ordering);
			}
		}
		for (T element : ordering) {
			cout << element << "-->";
		}
	}
};
int main() {
	graph<int>g;
	g.addEdge(0, 1, false);
	g.addEdge(0, 2, false);
	g.addEdge(0, 4, false);
	g.addEdge(2, 4, false);
	g.addEdge(1, 4, false);
	g.addEdge(4, 5, false);

	g.topological();
}