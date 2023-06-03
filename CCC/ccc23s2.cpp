#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans[5005];
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i), ans[i + 1] = 1e9;
    for (int i = 0; i < n; i++){
        int s = 0;
        for (int l = i, r = i; l >= 0 && r < n; l--, r++){
            s += abs(a[l] - a[r]);
            ans[r - l + 1] = min(ans[r - l + 1], s);
        }
        s = 0;
        for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++){
            s += abs(a[l] - a[r]);
            ans[r - l + 1] = min(ans[r - l + 1], s);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}


