#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s, t;
	cin >> s >> t;
	vector<int> p(t.size());
	for (int i = 1, j = 0; i < (int)t.size(); i++){
		while(j && t[i] != t[j]) j = p[j - 1];
		if (t[i] == t[j]) j++;
		p[i] = j;
	}
	int ans = 0;
	for (int i = 0, j = 0; i < (int)s.size(); i++){
		while(j && s[i] != t[j]) j = p[j - 1];
		if (t[j] == s[i]) j++;
		if (j == (int)t.size()) ans++, j = p[j - 1];
	}
	cout << ans << '\n';
}

