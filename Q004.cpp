// 백준 11660번 : 구간 합 구하기 5
// 구간 합 구하기 2

#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> S(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1] << '\n';
	}
}