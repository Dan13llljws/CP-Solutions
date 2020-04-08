#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define pb push_back
int n; string s, ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        vector<string> tmp;
        for (int j = 0; j <= n - i; j++){
            tmp.pb(s.substr(j, i));
        }
        bool flag = 1;
        sort(af(tmp));
        for (int j = 1; j < sz(tmp); j++){
            if (tmp[j] == tmp[j - 1]){
                flag = 0;
                break;
            }
        }
        if (flag){
            cout << i;
            return 0;
        }
    }
    return 0;
}
