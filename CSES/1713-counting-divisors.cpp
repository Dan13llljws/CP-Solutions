#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		int ans = 0;
		for (int i = 1; i * i <= a; i++)
			if (a % i == 0){
				ans += 2;
				if (a / i == i) ans--;
			}
		cout << ans << '\n';
	}
}
