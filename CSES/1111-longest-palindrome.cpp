#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, base = 131;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	string t;	
	t.push_back('#');
	for (char c : s) t.push_back(c), t.push_back('#');
	int n = t.size();
	vector<int> p(n);
	for (int i = 0, l = 0, r = -1; i < n; i++){
		int k = i > r ? 1 : min(p[l + r - i], r - i + 1);
		while(i - k >= 0 && i + k < n && t[i + k] == t[i - k]) k++;
		p[i] = k--;
		if (i + k > r) r = i + k, l = i - k;
	}
	int ans = 0, id = 0;
	for (int i = 0; i < n; i++)
		if (p[i] - 1 > ans) ans = p[i] - 1, id = (i - p[i] + 1) / 2;
	cout << s.substr(id, ans) << '\n';
}


