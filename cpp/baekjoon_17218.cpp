#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string s1, s2;
int l1, l2;

int arr[50][50];

int main() {
	cin >> s1 >> s2;

	l1 = s1.length();
	l2 = s2.length();
	
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {

			if (s1[i - 1] == s2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}

		}
	}

	string ans = "";
	int i = l1;
	int j = l2;

	while (i > 0 && j > 0) {
		if (arr[i - 1][j] == arr[i][j]) {
			i--;
		}
		else if (arr[i][j - 1] == arr[i][j]) {
			j--;
		}
		else {
			ans += s1[i - 1];
			i--;
			j--;
		}
	}

	reverse(ans.begin(), ans.end());

	if (ans.length() > 0) cout << ans;

	return 0;
}