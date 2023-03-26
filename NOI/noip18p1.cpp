#include <stdio.h>
int n, p, x, ans;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++, p = x){
        scanf("%d", &x);
        if (x > p) ans += x - p;
    } printf("%d\n", ans);
}

