// πÈ¡ÿ 1260 : DFSøÕ BFS
// DFS, BFS

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int v);
void BFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, V;
	cin >> N >> M >> V;

	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(A[i].begin(), A[i].end());
	}

	for (int i = 1; i < N + 1; i++) {
		if (!visited[V]) {
			DFS(V);
		}
	}

	fill(visited.begin(), visited.end(), false);
	cout << "\n";

	for (int i = 1; i < N + 1; i++) {
		if (!visited[V]) {
			BFS(V);
		}
	}


}

void DFS(int v) {
	if (visited[v]) return;
	cout << v << " ";

	visited[v] = true;
	
	for (int i : A[v]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	queue<int> que;
	que.push(v);
	visited[v] = true;
	while (!que.empty()) {
		int now_node = que.front();
		cout << now_node << " ";
		que.pop();
		for (int i : A[now_node]) {
			if (!visited[i]) {
				visited[i] = true;
				que.push(i);
			}
		}
	}
}