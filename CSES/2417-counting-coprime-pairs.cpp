#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 5;
vector<int> p[MM];
int f[MM];
int main(){
    int n;
    cin >> n;
    for (int i = 2; i < MM; i++)
        if (!p[i].size())
            for (int j = i; j < MM; j += i)
                p[j].push_back(i);
    long long ans = 0;
    for (int i = 0, x; i < n; i++){
        cin >> x;
        ans += i;
        int k = p[x].size();
        for (int mask = 1; mask < (1 << k); mask++){
            int prod = 1;
            for (int j = 0; j < k; j++)
                if (mask >> j & 1) prod *= p[x][j];
            if (__builtin_popcount(mask) & 1) ans -= f[prod];
            else ans += f[prod];
            f[prod]++;
        }
    }
    cout << ans << '\n';
}
