#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m), c(m);
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i];
	vector<long long> d(n + 1);
	vector<int> p(n + 1);
	int x = 0;
	for (int i = 0; i < n; i++){
		x = 0;
		for (int j = 0; j < m; j++)
			if (d[b[j]] > d[a[j]] + c[j]){
				d[b[j]] = d[a[j]] + c[j];
				p[b[j]] = a[j];
				x = b[j];
			}
	}
	if (!x){
		cout << "NO\n"; 
		return 0;
	}
	for (int i = 0; i < n; i++) x = p[x];
	vector<int> ans;
	for (int i = x;; i = p[i]){
		ans.push_back(i);
		if (ans.size() > 1 && i == x) break;
	}
	reverse(ans.begin(), ans.end());
	cout << "YES\n";
	for (int v : ans) cout << v << ' ';
	cout << '\n';
}
	
