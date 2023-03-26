#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 1e4 + 5;
struct rect{int a, b, c, d;} windows[5*MM];
struct node{int l, r, v;}seg[MM*20];
int C, R, n, t, st[MM<<2];
void push_down(int i){
	if (seg[i].v == -1) return;
	seg[seg[i].l].v = seg[seg[i].r].v = seg[i].v;
	seg[i].v = -1;
}
void updatey(int &i, int l, int r, int v, int l1 = 1, int r1 = C){
	if (!i) i = ++t, seg[i].v = -1;
	if (l1 == l && r1 == r){seg[i].v = v; return;}
	if (!seg[i].l) seg[i].l = ++t, seg[t].v = -1;
	if (!seg[i].r) seg[i].r = ++t, seg[t].v = -1;
	push_down(i);
	int mid = (l1 + r1) >> 1;
	if (r <= mid) updatey(seg[i].l, l, r, v, l1, mid);
	else if (l > mid) updatey(seg[i].r, l, r, v, mid + 1, r1);
	else update(seg[i].l, l, mid, v, l1, mid), updatey(seg[i].r, mid + 1, r, v, mid + 1, r1);
}
int queryy(int &i, int y, int l1 = 1, int r1 = C){
	if (l1 == r1) seg[i].v;
	
}
void updatex(int i, int lx, int rx, int ly, int ry, int v, int l1 = 1, int r1 = R){
	if (lx == l1 && rx == r1){
		updatey(st[i], ly, ry, v);
		return;
	}
	int mid = (l1 + r1) >> 1;
	if (rx <= mid) updatex(lc, lx, rx, ly, ry, v, l1, mid);
	else if updatex(rc, lx, rx, ly, ry, v, mid + 1, r1);
	else updatex(lc, lx, mid, ly, ry, v, mid + 1, r1), updatex(rc, mid + 1, rx, ly, ry, v, mid + 1, r1);
}
int queryx(int i, int x, int y, int l1 = 1, int r1 = R){
	if (l1 == r1) return queryy(st[i], y);
	int mid = (l1 + r1) >> 1;
	if (x <= mid) return queryx(lc, x, y, l1, mid);
	return queryx(rc, x, y, mid + 1, r1);
}
int main(){
	C = re, R = re, n = re;
	for (int i = 0; i < n; i++){
		windows[i] = {re, re, re, re};
	}
	
}


