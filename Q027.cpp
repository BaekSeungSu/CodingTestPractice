// ���� 2178 : �̷� Ž��
// BFS

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { 1, 0, -1, 0 };
static vector<vector<int>> A;
static vector<vector<bool>> visited;
static int N, M;

void BFS(int i, int j);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	A = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			A[i][j] = s[j] - '0';
		}
	}

	BFS(0, 0);
	cout << A[N - 1][M - 1];

}

void BFS(int i, int j) {
	queue<pair<int, int>> que;
	que.push(make_pair(i,j));

	while (!que.empty()) {
		int now[2];
		now[0] = que.front().first;
		now[1] = que.front().second;
		que.pop();
		visited[i][j] = true;

		for (int k = 0; k < 4; k++) {
			int x = now[0] + dx[k];
			int y = now[1] + dy[k];

			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (A[x][y] != 0 && !visited[x][y]) {
					visited[x][y] = true;
					A[x][y] = A[now[0]][now[1]] + 1;
					que.push(make_pair(x, y));
				}
			}
		}
	}

}