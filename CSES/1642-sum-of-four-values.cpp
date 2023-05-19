#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    map<int, pair<int,int>> mp;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int rem = x - a[i] - a[j];
            if (mp.count(rem)){
                cout << i + 1 << ' ' << j + 1 << ' ' << mp[rem].first + 1 << ' ' << mp[rem].second + 1 << '\n';
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
            mp[a[j] + a[i]] = {j, i};
    }
    cout << "IMPOSSIBLE\n";
}

