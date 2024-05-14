// 백준 2023 : 신기한 소수
// DFS

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n);
void DFS(int n, int jarisu);
static int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

}

void DFS(int n, int jarisu) {
	if (jarisu == N) {
		if (isPrime(n)) {
			cout << n << "\n";
		}
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (isPrime(n * 10 + i) && i % 2 == 1) {
			DFS(n * 10 + i, jarisu + 1);
		}
	}
}

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}