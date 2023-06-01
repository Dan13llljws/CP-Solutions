#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
const int MM = 3003;
bitset<MM> g[MM];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; 
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            bitset<MM> t = g[i] & g[j];
            long long x = t.count();
            ans += x * (x - 1);
        }
    }
    cout << (ans >> 1) << '\n';
}
