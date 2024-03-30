// 백준 11004 : K번째 수
// 퀵 정렬

#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int> &data, int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;
	while (i <= j) {
		while (i <= end && data[i] <= data[pivot]) {
			i++;
		}
		while (j > start && data[j] >= data[pivot]) {
			j--;
		}

		if (i > j) {
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	quickSort(A, 0, N-1);

	cout << A[K-1];

	return 0;
}

