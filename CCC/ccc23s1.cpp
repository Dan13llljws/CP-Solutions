#include <bits/stdc++.h>
using namespace std;
int n, a[2][200005], ans;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a[0] + i), ans += 3 * a[0][i];
    for (int i = 0; i < n; i++) scanf("%d", a[1] + i), ans += 3 * a[1][i];
    for (int i = 0; i < n; i += 2)
        ans -= 2 * (a[0][i] & a[1][i]);
    for (int j : {0, 1})
        for (int i = 0; i < n - 1; i++)
            ans -= 2 * (a[j][i] & a[j][i + 1]);
    printf("%d\n", ans);
}
