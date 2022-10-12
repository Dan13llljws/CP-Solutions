#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7 + 5;
int t, x, f[MM], nxt[MM];
int ck(int y){
    while(y){
        if (y % 10 == 7) return 1;
        y /= 10;
    } return 0;
}
int main(){
    scanf("%d", &t);
    for (int i = 1; i < MM; i++){
        if (f[i]) continue;
        f[i] = ck(i);
        if (f[i])
            for (int j = 2 * i; j < MM; j += i) f[j] = 1;
    }
    for (int i = MM - 1, j = -1; i; i--){
        nxt[i] = j;
        if (!f[i]) j = i;
    }
    while(t--) scanf("%d", &x), printf("%d\n", f[x] ? -1 : nxt[x]);
}
