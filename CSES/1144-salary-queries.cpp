#include <bits/stdc++.h>
using namespace std;
struct Q{
	int t, a, b;
}; 
vector<int> bit;
void update(int p, int v){
	for (; p < (int)bit.size(); p += p & -p)
		bit[p] += v;
}
int query(int p){
	int ret = 0;
	for (; p; p -= p & -p)
		ret += bit[p];
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; 
	cin >> n >> q;
	vector<int> comp;
	vector<int> p(n + 1);
	vector<Q> que;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		comp.push_back(p[i]);
		que.push_back({0, i, p[i]});
	}
	while(q--){
		char ch; int a, b;
		cin >> ch >> a >> b;
		if (ch == '!'){
			que.push_back({0, a, b});
			comp.push_back(b);
		} else {
			que.push_back({1, a, b});
			comp.push_back(a);
			comp.push_back(b);
		}
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	bit.resize(comp.size() + 5);
	for (int i = 1; i <= n; i++)
		p[i] = 0;
	for (Q &x : que){
		if (x.t){
			x.a = lower_bound(comp.begin(), comp.end(), x.a) - comp.begin() + 1;
			x.b = lower_bound(comp.begin(), comp.end(), x.b) - comp.begin() + 1;
			cout << query(x.b) - query(x.a - 1) << '\n';
		} else {
			x.b = lower_bound(comp.begin(), comp.end(), x.b) - comp.begin() + 1;
			if (p[x.a]) update(p[x.a], -1);
			update(x.b, 1);
			p[x.a] = x.b;
		}
	}
}
