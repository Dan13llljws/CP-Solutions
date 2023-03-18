#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> x >> n;
	vector<int> a(n);
	set<int> s;
	for (int &v : a) cin >> v, s.insert(v);
	s.insert(0), s.insert(x);
	reverse(a.begin(), a.end());
	int ans = 0;
	for (auto it = s.begin(); it != s.end(); it++){
		if (it == s.begin()) continue;
		auto it1 = it;
		it1--;
		ans = max(ans, *it - *it1);
	}
	vector<int> b;
	for (int v : a){
		b.push_back(ans);
		auto it = s.lower_bound(v), it1 = it, it2 = it;
		it1--, it2++;
		ans = max(ans, *it2 - *it1);
		s.erase(it);
	}
	reverse(b.begin(), b.end());
	for (int v : b) cout << v << ' ';
}

