// 백준 1940번 : 주몽
// 투 포인터

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N, M, count=0; // N = 재료의 개수, M = 갑옷이 완성되는 번호의 합
	cin >> N;
	cin >> M;
	vector<int> materials(N, 0);

	for (int i = 0; i < N; i++) {

		cin >> materials[i];
	}

	int i = 0, j = N - 1;

	sort(materials.begin(), materials.end());

	while (i < j) {
		if (materials[i] + materials[j] == M) {
			count++;
			i++;
			j--;
		}
		else if (materials[i] + materials[j] < M) {
			i++;
		}
		else {
			j--;
		}
	}
	
	cout << count << "\n";
}