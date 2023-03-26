#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, MM = 1e5 + 5, base = 131;
int n, t, nxt[MM], st[MM]; ll h[MM]; char s[MM], ans[MM]; unordered_map<ll,int> mp[26];
void rec(int l, int r){
    if (l > r) return;
    int p = mp[s[l] - 'a'][h[r]];
    while(p > r) p = nxt[p];
    ans[l] = '(', ans[p] = ')', rec(l + 1, p - 1), rec(p + 1, r);
}
int main(){
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++){
        if (t && s[st[t]] == s[i]) t--, h[i] = h[st[t]];
        else h[i] = (h[st[t]] * base + s[i]) % mod, st[++t] = i;
        nxt[i] = mp[s[i] - 'a'][h[i]], mp[s[i] - 'a'][h[i]] = i;
    }
    if (t) return 0 * puts("-1");
    rec(1, n), puts(ans + 1);
}
