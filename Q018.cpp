// 백준 11399 : ATM
// 삽입 정렬

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp, j, sum=0;
	cin >> N;
	vector<int> A(N, 0);
	vector<int> S(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i < N; i++) {
		tmp = A[i];
		for (j = i - 1; j >= 0; j--) {
			if (A[j] > tmp) {
				A[j + 1] = A[j];
			}
			else break;
		}
		A[j + 1] = tmp;
	}

	S[0] = A[0];
	for (int i = 1; i < N; i++) {
		S[i] = S[i - 1] + A[i];
	}

	for (int i = 0; i < N; i++) {
		sum += S[i];
	}

	cout << sum;
}