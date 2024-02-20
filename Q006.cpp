// 백준 2018번 : 수들의 합 5
// 투 포인터

#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	long N, sum = 1;
	int start_id = 1, end_id = 1, count = 1;
	cin >> N;


	while (end_id != N) {
		if (sum < N) {
			end_id++;
			sum += end_id;
		}
		else if (sum > N) {
			sum -= start_id;
			start_id++;
		}
		else{
			end_id++;
			sum += end_id;
			count++;
		}
	}
	cout << count << '\n';
}
