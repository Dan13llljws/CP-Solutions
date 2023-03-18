#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define lc i << 1
#define rc i << 1 | 1
struct node{
	int l, r, v;
}; vector<node>seg(MM<<2);
void build(int i, int l, int r, vector<int> &a){
	seg[i].l = l, seg[i].r = r;
	if (l == r){
		seg[i].v = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid, a);
	build(rc, mid + 1, r, a);
	seg[i].v = max(seg[lc].v, seg[rc].v);
}
int query(int i, int v){
	if (seg[i].l == seg[i].r){
		if (seg[i].v < v) return 0;
		seg[i].v -= v;
		return seg[i].l;
	}
	int ret = 0;
	if (seg[lc].v >= v) ret = query(lc, v);
	else if (seg[rc].v >= v) ret = query(rc, v);
	seg[i].v = max(seg[lc].v, seg[rc].v);
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	build(1, 1, n, a);
	while(m--){
		int x; 
		cin >> x;
		cout << query(1, x) << '\n';
	}
}
