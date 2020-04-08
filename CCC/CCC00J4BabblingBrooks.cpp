#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define pb push_back
int n, cmd;
vector<int> stream;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        stream.pb(x);
    }
    while(1){
        cin >> cmd;
        if (cmd == 77) break;
        else if (cmd == 99){
            int l, p; cin >> l >> p;
            l--;
            stream.insert(stream.begin() + l, stream[l] * p / 100.0);
            stream[l + 1] -= stream[l];
        }
        else {
            int l; cin >> l;
            l--;
            stream[l] += stream[l + 1];
            stream.erase(stream.begin() + l + 1);
        }
    }
    for (int i = 0; i < sz(stream); i++) cout << stream[i] << ' ';
    return 0;
}