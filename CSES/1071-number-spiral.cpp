#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		if (max(x, y) & 1){
			long long z = max(x, y);
			cout << z * z + y - x - z + 1 << '\n';
		} else {
			long long z = max(x, y);
			cout << z * z + x - y - z + 1 << '\n';
		}
	}
}
			
