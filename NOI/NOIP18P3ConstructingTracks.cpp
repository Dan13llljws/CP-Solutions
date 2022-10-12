#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 50005;
int n, m, tot, head[MM], f[MM], w[MM*2], v[MM*2], nxt[MM*2]; 
int dfs(int src, int par, int c){
    int ret = 0;
    multiset<int> st; vector<int> vec;
    for (int i = head[src]; i; i = nxt[i])
        if (v[i] != par)
            ret += dfs(v[i], src, c), st.insert(w[i] + f[v[i]]), vec.push_back(w[i] + f[v[i]]);
    sort(vec.begin(), vec.end());
    for (int x : vec)
        if (x >= c) st.erase(st.lower_bound(x)), ret++;
    for (int x : vec){
        if (!st.count(x)) continue;
        auto it = st.lower_bound(c - x); int p = *it;
        if (it == st.end()) continue;
        st.erase(it);
        if (!st.count(x)){st.insert(p); continue;}
        st.erase(st.lower_bound(x)), ret++;
    }
    if (st.size()) f[src] = *(--st.end());
    return ret;
}
bool check(int x){
    memset(f, 0, sizeof f);
    return dfs(1, 1, x) >= m;
}
int main(){
    n = re, m = re;
    for (int i = 1; i < n; i++){
        int a = re, b = re, c = re;
        nxt[++tot] = head[a], w[tot] = c, v[tot] = b, head[a] = tot;
        nxt[++tot] = head[b], w[tot] = c, v[tot] = a, head[b] = tot;
    } int l = 0, r = 1e9;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    } printf("%d\n", l);
}
