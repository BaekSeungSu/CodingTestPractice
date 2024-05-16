// 백준 1167 : 트리의 지름
// BFS

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> m_distance;

void BFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	A.resize(N+1);
	visited = vector<bool>(N + 1, false);
	m_distance = vector<int>(N + 1, 0);

	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		while (true) {
			int E, V;
			cin >> E;
			if (E == -1) {
				break;
			}
			cin >> V;
			A[s].push_back(edge(E, V));
		}
	}

	BFS(1);
	int max = 1;

	for (int i = 2; i <= N; i++) {
		if (m_distance[max] < m_distance[i]) {
			max = i;
		}
	}

	fill(m_distance.begin(), m_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);

	BFS(max);

	sort(m_distance.begin(), m_distance.end());

	cout << m_distance[N];
	


}

void BFS(int node) {
	queue<int> myQue;
	myQue.push(node);
	visited[node] = true;

	while (!myQue.empty()) {
		int now_node = myQue.front();
		myQue.pop();
		for (edge i : A[now_node]) {
			if (!visited[i.first]) {
				visited[i.first] = true;
				myQue.push(i.first);
				m_distance[i.first] = m_distance[now_node] + i.second;
			}
		}
	}
}
