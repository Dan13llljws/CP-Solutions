#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 2e5 + 5;
struct interval{int l, r, v;} a[MM];
struct node{ll v, lz;} seg[MM<<2];
int n, m; ll sum, dp;
void push_down(int i){
	if (seg[i].lz){
		seg[lc].lz += seg[i].lz, seg[rc].lz += seg[i].lz;
		seg[lc].v += seg[i].lz, seg[rc].v += seg[i].lz;
		seg[i].lz = 0;
	}
}
void update(int i, int l, int r, ll v, int l1 = 0, int r1 = n + 1){
	if (l == l1 && r == r1){seg[i].v += v, seg[i].lz += v; return;}
	push_down(i);
	int mid = (l1 + r1) >> 1;
	if (r <= mid) update(lc, l, r, v, l1, mid);
	else if (l > mid) update(rc, l, r, v, mid + 1, r1);
	else update(lc, l, mid, v, l1, mid), update(rc, mid + 1, r, v, mid + 1, r1);
	seg[i].v = min(seg[lc].v, seg[rc].v);
}
ll get(int i, int l, int r, int l1 = 0, int r1 = n + 1){
	if (l == l1 && r == r1) return seg[i].v;
	push_down(i);
	int mid = (l1 + r1) >> 1;
	if (r <= mid) return get(lc, l, r, l1, mid);
	if (l > mid) return get(rc, l, r, mid + 1, r1);
	return min(get(lc, l, mid, l1, mid), get(rc, mid + 1, r, mid + 1, r1));
}
int main(){
	n = re, m = re;
	for (int i = 0; i < m; i++) a[i] =  {re, re, re}, sum += a[i].v;
	sort(a, a + m, [](const interval& a1, const interval& a2){return a1.r < a2.r;});
	int ptr = 0;
	for (int i = 1; i <= n + 1; i++){
		while(ptr < m && a[ptr].r < i)
			update(1, 0, a[ptr].l - 1, a[ptr].v), ptr++;
		update(1, i, i, dp = get(1, 0, i - 1));
	}
	printf("%lld\n", sum - dp);
}

