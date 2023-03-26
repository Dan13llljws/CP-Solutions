#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5005;
int n, m, q, x, a, b, c, d, px, py, l[MM], r[MM], pos[MM*MM], ord[MM*MM];
int main(){
    x = re, a = re, b = re, c = re, d = re, n = re, m = re, q = re;
    iota(ord + 1, ord + 1 + m * n, 1);
    for (int i = 1; i <= n * m; i++)
        x = (1LL * a * x * x + 1LL * b * x + c) % d, swap(ord[i], ord[x % i + 1]);
    while(q--) swap(ord[re], ord[re]);
    for (int i = 1; i <= n * m; i++) pos[ord[i]] = i;
    for (int i = 1; i <= n; i++) l[i] = 1, r[i] = m;
    for (int i = 1; i <= n * m; i++){
        px = (pos[i] - 1) / m + 1, py = (pos[i] - 1) % m + 1;
        if (py < l[px] || py > r[px]) continue;
        printf("%d ", i);
        for (int j = px - 1; j && r[j] > py; j--) r[j] = py;
        for (int j = px + 1; j && l[j] < py; j++) l[j] = py;
    } puts("");
}
