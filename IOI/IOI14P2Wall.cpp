#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define lc i << 1
#define rc i << 1 | 1
const int MM = 2e6 + 5;
struct node{int l, r, lz1, lz2;}seg[MM << 2];
void update_add(int i, int v){
	seg[i].lz1 = max(seg[i].lz1, v);
	seg[i].lz2 = max(seg[i].lz2, v);
}
void update_remove(int i, int v){
	seg[i].lz1 = min(seg[i].lz1, v);
	seg[i].lz2 = min(seg[i].lz2, v);
}
void push_down(int i){
	update_add(lc, seg[i].lz1);
	update_add(rc, seg[i].lz1);
	seg[i].lz1 = 0;
	update_remove(lc, seg[i].lz2);
	update_remove(rc, seg[i].lz2);
	seg[i].lz2 = INF;
}
void build(int i, int l, int r){
	seg[i].l = l, seg[i].r = r;
	if (l == r) return;
	seg[i].lz2 = INF;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid + 1, r);
}
void add(int i, int l, int r, int v){
	if (seg[i].l == l && seg[i].r == r){
		update_add(i, v); return;
	}
	push_down(i);
	int mid = seg[i].l + seg[i].r >> 1;
	if (r <= mid) add(lc, l, r, v);
	else if (l > mid) add(rc, l, r, v);
	else add(lc, l, mid, v), add(rc, mid + 1, r, v);
}
void remove(int i, int l, int r, int v){
	if (seg[i].l == l && seg[i].r == r){
		update_remove(i, v); return;
	}
	push_down(i);
	int mid = seg[i].l + seg[i].r >> 1;
	if (r <= mid) remove(lc, l, r, v);
	else if (l > mid) remove(rc, l, r, v);
	else remove(lc, l, mid, v), remove(rc, mid + 1, r, v);
}
int query(int i, int pos){
	if (seg[i].l == pos && seg[i].r == pos) return seg[i].lz2;
	push_down(i);
	int mid = seg[i].l + seg[i].r >> 1;
	if (pos <= mid) return query(lc, pos);
	else return query(rc, pos);
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
	build(1, 1, n);
	for (int i = 0; i < k; i++){
		if (op[i] == 1) add(1, left[i] + 1, right[i] + 1, height[i]);
		else remove(1, left[i] + 1, right[i] + 1, height[i]);
	}
	for (int i = 0; i < n; i++) finalHeight[i] = query(1, i + 1);
}
int main(){
	return 0;
}

