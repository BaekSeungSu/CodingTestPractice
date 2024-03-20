// 백준 2164 : 카드 게임
// Queue

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	queue<int> Cards;

	for (int i = 1; i <= N; i++) {
		Cards.push(i);
	}

	while (Cards.size() > 1) {
		int top;
		Cards.pop();
		top = Cards.front();
		Cards.pop();
		Cards.push(top);
	}
	cout << Cards.front() << '\n';
}
