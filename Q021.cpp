// 백준 1517 : 버블 소트
// 병합 정렬

#include<iostream>
#include<vector>
using namespace std;

static vector<int> A;
static vector<int> temp;
static long result = 0;

void merge_sort(int start, int end);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	A = vector<int>(N+1, 0);
	temp = vector<int>(N+1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	merge_sort(1, N);

	cout << result;

}

void merge_sort(int start, int end) {
	if (end - start < 1) {
		return;
	}

	int mid = start + (end - start) / 2;

	merge_sort(start, mid);
	merge_sort(mid + 1, end);

	int k = start;
	int idx_1 = start;
	int idx_2 = mid + 1;

	for (int i = start; i <= end; i++) {
		temp[i] = A[i];
	}

	while (idx_1 <= mid && idx_2 <= end) {
		if (temp[idx_1] > temp[idx_2]) {
			A[k] = temp[idx_2];
			result += idx_2 - k;
			k++;
			idx_2++;
		}
		else {
			A[k++] = temp[idx_1++];
		}
	}

	while (idx_1 <= mid) {
		A[k++] = temp[idx_1++];
	}
	while (idx_2 <= end) {
		A[k++] = temp[idx_2++];
	}
}