#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		if ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b)) cout << "YES\n";
		else cout << "NO\n";
	}
}
