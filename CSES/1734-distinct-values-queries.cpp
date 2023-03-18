#include <bits/stdc++.h>
using namespace std;
struct Q{
	int idx, l, r;
};
vector<int> bit(200005);
void update(int x, int v){
	for (; x <= 200000; x += x & -x)
		bit[x] += v;
}
int query(int x){
	int ret = 0;
	for (; x; x -= x & -x)
		ret += bit[x];
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), comp;
	for (int i = 1; i <= n; i++)
		cin >> a[i], comp.push_back(a[i]);
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
	vector<int> pre(comp.size() + 1, 0);
	vector<Q> que(q);
	for (int i = 0; i < q; i++)
		cin >> que[i].l >> que[i].r, que[i].idx = i;
	sort(que.begin(), que.end(), [](const Q& a1, const Q& a2){
		return a1.r < a2.r;
	});
	vector<int> ans(q);
	int ptr = 0;
	for (int i = 1; i <= n; i++){
		if (pre[a[i]]) update(pre[a[i]], -1);
		update(i, 1);
		pre[a[i]] = i;
		while(que[ptr].r <= i && ptr < q){
			ans[que[ptr].idx] = query(que[ptr].r) - query(que[ptr].l - 1);
			ptr++;
		}
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}
