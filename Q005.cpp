// 백준 11660번 : 구간 합 구하기 5
// 구간 합 구하기 2

#include<vector>
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; // 수의 개수, 나눌 숫자
	cin >> N >> M;
	//합배열, 빈도수 저장 배열
	vector<long> sum(N+1);
	vector<long> C(M);
	long answer = 0;

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		sum[i] = sum[i - 1] + temp; // 구간합 구함
	}

	for (int i = 1; i <= N; i++) {
		int remainder;
		remainder = sum[i] % M;
		if (remainder == 0) {
			answer += 1;
		}
		C[remainder] +=1;
	}

	for (int i = 0; i < M; i++) {
		if (C[i] > 1) {
			answer += (C[i] * (C[i] - 1)) / 2;
		}
	}
	cout << answer << '\n';
}