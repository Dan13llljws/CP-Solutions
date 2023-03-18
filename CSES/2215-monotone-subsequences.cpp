#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if (k * k < n){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        for (int i = 0, j = k; i < n; i += k, j += k){
            j = min(j, n);
            reverse(a.begin() + i, a.begin() + j);
        }
        for (int x : a) cout << x << ' ';
        cout << '\n';
    }
}
