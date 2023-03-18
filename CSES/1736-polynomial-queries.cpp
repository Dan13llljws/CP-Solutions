#include <bits/stdc++.h>
using namespace std;
#define lc i << 1
#define rc i << 1 | 1
struct node{
	int l, r; long long v, a, b;
}; vector<node> seg(800005);
void push_down(int i){
	if (seg[i].a){
		long long k = (seg[i].b - seg[i].a) / (seg[i].r - seg[i].l);
		int mid = (seg[i].l + seg[i].r) >> 1;
		seg[lc].a += seg[i].a, seg[lc].b += seg[i].a + 1LL * (mid - seg[i].l) * k;
		seg[rc].a += seg[i].a + 1LL * (mid - seg[i].l + 1) * k, seg[rc].b += seg[i].b;
		seg[lc].v += (seg[i].a + seg[i].a + 1LL * (mid - seg[i].l) * k) * (seg[lc].r - seg[lc].l + 1) / 2;
		seg[rc].v += (seg[i].a + 1LL * (mid - seg[i].l + 1) * k + seg[i].b) * (seg[rc].r - seg[rc].l + 1) / 2;
		seg[i].a = seg[i].b = 0;
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
void update(int i, int l, int r, long long a, long long b){
	if (seg[i].l == l && seg[i].r == r){
		seg[i].v += 1LL * (a + b) * (seg[i].r - seg[i].l + 1) / 2;
		seg[i].a += a, seg[i].b += b;
		return;
	}
	push_down(i);
	int mid = (seg[i].l + seg[i].r) >> 1;
	if (r <= mid) update(lc, l, r, a, b);
	else if (l > mid) update(rc, l, r, a, b);
	else {
		long long k = (b - a) / (r - l);
		update(lc, l, mid, a, a + 1LL * (mid - l) * k), update(rc, mid + 1, r, a + 1LL * (mid - l + 1) * k, b);
	}
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
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
			update(1, l, r, 1, r - l + 1);
		else 
			cout << query(1, l, r) << '\n';
	}
}
