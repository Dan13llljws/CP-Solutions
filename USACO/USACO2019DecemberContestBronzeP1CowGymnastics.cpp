#include <bits/stdc++.h>
using namespace std;
int n, k, p[11][21], cnt, c[21][21];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                c[p[i][j]][p[i][k]]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (c[i][j] == k) cnt++;
    cout << cnt;
    return 0;
}
