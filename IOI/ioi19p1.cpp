#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
int n, p[MM], bit[MM], vis[MM]; ll ans; vector<int> l[MM], r[MM];
void upd(int x){
    for (x++; x <= n; x += x & -x) bit[x]++;
}
int get(int x){
    int ret = 0;
    for (x++; x; x -= x & -x) ret += bit[x];
    return ret;
}
ll count_swaps(vector<int> S){
    n = S.size();
    for (int i = 0; i < n; i++)
        if (S[i] < 0) l[-S[i]].push_back(i);
        else r[S[i]].push_back(i);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (int)l[i].size(); j++)
            if (l[i][j] < r[i][j]) p[l[i][j]] = r[i][j];
            else p[r[i][j]] = l[i][j];
    for (int i = 0; i < n; i++){
        if (vis[i]) continue;
        ans += p[i] - get(p[i]) - 1, vis[p[i]] = 1, upd(i), upd(p[i]);
        if (S[i] > 0) ans++;
    } return ans;
}
int main(){}
