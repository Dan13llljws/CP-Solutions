#include <bits/stdc++.h>
using namespace std;
#define lc i << 1
#define rc i << 1 | 1
struct node{
	int l, r; long long v, lz1, lz2;
}; vector<node> seg(800005);
void push_down(int i){
	if (seg[i].lz2){
		seg[lc].v = 1LL * (seg[lc].r - seg[lc].l + 1) * seg[i].lz2;
		seg[rc].v = 1LL * (seg[rc].r - seg[rc].l + 1) * seg[i].lz2;
		seg[lc].lz1 = seg[rc].lz1 = 0;
		seg[lc].lz2 = seg[rc].lz2 = seg[i].lz2;
		seg[i].lz2 = 0;
	}
	if (seg[i].lz1){
		seg[lc].v += 1LL * (seg[lc].r - seg[lc].l + 1) * seg[i].lz1;
		seg[rc].v += 1LL * (seg[rc].r - seg[rc].l + 1) * seg[i].lz1;
		seg[lc].lz1 += seg[i].lz1, seg[rc].lz1 += seg[i].lz1;
		seg[i].lz1 = 0;
	}
}
void build(int i, int l, int r, vector<int> &a){
	seg[i].l = l, seg[i].r = r;
	if (l == r){
		seg[i].v = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid, a);
	build(rc, mid + 1, r, a);
	seg[i].v = seg[lc].v + seg[rc].v;
}
void update(int i, int l, int r, int v, int t){
	if (seg[i].l == l && seg[i].r == r){
		if (t == 2){
			seg[i].lz2 = v;
			seg[i].lz1 = 0;
			seg[i].v = 1LL * (r - l + 1) * v;
		} else {
			seg[i].v += 1LL * (r - l + 1) * v;
			seg[i].lz1 += v;
		}
		return;
	}
	push_down(i);
	int mid = (seg[i].l + seg[i].r) >> 1;
	if (r <= mid) update(lc, l, r, v, t);
	else if (l > mid) update(rc, l, r, v, t);
	else update(lc, l, mid, v, t), update(rc, mid + 1, r, v, t);
	seg[i].v = seg[lc].v + seg[rc].v;
}
long long query(int i, int l, int r){
	if (seg[i].l == l && seg[i].r == r) return seg[i].v;
	push_down(i);
	int mid = (seg[i].l + seg[i].r) >> 1;
	if (r <= mid) return query(lc, l, r);
	if (l > mid) return query(rc, l, r);
	return query(lc, l, mid) + query(rc, mid + 1, r);
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
		int t;
		cin >> t;
		if (t == 1){
			int l, r, x;
			cin >> l >> r >> x;
			update(1, l, r, x, 1);
		} else if (t == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			update(1, l, r, x, 2);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << '\n';
		}
	}
}
