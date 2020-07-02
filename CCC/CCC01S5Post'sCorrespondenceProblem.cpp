#include <bits/stdc++.h>
using namespace std;
int n, m, k; string a[10], b[10]; vector<int> seq;
bool check(string s, string t, int cnt){
	if (cnt == k) return s == t;
	for (int i = 0; i < n; i++)
		if (check(s + a[i], t + b[i], cnt + 1)){seq.push_back(i + 1); return 1;}
	return 0;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (k = 1; k < m; k++)
		if (check("", "", 0)){
			cout << k << '\n';
			for (int i = seq.size() - 1; i >= 0; i--) cout << seq[i] << '\n';
			return 0;
		}
	cout << "No solution.\n";
}
