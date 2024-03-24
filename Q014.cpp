// น้มุ 11286 : ภýด๑ฐช ศü
// priority_queue

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2))
			return true;
		else if (abs(n1) == abs(n2)) {
			if (n1 > n2)
				return true;
			else
				return false;
		}
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << "0" << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

	return 0;
}
