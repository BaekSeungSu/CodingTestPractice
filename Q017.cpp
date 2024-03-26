// 백준 1427 : 소트인사이드
// 선택 정렬

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N;
	cin >> N;
	vector<int> A;

	for (int i = 0; i < N.size(); i++) {
		A.push_back(N[i] - '0');
	}

	for (int i = 0; i < A.size(); i++) {
		int max = i;
		for (int j = i + 1; j < A.size(); j++) {
			if (A[max] < A[j]) {
				max = j;
			}
		}
		if (A[i] < A[max]) {
			int tmp = A[i];
			A[i] = A[max];
			A[max] = tmp;
		}
	}

	for (int i = 0; i < A.size(); i++) {
		cout << A[i];
	}
}