#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
bool check(int n){
    int a[6], cnt = 1;
    while(n != 0){
        a[cnt++] = n % 10;
        n /= 10;
    }
    for (int i = 1; i < cnt; i++){
        if (a[i] != 0 && a[i] != 1 && a[i] != 8 && a[i] != 6 && a[i] != 9) return false;
        if (a[i] == 0 && a[cnt - i] != 0) return false;
        if (a[i] == 1 && a[cnt - i] != 1) return false;
        if (a[i] == 8 && a[cnt - i] != 8) return false;
        if (a[i] == 6 && a[cnt - i] != 9) return false;
        if (a[i] == 9 && a[cnt - i] != 6) return false;
    }
    return true;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = n; i <= m; i++) ans += check(i);
    cout << ans;
    return 0;
}