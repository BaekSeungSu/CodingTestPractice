// 백준 1253번 : 좋다
// 투 포인터

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	

	for (int k = 0; k < N; k++) {
		int i = 0;
		int j = N - 1;
		while (i < j) {
			if (A[i] + A[j] == A[k]) {
				if (i != k && j != k) {
					count++;
					break;
				}
				else if (i == k) {
					i++;
				}
				else if (j == k) {
					j--;
				}
			}
			else if (A[i] + A[j] > A[k]) {
				j--;
			}
			else {
				i++;
			}
		}
	}
	cout << count << '\n';
}