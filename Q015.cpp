// 백준 2750 : 수 정렬하기
// 버블 정렬
#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int s[1000];

	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N - i; j++) {
			int tmp;
			if (s[j] > s[j + 1]) {
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
	
	
	for (int i = 0;  i < N; i++) {
		cout << s[i] << "\n";
	}
}
