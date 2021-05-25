#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 3e5 + 5;
int N, anc[MM][20], s[MM], t[MM];
int lca(int u, int v){
    if (s[u] < s[v]) swap(u, v);
    for (int i = ceil(log2(N)); i >= 0; i--)
        if (s[u] - (1 << i) >= s[v]) u = anc[u][i];
    if (u == v) return u;
    for (int i = ceil(log2(N)); i >= 0; i--)
        if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
    return anc[u][0];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N); 
    for (int i = 1; i <= N; i++){
        char cmd; int x; sc(cmd, x); x = t[x];
        if (cmd == 'a'){
            anc[i][0] = x; s[i] = s[x] + 1; t[i] = i; anc[i][0] = x;
            for (int j = 1; j <= ceil(log2(N)); j++) anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
        else if (cmd == 'b'){
            t[i] = anc[x][0];
            pr(t[x], nl);
        }
        else {
            int y; sc(y);
            y = t[y]; t[i] = x;
            pr(s[lca(x, y)], nl);
        }
    }
    return 0;
}