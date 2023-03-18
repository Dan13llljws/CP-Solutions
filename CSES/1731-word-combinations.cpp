#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 1e6 + 5;
int tot, trie[MM][26]; bool ed[MM];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	string t;
	cin >> t >> k;
	n = t.size();
	memset(trie, -1, sizeof trie);
	for (int i = 0; i < k; i++){
		string s;
		cin >> s;
		int rt = 0;
		reverse(s.begin(), s.end());
		for (int j = 0; j < (int)s.size(); j++){
			if (trie[rt][s[j] - 'a'] == -1) trie[rt][s[j] - 'a'] = ++tot;
			rt = trie[rt][s[j] - 'a'];
		}
		ed[rt] = 1;
	}
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		int rt = 0;
		for (int j = i; j >= 0; j--){
			if (trie[rt][t[j] - 'a'] == -1) break;
			rt = trie[rt][t[j] - 'a'];
			if (ed[rt]) dp[i + 1] = (dp[i + 1] + dp[j]) % mod;
		}
	}
	cout << dp[n] << '\n';
}
