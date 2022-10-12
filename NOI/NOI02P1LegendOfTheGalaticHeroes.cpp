#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 30005;
int n, q, dsu[MM], d[MM], sz[MM];
int Find(int x){
    if (x == dsu[x]) return x;
    int y = Find(dsu[x]);
    d[x] += d[dsu[x]]; return dsu[x] = y;
}
void unite(int x, int y){
    x = Find(x), y = Find(y);
    d[x] = sz[y], sz[y] += sz[x], dsu[x] = y;
}
int main(){
    q = re;
    for (int i = 1; i <= 3e4; i++) dsu[i] = i, sz[i] = 1;
    while(q--){
        char c = getchar(); int x = re, y = re;
        if (c == 'M') unite(x, y);
        else if (Find(x) != Find(y)) puts("-1");
        else Find(x), Find(y), printf("%d\n", d[y] - d[x] - 1);
    }
}
