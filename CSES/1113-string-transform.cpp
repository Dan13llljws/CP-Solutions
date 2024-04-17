#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	int n = s.size();
	vector<vector<int>> f(27);
	for (int i = 0; i < n; i++) {
		if (s[i] == '#') f[0].push_back(i);
		else f[s[i] - 'a' + 1].push_back(i);
	}
	vector<int> pos(n); int t = 0;
	for (int i = 0; i < 27; i++)
		for (int x : f[i]) pos[x] = t++;
	string ans;
	for (int i = 0, j = 0; i < n - 1; i++) 
		ans.push_back(s[j]), j = pos[j];
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
	
	
