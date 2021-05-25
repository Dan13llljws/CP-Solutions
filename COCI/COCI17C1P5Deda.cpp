#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e5 + 5;
struct node{int l, r, val;} seg[MM << 4];
int N, Q;
void build(int i, int l, int r){
	seg[i].l = l, seg[i].r = r, seg[i].val = INF;
	if (l == r) return;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid + 1, r);
}
void update(int i, int pos, int v){
	if (seg[i].l == pos && seg[i].r == pos){
		seg[i].val = v; return;
	}
	int mid = seg[i].l + seg[i].r >> 1;
	if (pos <= mid) update(lc, pos, v);
	else update(rc, pos, v);
	seg[i].val = min(seg[lc].val, seg[rc].val);
}
int get(int i, int l, int r, int v){
	if (seg[i].val > v) return INF;
	if (seg[i].l == seg[i].r) return seg[i].l;
	int mid = seg[i].l + seg[i].r >> 1;
	if (r <= mid) return get(lc, l, r, v);
	if (l > mid) return get(rc, l, r, v);
	int t = get(lc, l, mid, v);
	if (t != INF) return t;
	return get(rc, mid + 1, r, v);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, Q); build(1, 1, N);
	while (Q--){
		char cmd; int a, b; sc(cmd, a, b);
		if (cmd == 'M') update(1, b, a);
		else {
			int tmp = get(1, b, N, a);
			pr(tmp == INF ? -1 : tmp, nl);
		}
	}
	return 0;
}
