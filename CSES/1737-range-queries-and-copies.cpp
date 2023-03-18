#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int t = 1;
struct node{// 0-indexed
	int lc, rc;
	long long s;
}; vector<node> seg(MM*40);
void update(int &i, int p, int v, int l1, int r1){
	seg[t].lc = seg[i].lc;
	seg[t].rc = seg[i].rc;
	seg[t].s = seg[i].s + v;
	i = t++;
	if (l1 == r1) return;
	int mid = (l1 + r1) >> 1;
	if (p <= mid) update(seg[i].lc, p, v, l1, mid);
	else update(seg[i].rc, p, v, mid + 1, r1);
}
long long query(int i, int l, int r, int l1, int r1){
	if (l == l1 && r == r1) return seg[i].s;
	int mid = (l1 + r1) >> 1;
	if (r <= mid) return query(seg[i].lc, l, r, l1, mid);
	if (l > mid) return query(seg[i].rc, l, r, mid + 1, r1);
	return query(seg[i].lc, l, mid, l1, mid) + query(seg[i].rc, mid + 1, r, mid + 1, r1);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> rt = {0};
	for (int i = 1, a; i <= n; i++)
		cin >> a, update(rt[0], i, a, 1, n);
	while(q--){
		int tp;
		cin >> tp;
		if (tp == 1){
			int k, a, x;
			cin >> k >> a >> x, k--;
			update(rt[k], a, x - query(rt[k], a, a, 1, n), 1, n);
		} else if (tp == 2){
			int k, a, b; 
			cin >> k >> a >> b, k--;
			cout << query(rt[k], a, b, 1, n) << '\n';
		} else {
			int k;
			cin >> k, k--;
			rt.push_back(rt[k]);
		}
	}
}
