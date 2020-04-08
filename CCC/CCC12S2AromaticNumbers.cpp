#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define sz(x) (int)(x.size())
string n; int ans;
map<char, int> val;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    val['I'] = 1; val['V'] = 5; val['X'] = 10; val['L'] = 50;
    val['C'] = 100; val['D'] = 500; val['M'] = 1000;
    cin >> n;
    for (int i = 0; i < sz(n) - 2; i += 2){
        if (val[n[i + 1]] >= val[n[i + 3]]) ans += (n[i] - '0') * val[n[i + 1]];
        else ans -= (n[i] - '0') * val[n[i + 1]];
    }    
    ans += (n[sz(n) - 2] - '0') * val[n[sz(n) - 1]];
    cout << ans << nl;
    return 0;
}
