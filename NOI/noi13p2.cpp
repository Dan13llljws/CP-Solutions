#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
int n, a[MM], pos[MM], psa[MM]; double ans;
int main(){
    n = re, ans = 2;
    for (int i = 1; i <= n; i++) a[re] = i;
    for (int i = 1; i <= n; i++) pos[a[re]] = i;
    for (int i = 1; i <= n; i++) a[pos[i]] = i;
    for (int i = 2; i <= n; i++){
        if (a[i] < a[i - 1]) ans = ans + 1.0, psa[i - 1]++, psa[i]--;
        if (pos[i - 1] < pos[i] - 1) psa[pos[i - 1]]++, psa[pos[i]]--;
    } 
    for (int i = 2; i < n; i++) psa[i] += psa[i - 1], ans += psa[i] ? 0 : 0.5;
    printf("%.3f\n", ans);
}
