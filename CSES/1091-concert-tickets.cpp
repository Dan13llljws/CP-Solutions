#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	multiset<int> s;
	while(n--){
		int a;
		cin >> a;
		s.insert(-a);
	}
	while(m--){
		int a;
		cin >> a;
		auto it = s.lower_bound(-a);
		if (it == s.end()) cout << -1 << '\n';
		else {
			cout << -(*it) << '\n';
			s.erase(it);
		}
	}
}
