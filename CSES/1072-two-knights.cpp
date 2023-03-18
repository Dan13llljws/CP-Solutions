#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		if (i == 1) cout << 0 << '\n';
		else if (i == 2) cout << 6 << '\n';
		else if (i == 3) cout << 28 << '\n';
		else if (i == 4) cout << 96 << '\n';
		else if (i == 5) cout << 252 << '\n';
		else cout << (4LL * (1LL * i * i - 3) + 8LL * (1LL * i * i - 4) + 4LL * (1LL * i * i - 5) + 
					4LL * (i - 4) * (1LL * i * i - 5) + 4LL * (i - 4) * (1LL * i * i - 7) + 1LL * (i - 4) * (i - 4) * (1LL * i * i - 9)) / 2 << '\n';
	}
}
