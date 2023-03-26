#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, d, m, fav;
map<int, string> dict;
map<int, int> cnt;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        string name; int number; cin >> name >> number;
        dict[number] = name;
    }
    cin >> d;
    for (int i = 0, x; i < d; i++){
        cin >> x;
        cnt[x]++;
        if (cnt[x] > m){
            m = cnt[x];
            fav = x;
        }
        else if (m == cnt[x]){
            if (x < fav) fav = x;
        }
    }
    cout << dict[fav] << nl;
    return 0;
}