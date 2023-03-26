#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5e5 + 5;
struct S{
    int i, t, l, r, v;
    bool operator <(const S &o) const {return v < o.v;}
};
int n, k, L, R, psa[MM], st[20][MM]; ll ans; priority_queue<S> q;
int get(int l, int r){
    int j = 31 - __builtin_clz(r - l + 1), lft = st[j][l], rit = st[j][r - (1 << j) + 1];
    return psa[lft] > psa[rit] ? lft : rit;
}
int main(){
    n = re, k = re, L = re, R = re;
    for (int i = 1; i <= n; i++) psa[i] = psa[i - 1] + re, st[0][i] = i;
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++){
            int l = st[i - 1][j], r = st[i - 1][j + (1 << (i - 1))];
            psa[l] > psa[r] ? st[i][j] = l : st[i][j] = r;
        }
    for (int i = 1; i <= n; i++){
        if (i + L > n + 1) continue;
        int t = get(i + L - 1, min(n, i + R - 1));
        q.push({i, t, i + L - 1, min(n, i + R - 1), psa[t] - psa[i - 1]});
    }
    while(k--){
        S u = q.top(); q.pop(); ans += u.v;
        if (u.l < u.t){
            int t = get(u.l, u.t - 1);
            q.push({u.i, t, u.l, u.t - 1, psa[t] - psa[u.i - 1]});
        } 
        if (u.t < u.r){
            int t = get(u.t + 1, u.r);
            q.push({u.i, t, u.t + 1, u.r, psa[t] - psa[u.i - 1]});
        }
    } printf("%lld\n", ans);
}
