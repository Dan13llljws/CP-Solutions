#include <bits/stdc++.h>
using namespace std;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e5 + 5;
struct node{
	int l, r; long long pfx, sfx, sum, mx;
}; vector<node> seg(MM<<2);
void push_up(int i){
	seg[i].pfx = max(seg[lc].pfx, seg[lc].sum + seg[rc].pfx);
	seg[i].sfx = max(seg[rc].sfx, seg[rc].sum + seg[lc].sfx);
	seg[i].sum = seg[lc].sum + seg[rc].sum;
	seg[i].mx = max({seg[lc].mx, seg[rc].mx, seg[lc].sfx + seg[rc].pfx});
}
void build(int i, int l, int r, vector<int> &a){
	seg[i].l = l, seg[i].r = r;
	if (l == r){
		seg[i].pfx = seg[i].sfx = seg[i].mx = max(0, a[l]);
		seg[i].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid, a);
	build(rc, mid + 1, r, a);
	push_up(i);
}
void update(int i, int p, int v){
	if (seg[i].l == seg[i].r){
		seg[i].pfx = seg[i].sfx = seg[i].mx = max(0, v);
		seg[i].sum = v;
		return;
	}
	int mid = (seg[i].l + seg[i].r) >> 1;
	if (p <= mid) update(lc, p, v);
	else update(rc, p, v);
	push_up(i);
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
		int x, y;
		cin >> x >> y;
		update(1, x, y);
		cout << seg[1].mx << '\n';
	}
}
