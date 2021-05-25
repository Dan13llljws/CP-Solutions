#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f; const char sp=' ',nl='\n';
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, base = 131, MM = 2e5 + 5;
struct Q{int t, id;}q[MM];
struct student{int pos, id, a, b;}st[MM];
struct node{int l, r, v, id;}seg[MM<<2]; // range max query point update
int N, tot;
void build(int i, int l, int r){
	seg[i].l = l, seg[i].r = r;
	if (l == r) return;
	int mid = l + r >> 1;
	build(lc, l, mid); build(rc, mid + 1, r);
}
void update(int i, int pos, int v){
	if (seg[i].l == pos && seg[i].r == pos){seg[i].v = v; return;}
	int mid = seg[i].l + seg[i].r >> 1;
	if (pos <= mid) update(lc, pos, v);
	else update(rc, pos, v);
	seg[i].v = st[seg[lc].v].a > st[seg[rc].v].a ? seg[lc].v : seg[rc].v;
}
int query(int i, int l, int r){
	if (seg[i].l == l && seg[i].r == r) return seg[i].v;
	int mid = seg[i].l + seg[i].r >> 1;
	if (r <= mid) return query(lc, l, r);
	if (l > mid) return query(rc, l, r);
	int a = query(lc, l, mid), b = query(rc, mid + 1, r);
	return st[a].a > st[b].a ? a : b;
}
bool cmp(student a, student b){return a.b == b.b ? a.a < b.a : a.b < b.b;}
bool cmp2(student a, student b){return a.id < b.id;}
int main(){ 
	N = re;
	for (int i = 0; i < N; i++){
		char cmd = getchar();
		if (cmd == 'D') q[i].t = 0, q[i].id = ++tot, st[tot].id = tot, st[tot].a = re, st[tot].b = re;
		else q[i].t = 1, q[i].id = re;
	}
	st[tot + 1].a = st[tot + 1].b = INF;
	sort(st + 1, st + tot + 1, cmp); 
	for (int i = 1; i <= tot; i++) st[i].pos = i;
	sort(st + 1, st + tot + 1, cmp2);	
	build(1, 1, tot + 1); update(1, tot + 1, tot + 1);
	for (int i = 0; i < N; i++){ // O(Nlog^2N) 
		int t = q[i].id; 
		if (!q[i].t) update(1, st[t].pos, t);
		else {
			int l = st[t].pos + 1, r = tot + 1; 
			while(l < r){
				int mid = l + r >> 1;
				if (st[query(1, st[t].pos + 1, mid)].a >= st[t].a) r = mid;
				else l = mid + 1;
			}
			if (l == tot + 1) puts("NE");
			else printf("%d\n", query(1, st[t].pos + 1, l));
		}
	}
	return 0;
}

