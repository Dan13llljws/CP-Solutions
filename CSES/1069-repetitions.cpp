#include <bits/stdc++.h>
using namespace std;
string s; int ans, cur = 1;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 1; i < (int)s.size(); i++){
		if (s[i] == s[i - 1]) cur++;
		else ans = max(ans, cur), cur = 1;
	}
	cout << max(ans, cur) << '\n';
}
