// 백준 1546번 : 평균
// 자료구조 : 배열, 리스트, 백터

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N = 0;
	vector<int> grades(1000);
	int M = 0;
	int sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> grades[i];
	}

	for (int i = 0; i<N; i++) {
		if (grades[i] > M) {
			M = grades[i];
		}
		sum += grades[i];
	}

	double result = sum * 100.0 / M / N;
	cout << result << endl;
}