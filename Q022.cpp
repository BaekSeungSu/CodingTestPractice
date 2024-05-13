// ���� 10989 : �� �����ϱ� 3
// ��� ����

#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> count(10001, 0);
	int num = 0;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		count[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				cout << i << "\n";
			}
		}
	}
	
}