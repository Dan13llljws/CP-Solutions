#include <stdio.h>
#include <algorithm>
int a; long long ans = 1e18;
int main(){
    scanf("%d", &a); long long x = 1LL * a * a + 1;
    for (int i = 1; 1LL * i * i <= x; i++){
        if (x % i) continue;
        long long j = x / i;
        ans = std::min(ans, i + j);
    } printf("%lld\n", ans + a + a);
}
