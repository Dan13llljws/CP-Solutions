#include <bits/stdc++.h>
int a, b;
int main(){
    scanf("%d%d", &a, &b);
    if (a == 0) puts("0");
    else if (a % b == 0) printf("%d", a / b);
    else {
        int q = a / b, g = std::__gcd(a, b);
        a %= b, a /= g, b /= g;
		if (q) printf("%d ", q);
        printf("%d/%d\n", a, b);
    }
    return 0;
}
