#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e5 + 5;
struct node{ll v, lz;} seg[MM<<2];
int n, m, pa[MM], ch[MM], p[MM]; ll dp[MM];
void push_down(int i){
	if (!seg[i].lz) return;
	seg[lc].lz += seg[i].lz, seg[rc].lz += seg[i].lz;
	seg[lc].v +=  seg[i].lz, seg[rc].v += seg[i].lz, seg[i].lz = 0;
}
void upd(int i, int l, int r, ll v, int l1 = 1, int r1 = n){
	if (r < l) return;
	if (l1 == l && r1 == r){seg[i].v += v, seg[i].lz += v; return;}
	int mid = (l1 + r1) >> 1; push_down(i);
	if (r <= mid) upd(lc, l, r, v, l1, mid);
	else if (l > mid) upd(rc, l, r, v, mid + 1, r1);
	else upd(lc, l, mid, v, l1, mid), upd(rc, mid + 1, r, v, mid +1, r1);
	seg[i].v = min(seg[lc].v, seg[rc].v);
}
ll qry(int i, int l, int r, int l1 = 1, int r1 = n){
	if (r < l) return 1e15;
	if (l1 == l && r1 == r) return seg[i].v;
	int mid = (l1 + r1) >> 1; push_down(i);
	if (r <= mid) return qry(lc, l, r, l1, mid);
	if (l > mid) return qry(rc, l, r, mid + 1, r1);
	return min(qry(lc, l, mid, l1, mid), qry(rc, mid + 1, r, mid + 1, r1));
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) pa[i] = i;
	for (int i = 0; i < m; i++){
		int a, b; scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		pa[b] = min(pa[b], a), ch[a] = max(ch[a], b);
	}
	for (int i = 1; i <= n; i++) ch[i] = max(ch[i], ch[i - 1]);
	for (int i = 1, j = 1; i <= n; i++){
		while(j < n && ch[j] <= i) j++;
		p[i] = j - 1;
	}
	for (int i = 2; i <= n; i++)
		upd(1, 1, pa[i] - 1, 1), upd(1, i, i, dp[i] = qry(1, 1, min(i - 1, p[i])));
	printf("%lld\n", dp[n]);
		
}

