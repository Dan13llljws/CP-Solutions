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
	for(; p; p -= p & -p)
		ret += bit[p];
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1, a; i <= n; i++)
		cin >> a, update(i, a), update(i + 1, -a);
	while(q--){
		int t;
		cin >> t;
		if (t == 1){
			int l, r, v;
			cin >> l >> r >> v;
			update(l, v); update(r + 1, -v);
		} else {
			int k;
			cin >> k;
			cout << query(k) << '\n';
		}
	}
}
