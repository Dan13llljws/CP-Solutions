#include <stdio.h>
const int mod = 1e4;
int n, m, pol, sol;
int fpow(int a, int b){
    int ret = 1;
    while(b){
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod, b >>= 1;
    } return ret;
}
int main(){
    scanf("%d", &n), m = 1;
    for (int i = 0; i < n; i++){
        int p, e; scanf("%d%d", &p, &e), m = m * fpow(p, e) % mod;
        if (p == 2) continue;
        int npol = (pol + sol * (p - 1)) % mod, nsol = (sol + (pol + 1) * (p - 1)) % mod;
        pol = npol, sol = nsol;
    } printf("%d\n%d\n%d\n", pol, sol, (m - 1 - pol - sol + mod * 2) % mod); 
}
