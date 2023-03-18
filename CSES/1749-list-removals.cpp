#include <bits/stdc++.h>
using namespace std;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e5 + 5;
struct node{
	int l, r, s, v;
}; vector<node>seg(MM<<2);
void build(int i, int l, int r, vector<int> &a){
	seg[i].l = l, seg[i].r = r;
	if (l == r){
		seg[i].v = a[l];
		seg[i].s = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid, a);
	build(rc, mid + 1, r, a);
	seg[i].s = seg[lc].s + seg[rc].s;
}
int query(int i, int p){
	if (seg[i].l == seg[i].r){
		seg[i].s = 0;
		return seg[i].v;
	}
	int ret = 0;
	if (seg[lc].s >= p) ret = query(lc, p);
	else ret = query(rc, p - seg[lc].s);
	seg[i].s = seg[lc].s + seg[rc].s;
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	build(1, 1, n, a);
	while(n--){
		int x;
		cin >> x;
		cout << query(1, x) << ' ';
	}
}
