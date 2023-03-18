#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e5 + 5;
struct node{
	ll sum, mx;
}; vector<node> seg(MM<<2);
int n;
void upd(int i, int p, int v, int l1 = 0, int r1 = n){
	if (l1 == r1){
		seg[i].sum = seg[i].mx = v;
		return;
	}
	int mid = (l1 + r1) >> 1;
	if (p <= mid) upd(lc, p, v, l1, mid);
	else upd(rc, p, v, mid + 1, r1);
	seg[i].sum = seg[lc].sum + seg[rc].sum;
	seg[i].mx = max(seg[lc].mx, seg[rc].mx + seg[lc].sum);
}
pair<ll,ll> get(int i, int l, int r, int l1 = 0, int r1 = n){
	if (l == l1 && r == r1) return {seg[i].mx, seg[i].sum};
	int mid = (l1 + r1) >> 1;
	if (r <= mid) return get(lc, l, r, l1, mid);
	if (l > mid) return get(rc, l, r, mid + 1, r1);
	pair<ll,ll> lft = get(lc, l, mid, l1, mid), rit = get(rc, mid + 1, r, mid + 1, r1);
	return {max(lft.first, lft.second + rit.first), lft.second + rit.second};
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		upd(1, i, x);
	}
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) upd(1, a, b);
		else cout << max(0LL, get(1, a, b).first) << '\n';
	}
}
