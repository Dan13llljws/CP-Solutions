#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> st(ceil(log2(n)) + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) cin >> st[0][i];
	for (int i = 1; (1 << i) <= n; i++)
		for (int j = 1; j + (1 << i) <= n + 1; j++)
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	while(q--){
		int l, r; 
		cin >> l >> r;
		int j = 31 - __builtin_clz(r - l + 1);
		cout << min(st[j][l], st[j][r - (1 << j) + 1]) << '\n';
	}
}
