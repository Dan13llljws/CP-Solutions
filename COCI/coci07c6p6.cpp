#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, a[MM], b[MM], c[3]; ll dp[MM];
int main(){
    n = re, memset(dp, 0x3f, sizeof dp), dp[0] = 0;
    for (int i = 1; i <= n; i++) a[i] = re, b[i] = re;
    sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 3 && i > j; j++){
            for (int k = 0; k <= j; k++) c[k] = b[i - k];
            sort(c, c + j + 1);
            do{
                int w = 0;
                for (int k = 0; k <= j; k++){
                    if (c[k] == a[i - k]) w = 1e9;
                     w += abs(c[k] - a[i - k]);
                } dp[i] = min(dp[i], w + dp[i - j - 1]);
            } while(next_permutation(c, c + j + 1));
        }
    } printf("%lld\n", dp[n]);
}
