#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    map<int,int> cnt;
    int dist = 0;
    long long ans = 0;
    for (int i = 0, j = 0; i < n; i++){
        if (++cnt[a[i]] == 1) dist++;
        while(dist > k)
            if (!--cnt[a[j++]]) dist--;
        ans += i - j + 1;
    }
    cout << ans << '\n';
}

