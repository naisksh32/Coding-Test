#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
int vowel = 0;
int consonant = 0;

vector<char> pw;
vector<char> v;

void DFS(int level, int idx) {
	// 기저
	// L개 만큼 문자를 구성하면
	if (level >= L) {
		// 모음이 1개 이상, 자음이 2개 이상 있을 때
		if(vowel>=1 && consonant >=2){
			for (int i = 0; i < L; i++) {
				cout << v[i];
			}
			//cout << '<' << consonant << ", " << vowel << '>';
			cout << endl;
		}
		return;
	}

	// 재귀
	for (int i = idx; i < C; i++) {
		// 모음이 들어오는 경우
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') {
			v.push_back(pw[i]);
			vowel++;
			DFS(level + 1, i + 1);
			v.pop_back();
			vowel--;
		}

		// 자음이 들어오는 경우
		else {
			v.push_back(pw[i]);
			consonant++;
			DFS(level + 1, i + 1);
			v.pop_back();
			consonant--;
		}

	}
}


int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		pw.push_back(c);
	}

	sort(pw.begin(), pw.end());

	DFS(0, 0);

	return 0;
}