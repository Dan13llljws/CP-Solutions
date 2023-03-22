#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 1e9;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) a[i] |= (s[j] - '0') << j;
        for (int j = 0; j < i; j++) ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
    }
    cout << ans << '\n';
}
