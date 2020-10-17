#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n, a, b, c, dp[3];
int main(){
    n = read();
    for (int i = 1; i <= n; i++){
        a = read(), b = read(), c = read();
        a = max(dp[1], dp[2]) + a;
        b = max(dp[0], dp[2]) + b;
        c = max(dp[0], dp[1]) + c;
        dp[0] = a, dp[1] = b, dp[2] = c;
    }
    printf("%d ", max({dp[0], dp[1], dp[2]}));
    return 0;
}
