#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	vector<int> f(26);
	for (int i = 0; i < (int)s.size(); i++) f[s[i] - 'A']++;
	int cnt = 0;
	for (int i = 0; i < 26; i++) cnt += f[i] & 1;
	if (cnt > 1){
		cout << "NO SOLUTION\n";
		return 0;
	}
	char odd = -1;
	vector<char> ans(s.size());
	int l = 0, r = s.size() - 1;
	for (int i = 0; i < 26; i++){
		if (f[i] & 1) odd = i;
		while(f[i] > 1) ans[l++] = ans[r--] = i + 'A', f[i] -= 2;
	}
	if (odd != -1) ans[l] = odd + 'A';
	for (char c : ans) cout << c;
	cout << '\n';
}
