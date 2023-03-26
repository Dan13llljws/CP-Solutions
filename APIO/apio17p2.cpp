#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005, MN = 105;
int n, m, k, b[MN][MM], s[MN][MM], g[MN][MN]; ll d[MN][MN], dp[MN][MN];
bool check(int x){
    memset(dp, 0x3f, sizeof dp); 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            if (d[i][j] <= 1e9) dp[i][j] = min(dp[i][j], x * d[i][j] - g[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int i1 = 1; i1 <= n; i1++)
                dp[j][i1] = min(dp[j][i1], dp[j][i] + dp[i][i1]);
    for (int i = 1; i <= n; i++) 
        if (dp[i][i] <= 0) return 1;
    return 0;
}
int main(){
    n = re, m = re, k = re, memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) 
            b[i][j] = re, s[i][j] = re;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int i1 = 1; i1 <= k; i1++)
                if (s[j][i1] != -1 && b[i][i1] != -1) 
                    g[i][j] = max(g[i][j], s[j][i1] - b[i][i1]);
    for (int i = 0; i < m; i++){
        int u = re, v = re, w = re;
        d[u][v] = w;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int i1 = 1; i1 <= n; i1++)
                d[j][i1] = min(d[j][i1], d[j][i] + d[i][i1]);
    int l = 0, r = 1e9;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    } printf("%d\n", l);
}
