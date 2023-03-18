#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
vector<long long> bit(MM);
void update(int p, int v){
	for (; p < MM; p += p & -p)
		bit[p] += v;
}
long long query(int p){
	long long ret = 0;
	for (; p; p -= p & -p)
		ret += bit[p];
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i], update(i, a[i]);
	while(q--){
		int t, x, y; 
		cin >> t >> x >> y;
		if (t == 1){
			update(x, y - a[x]);
			a[x] = y;
		} else {
			cout << query(y) - query(x - 1) << '\n';
		}
	}
}
