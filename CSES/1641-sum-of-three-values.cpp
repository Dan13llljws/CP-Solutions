#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++){
		int nx = x - a[i].first;
		for (int l = i + 1, r = n - 1; l < r; l++){
			while(r > l + 1 && a[l].first + a[r].first > nx) r--;
			if (a[l].first + a[r].first == nx){
				cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second << '\n';
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

