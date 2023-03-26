#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
int n, ans, v[MM], a[MM], c[MM], in[MM]; queue<int> q;
int main(){
    n = re;
    for (int i = 1; i <= n; i++) in[v[i] = re]++, a[i] = re;
    for (int i = 1; i <= n; i++)
        if (!in[i]) q.push(i);
    while(q.size()){
        int u = q.front(); q.pop();
        ans += max(0, a[u] - c[u]), c[v[u]] += a[u];
        if (!--in[v[u]]) q.push(v[u]);
    }
    for (int i = 1; i <= n; i++){
        if (!in[i]) continue; 
        int mn = 1e9;
        for (int j = i; in[j]; j = v[j]){
            int x = max(0, a[v[j]] - a[j] - c[v[j]]), y = max(0, a[v[j]] - c[v[j]]);
            ans += x, mn = min(mn, y), in[j] = 0;
        } ans += mn;
    } printf("%d\n", ans);
}
