#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, base = 131;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	int i = 0, j = 1, cnt = 0;
	while (i < n && j < n && cnt < n){
		int x = i + cnt, y = j + cnt;
		if (x >= n) x -= n;
		if (y >= n) y -= n;
		if (s[x] == s[y]) cnt++;
		else {
			if (s[x] > s[y]) i = i + cnt + 1, j = i + 1;
			else j = j + cnt + 1;
			if (i == j) j++;
			cnt = 0;
		}
	}
	cout << s.substr(i, n - i) + s.substr(0, i) << '\n';
}

