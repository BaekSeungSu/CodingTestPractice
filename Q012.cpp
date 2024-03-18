// 백준 17298 : 오큰수 구하기
// Stack
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	stack<int> s;
	vector<int> answer(N,0);
	
	s.push(0);

	for (int i = 1; i < N; i++) {
		while (!s.empty() && A[s.top()] < A[i]) {
			answer[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}