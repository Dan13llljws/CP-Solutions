#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	multiset<int> s;
	int ans = 0;
	while(n--){
		int a;
		cin >> a;
		if (s.empty() || a >= *s.rbegin()) s.insert(a), ans++;
		else s.erase(s.upper_bound(a)), s.insert(a);
	}
	cout << ans << '\n';
}

