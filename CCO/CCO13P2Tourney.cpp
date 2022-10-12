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
const int MM = 1 << 20;
struct node{int l, r, val, id;}seg[MM << 2];
int n, m;
void push_up(int i){
	if (seg[lc].val > seg[rc].val) seg[i].val = seg[lc].val, seg[i].id = seg[lc].id;
	else seg[i].val = seg[rc].val, seg[i].id = seg[rc].id;
}
void build(int i, int l, int r){
	seg[i].l = l, seg[i].r = r;
	if (l == r){
		sc(seg[i].val), seg[i].id = l; return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid + 1, r);
	push_up(i);
}
void update(int i, int pos, int v){
	if (seg[i].l == pos && seg[i].r == pos){
		seg[i].val = v; return;
	}
	int mid = seg[i].l + seg[i].r >> 1;
	if (pos <= mid) update(lc, pos, v);
	else update(rc, pos, v);
	push_up(i);
}
int get(int i, int pos){
	if (seg[i].id == pos) return seg[i].r - seg[i].l + 1;
	int mid = seg[i].l + seg[i].r >> 1;
	if (pos <= mid) return get(lc, pos);
	return get(rc, pos);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n, m); n = (1 << n);
	build(1, 1, n);
	while(m--){
		char cmd; sc(cmd);
		if (cmd == 'R'){
			int i, s; sc(i, s);
			update(1, i, s);
		}
		else if (cmd == 'W') pr(seg[1].id, nl);
		else {
			int i; sc(i);
			pr(log2(get(1, i)), nl);
		}
	}
	return 0;
}


