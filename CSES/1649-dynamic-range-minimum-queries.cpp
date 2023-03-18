#include <bits/stdc++.h>
using namespace std;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e5 + 5;
struct node{
	int l, r, v;
} seg[MM<<2];
void build(int i, int l, int r, vector<int> &a){
	seg[i].l = l, seg[i].r = r;
	if (l == r){
		seg[i].v = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid, a);
	build(rc, mid + 1, r, a);
	seg[i].v = min(seg[lc].v, seg[rc].v);
}
void update(int i, int p, int v){
	if (seg[i].l == p && seg[i].r == p){
		seg[i].v = v; 
		return;
	}
	int mid = (seg[i].l + seg[i].r) >> 1;
	if (p <= mid) update(lc, p, v);
	else update(rc, p, v);
	seg[i].v = min(seg[lc].v, seg[rc].v);
}
int query(int i, int l, int r){
	if (seg[i].l == l && seg[i].r == r) return seg[i].v;
	int mid = (seg[i].l + seg[i].r) >> 1;
	if (r <= mid) return query(lc, l, r);
	if (l > mid) return query(rc, l, r);
	return min(query(lc, l, mid), query(rc, mid + 1, r));
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n, a);
	while(q--){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
			update(1, x, y);
		else 
			cout << query(1, x, y) << '\n';
	}
}
