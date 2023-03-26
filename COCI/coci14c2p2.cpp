#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
int n;
char cnt[26];
string s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    cin >> n;
    n = 2 * n - 1;
    while(n--){
        cin >> s;
        for (int i = 0; i < sz(s); i++){
            cnt[i] ^= s[i];
        }
    }
    int i = 0;
    while(cnt[i]) {cout << cnt[i]; i++;}
    return 0;
}
