// ���� 11720�� : ������ ��
// �ڷᱸ�� : �迭, ����Ʈ, ����

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