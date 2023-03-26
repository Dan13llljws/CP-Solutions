#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct S{
    int r, c, h; ll s;
    bool operator < (const S &o) const {return s > o.s;}
};
int n, k, t, id[MM]; ll sum, ans; vector<int> a[MM]; priority_queue<S> q;
int main(){
    n = re, k = re;
    for (int i = 1; i <= n; i++){
        int m = re;
        if (m == 1) sum += re;
        else {
            while(m--) a[t].push_back(re);
            sort(a[t].begin(), a[t].end()), sum += a[t][0], id[t] = t, t++;
        }
    } q.push({0, 0, 0, sum});
    sort(id, id + t, [&](int x, int y){return a[x][1] - a[x][0] < a[y][1] - a[y][0];});
    while(k--){
        S u = q.top(); q.pop(); ll s = u.s; ans += s;
        int r = u.r, c = u.c, h = u.h, tr = id[r], nr = id[r + 1];
        if (c + 1 < (int)a[tr].size()) q.push({r, c + 1, 0, s + a[tr][c + 1] - a[tr][c]});
        if (r + 1 < t) q.push({r + 1, 1, 1, s + a[nr][1] - a[nr][0]});
        if (r + 1 < t && h) q.push({r + 1, 1, 1, s + a[nr][1] - a[nr][0] - a[tr][1] + a[tr][0]});
    } printf("%lld\n", ans);
}
