#include <stdio.h>
#include <cstring>
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 105;
int n, m, tot, d[MM][MM]; ll c[MM][MM]; 
int main(){
    n = re, m = re; memset(d, 0x3f, sizeof d); 
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++){
        int a = re, b = re, e = re;
        d[a][b] = d[b][a] = e, c[a][b] = c[b][a] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (d[j][k] > d[j][i] + d[i][k]) 
                    d[j][k] = d[j][i] + d[i][k], c[j][k] = c[j][i] * c[i][k];
                else if (d[j][k] == d[j][i] + d[i][k])
                    c[j][k] += c[j][i] * c[i][k];
    for (int i = 1; i <= n; i++){
        double ans = 0;
        for (int j = 1; j <= n; j++) 
            for (int k = 1; k <= n; k++)
                if (j != i && k != i && d[j][i] + d[i][k] == d[j][k])
                    ans += c[j][i] * c[i][k] * 1.0 / c[j][k];
        printf("%.3f\n", ans);
    }
}
