#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e5 + 5;
struct node{
	int lm, rm, sz;
}; vector<node> seg(MM<<2);
int n;
void bld(int i, int l1 = 1, int r1 = n){
	seg[i].sz = r1 - l1 + 1;
	if (l1 == r1){
		cin >> seg[i].lm, seg[i].rm = seg[i].lm;
		return;
	}
	int mid = (l1 + r1) >> 1;
	bld(lc, l1, mid);
	bld(rc, mid + 1, r1);
	seg[i].lm = min(seg[lc].lm, seg[rc].lm + seg[lc].sz);
	seg[i].rm = min(seg[rc].rm, seg[lc].rm + seg[rc].sz);
}
void upd(int i, int p, int v, int l1 = 1, int r1 = n){
	if (l1 == r1){
		seg[i].lm = seg[i].rm = v;
		return;
	}
	int mid = (l1 + r1) >> 1;
	if (p <= mid) upd(lc, p, v, l1, mid);
	else upd(rc, p, v, mid + 1, r1);
	seg[i].lm = min(seg[lc].lm, seg[rc].lm + seg[lc].sz);
	seg[i].rm = min(seg[rc].rm, seg[lc].rm + seg[rc].sz);
}
int get(int i, int l, int r, int t, int l1 = 1, int r1 = n){
	if (l == l1 && r == r1) return t ? seg[i].lm : seg[i].rm;
	int mid = (l1 + r1) >> 1;
	if (r <= mid) return get(lc, l, r, t, l1, mid);
	if (l > mid) return get(rc, l, r, t, mid + 1, r1);
	if (t) return min(get(lc, l, mid, t, l1, mid), get(rc, mid + 1, r, t, mid + 1, r1) + mid - l + 1);
	else return min(get(lc, l, mid, t, l1, mid) + r - mid, get(rc, mid + 1, r, t, mid + 1, r1));
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	bld(1);
	while(q--){
		int t;
		cin >> t;
		if (t == 1){
			int a, b;
			cin >> a >> b;
			upd(1, a, b);
		} else {
			int a;
			cin >> a;
			cout << min(get(1, 1, a, 0), get(1, a, n, 1)) << '\n';
		}
	}
}
