#include <stdio.h>
typedef long long ll;
int a, b, ans, cnt; ll best;
int main(){
    scanf("%d%d", &a, &b);
    for (int i = 1; a >= i * b; i++){
        ll cur = i * (a - i * b);
        if (cur == best) cnt++;
        if (cur > best) best = cur, ans = i, cnt = 1;
    } printf("%d\n", cnt == 1 ? ans : 0);
}
