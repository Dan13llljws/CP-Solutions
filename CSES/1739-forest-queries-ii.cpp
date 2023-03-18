#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> bit(1005, vector<int>(1005));
void update(int x, int y, int v){
	for (int i = x; i <= 1000; i += i & -i)
		for (int j = y; j <= 1000; j += j & -j)
			bit[i][j] += v;
}
int query(int x, int y){
	int ret = 0;
	for (int i = x; i; i -= i & -i)
		for (int j = y; j; j -= j & -j)
			ret += bit[i][j];
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
			if (s[j - 1] == '*'){
				g[i][j] = 1;
				update(i, j, 1);
			}
	}
	while(q--){
		int t; 
		cin >> t;
		if (t == 1){
			int x, y;
			cin >> x >> y;
			update(x, y, g[x][y] ? -1 : 1);
			g[x][y] = 1 ^ g[x][y];
		} else {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << (query(c, d) - query(c, b - 1) - query(a - 1, d) + query(a - 1, b - 1)) << '\n';
		}
	}
}
