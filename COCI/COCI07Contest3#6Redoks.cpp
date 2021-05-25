#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 25e4 + 5;
struct node{int lz, a[10], v;}seg[MM<<2];
int n, m, a[10]; char s[MM];
void push_up(int i){
	seg[i].v = seg[lc].v + seg[rc].v;
	for (int j = 0; j < 10; j++) seg[i].a[j] = seg[lc].a[j] + seg[rc].a[j];
}
void push_down(int i){
	if (!seg[i].lz) return;
	int lz = seg[i].lz;
	seg[lc].v = seg[rc].v = 0;
	for (int j = 0; j < 10; j++) a[j] = seg[lc].a[(j - lz + 10) % 10];
	for (int j = 0; j < 10; j++) seg[lc].v += (seg[lc].a[j] = a[j]) * j;
	for (int j = 0; j < 10; j++) a[j] = seg[rc].a[(j - lz + 10) % 10];
	for (int j = 0; j < 10; j++) seg[rc].v += (seg[rc].a[j] = a[j]) * j;
	seg[lc].lz += lz, seg[rc].lz += lz, seg[lc].lz %= 10, seg[rc].lz %= 10, seg[i].lz = 0;
}
void build(int i, int l = 0, int r = n - 1){
	if (l == r){seg[i].a[seg[i].v = s[l] - '0']++; return;}
	int mid = (l + r) >> 1;
	build(lc, l, mid), build(rc, mid + 1, r);
	push_up(i);
}
void update(int i, int l, int r, int l1 = 0, int r1 = n - 1){
	if (l == l1 && r == r1){
		seg[i].v = 0, seg[i].lz++, seg[i].lz %= 10;
		for (int j = 0; j < 10; j++) a[j] = seg[i].a[(j + 9) % 10];
		for (int j = 0; j < 10; j++) seg[i].v += (seg[i].a[j] = a[j]) * j;
		return;
	}
	push_down(i);
	int mid = (l1 + r1) >> 1;
	if (r <= mid) update(lc, l, r, l1, mid);
	else if (l > mid) update(rc, l, r, mid + 1, r1);
	else update(lc, l, mid, l1 , mid), update(rc, mid + 1, r, mid + 1, r1);
	push_up(i);
}
int query(int i, int l, int r, int l1 = 0, int r1 = n - 1){
	if (l == l1 && r == r1) return seg[i].v;
	push_down(i);
	int mid = (l1 + r1) >> 1;
	if (r <= mid) return query(lc, l, r, l1, mid);
	if (l > mid) return query(rc, l, r, mid + 1, r1);
	return query(lc, l, mid, l1, mid) + query(rc, mid + 1, r, mid + 1, r1);
}	
int main(){
	n = re, m = re; scanf("%s", s);
	build(1);
	while(m--){
		int l = re - 1, r = re - 1;
		printf("%d\n", query(1, l, r));	
		update(1, l, r);
	}
}
