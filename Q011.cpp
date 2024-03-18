// 백준 1874 : 스택으로 수열 만들기
// Stack

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a(N, 0);
	vector<char> resultV;
	stack<int> s;
	int num = 1;
	bool result = true;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < a.size(); i++) {
		int su = a[i];
		if (su >= num) {
			while (su >= num) {
				s.push(num++);
				resultV.push_back('+');
			}
			s.pop();
			resultV.push_back('-');
		}
		else {
			int n = s.top();
			s.pop();
			if (n > su) {
				cout << "NO";
				result = false;
				break;
			}
			else {
				resultV.push_back('-');
			}
		}

	}
	if (result) {
		for (int i = 0; i < resultV.size(); i++) {
			cout << resultV[i] << '\n';
		}
	}
}
