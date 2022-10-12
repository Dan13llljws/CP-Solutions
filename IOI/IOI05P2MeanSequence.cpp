#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    int l = 0, r = 1e9;
    scanf("%d", &l);
    for (int i = 1; i < n; i++){
        int x; scanf("%d", &x);
        int nl = max(x + x - r, x), nr = x + x - l;
        l = nl, r = nr;
    }
    if (r < l) puts("0");
    else printf("%d\n", r - l + 1);

}


