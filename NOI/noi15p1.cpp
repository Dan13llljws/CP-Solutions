#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int f, t, n, tot, dsu[MM<<1], a[MM], b[MM], e[MM], cmp[MM<<1];
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){dsu[Find(x)] = Find(y);}
int main(){
    for (t = re; t; t--){
        n = re, f = 1, tot = 0;
        for (int i = 0; i < n; i++) cmp[tot++] = a[i] = re, cmp[tot++] = b[i] = re, e[i] = re;
        sort(cmp, cmp + tot), tot = unique(cmp, cmp + tot) - cmp, iota(dsu, dsu + tot, 0);
        for (int i = 0; i < n; i++){
            a[i] = lower_bound(cmp, cmp + tot, a[i]) - cmp;
            b[i] = lower_bound(cmp, cmp + tot, b[i]) - cmp;
            if (e[i]) unite(a[i], b[i]);
        }
        for (int i = 0; i < n; i++)
            if (!e[i] && Find(a[i]) == Find(b[i])){f = 0; break;}
        puts(f ? "YES" : "NO");
    }
}
