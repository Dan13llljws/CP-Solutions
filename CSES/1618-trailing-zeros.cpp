#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 0, cur = 5;
	while(cur <= n) ans += n / cur, cur *= 5;
	cout << ans << '\n';
}
