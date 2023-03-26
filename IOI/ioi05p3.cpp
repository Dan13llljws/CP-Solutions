#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct node{int sum, v, lz;}seg[MM<<3];
struct Q{int tp, l, r, v;}q[MM];
int n, m, t, comp[MM*2];
void update(int i, int l, int r, int v, int l1 = 0, int r1 = m - 1){
	if (l == l1 && r == r1){
		seg[i].sum = (comp[r] - comp[l - 1]) * v, seg[i].lz = v, seg[i].v = max(seg[i].sum, 0);
		return;
	}
	int mid = (l1 + r1) >> 1;
	if (seg[i].lz != -1e9){
		update(lc, l1, mid, seg[i].lz, l1, mid); update(rc, mid + 1, r1, seg[i].lz, mid + 1, r1);
		seg[i].lz = -1e9;
	}
	if (r <= mid) update(lc, l, r, v, l1, mid);
	else if (l > mid) update(rc, l, r, v, mid + 1, r1);
	else update(lc, l, mid, v, l1, mid), update(rc, mid + 1, r, v, mid + 1, r1);
	seg[i].sum = seg[lc].sum + seg[rc].sum;
	seg[i].v = max(seg[lc].v, seg[lc].sum + seg[rc].v);
}
int query(int i, int k, int l = 0, int r = m - 1){
	if (seg[i].v <= k) return comp[r];
	if (seg[i].lz != -1e9) return comp[l - 1] + k / seg[i].lz;
	int mid = (l + r) >> 1;
	if (seg[lc].v > k) return query(lc, k, l, mid);
	return query(rc, k - seg[lc].sum, mid + 1, r);
}
int main(){
	comp[m++] = 0, comp[m++] = re;
	for (t = 0;; t++){
		q[t].tp = getchar();
		if (q[t].tp == 'E') break;
		if (q[t].tp == 'Q'){
			q[t].l = re;
		} else {
			q[t].l = re - 1, q[t].r = re, q[t].v = re;
			comp[m++] = q[t].l, comp[m++] = q[t].r;
		}
	}
	sort(comp, comp + m); m = unique(comp, comp + m) - comp;
	for (int i = 0; i < t; i++){
		if (q[i].tp == 'Q'){
			printf("%d\n", query(1, q[i].l));
		} else {
			q[i].l = lower_bound(comp, comp + m, q[i].l) - comp + 1;
			q[i].r = lower_bound(comp, comp + m, q[i].r) - comp;
			update(1, q[i].l, q[i].r, q[i].v);
		}
	}
}

