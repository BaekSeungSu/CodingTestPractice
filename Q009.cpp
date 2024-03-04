#include<iostream>
#include<vector>
using namespace std;

vector<int> ACGT(4, 0);
vector<int> CheckACGT(4, 0);
int checkSecret = 0;
void Add(char s);
void Remove(char s);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, p;
	int count = 0;
	string DNA;
	cin >> s >> p;
	cin >> DNA;

	for (int i = 0; i < 4; i++) {
		cin >> ACGT[i];
		if (ACGT[i] == 0)
			checkSecret++;
	}


	for (int i = 0; i < p; i++) {
		Add(DNA[i]);
	}

	if (checkSecret == 4) {
		count++;
	}

	for (int i = p; i < s; i++) {
		int j = i - p;
		Add(DNA[i]);
		Remove(DNA[j]);
		if (checkSecret == 4) {
			count++;
		}
	}
	cout << count << '\n';



}

void Add(char s) {
	switch (s){
	case 'A':
		CheckACGT[0]++;
		if (CheckACGT[0] == ACGT[0])
			checkSecret++;
		break;
	case 'C':
		CheckACGT[1]++;
		if (CheckACGT[1] == ACGT[1])
			checkSecret++;
		break;
	case 'G':
		CheckACGT[2]++;
		if (CheckACGT[2] == ACGT[2])
			checkSecret++;
		break;
	case 'T':
		CheckACGT[3]++;
		if (CheckACGT[3] == ACGT[3])
			checkSecret++;
		break;
	default:
		break;
	}
}

void Remove(char s) {
	switch (s) {
	case 'A':
		if (CheckACGT[0] == ACGT[0])
			checkSecret--;
		CheckACGT[0]--;
		break;
	case 'C':
		if (CheckACGT[1] == ACGT[1])
			checkSecret--;
		CheckACGT[1]--;
		break;
	case 'G':
		if (CheckACGT[2] == ACGT[2])
			checkSecret--;
		CheckACGT[2]--;
		break;
	case 'T':
		if (CheckACGT[3] == ACGT[3])
			checkSecret--;
		CheckACGT[3]--;
		break;
	default:
		break;
	}
}