// 백준 2751 : 수 정렬하기 2
// 병합 정렬

#include<iostream>
#include<vector>
using namespace std;

static vector<int> A;
static vector<int> tmp;

void merge_sort(int s, int e) {
	if (e - s < 1) {
		return;
	}

	int m = s + (e - s) / 2;

	merge_sort(s, m);
	merge_sort(m + 1, e);

	for (int i = s; i <= e; i++) {
		tmp[i] = A[i];
	}
	
	int k = s;
	int id_1 = s;
	int id_2 = m + 1;

	while (id_1 <= m && id_2 <= e) {
		if (tmp[id_1] > tmp[id_2]) {
			A[k++] = tmp[id_2++];
		}
		else {
			A[k++] = tmp[id_1++];
		}
	}

	while (id_1 <= m) {
		A[k++] = tmp[id_1++];
	}
	while (id_2 <= e) {
		A[k++] = tmp[id_2++];
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	merge_sort(1, N);

	for (int i = 1; i <= N; i++) {
		cout << A[i] << "\n";
	}
}