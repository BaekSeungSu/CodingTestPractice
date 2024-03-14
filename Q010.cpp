// 백준 11003 : 최솟값 찾기 1
// 슬라이딩 윈도우, 덱

#include<iostream>
#include<deque>
using namespace std;
typedef pair<int, int> Node;

int main()
{
	int N, L;
	cin >> N >> L;
	deque<Node> myDeque;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		while (myDeque.size() && myDeque.back().second > now) {
			myDeque.pop_back();
		}
		myDeque.push_back(Node(i, now));
		if (myDeque.front().first <= i - L) {
			myDeque.pop_front();
		}
		cout << myDeque.front().second << '\n';
	}
}