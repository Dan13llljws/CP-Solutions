#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lc i << 1
#define rc i << 1 | 1
#define md int mid = (l1 + r1) >> 1
const int MM = 2e5 + 5;
struct node{ll v, sum, lz;}seg[MM<<2];
int n, p[MM], pp[MM]; ll ans;
void push_up(int i){seg[i].sum = seg[lc].sum + seg[rc].sum;seg[i].v = seg[lc].v + seg[rc].v;}
void push_down(int i){
	if (!seg[i].lz) return;
	seg[lc].lz += seg[i].lz, seg[rc].lz += seg[i].lz;
	seg[lc].sum += seg[i].lz * seg[lc].v, seg[rc].sum += seg[i].lz * seg[rc].v;
	seg[i].lz = 0;
}
void upd1(int i, int pos, int v, int l1 = 1, int r1 = n){
	if (l1 == r1){seg[i].v = v, seg[i].sum = v * seg[i].lz; return;}
	md; push_down(i);
	if (pos <= mid) upd1(lc, pos, v, l1, mid);
	else upd1(rc, pos, v, mid + 1, r1);
	push_up(i);
}
void upd2(int i, int l, int r, ll v, int l1 = 1, int r1 = n){
	if (l > r) return;
	if (l == l1 && r == r1){
		seg[i].lz += v, seg[i].sum += seg[i].v * v; return;
	} md; push_down(i);
	if (r <= mid) upd2(lc, l, r, v, l1, mid);
	else if (l > mid) upd2(rc, l, r, v, mid + 1, r1);
	else upd2(lc, l, mid, v, l1, mid), upd2(rc, mid + 1, r, v, mid + 1, r1);
	push_up(i);
}
ll qry(int i, int l, int r, int l1 = 1, int r1 = n){
	if (l > r) return 0;
	if (l == l1 && r == r1) return seg[i].sum;
	md; push_down(i);
	if (r <= mid) return qry(lc, l, r, l1, mid);
	if (l > mid) return qry(rc, l, r, mid + 1, r1);
	return qry(lc, l, mid, l1, mid) + qry(rc, mid + 1, r, mid + 1, r1);
}
int main(){
	scanf("%d", &n);
	for (int i = 1, a; i <= n; i++){
		scanf("%d", &a); ans += qry(1, p[a] + 1, i - 1);
		if (p[a]) upd1(1, p[a], 0), upd2(1, pp[a] + 1, p[a] - 1, -1);
		upd1(1, i, 1), upd2(1, p[a] + 1, i - 1, 1), pp[a] = p[a], p[a] = i;
	} printf("%lld\n", ans);
}
