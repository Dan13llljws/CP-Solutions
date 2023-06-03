#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while(n != 1){
		cout << n << ' ';
		if (n & 1) n = 3 * n + 1;
		else n /= 2;
	}
	cout << 1 << '\n';
}
