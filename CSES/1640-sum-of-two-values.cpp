#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> p(n);
	for (int i = 0; i < n; i++) cin >> p[i].first, p[i].second = i + 1;
	sort(p.begin(), p.end());
	for (int i = 0, j = n - 1; i < j; i++){
		while(j > i + 1 && p[i].first + p[j].first > x) j--;
		if (p[i].first + p[j].first == x){
			cout << p[i].second << ' ' << p[j].second << '\n';
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}	
