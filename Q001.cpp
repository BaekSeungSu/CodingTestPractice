// 백준 11720번 : 숫자의 합
// 자료구조 : 배열, 리스트, 백터

#include<iostream>
using namespace std;
int main() {
	int N = 0;
	string numbers;
	cin >> N;
	cin >> numbers;
	int sum = 0;

	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i] - '0';
	}
	cout << sum << endl;
}