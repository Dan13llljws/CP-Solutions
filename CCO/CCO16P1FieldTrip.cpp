#include <bits/stdc++.h>
using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
int n, m, k, diset[1000001], s[1000001], ans1, ans2; bool cycle[1000001];
int Find(int x){
    return diset[x] == x ? x : diset[x] = Find(diset[x]);
}
void unite(int x, int y){
    s[Find(y)] += s[Find(x)]; diset[Find(x)] = Find(y);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    scan(n); scan(m); scan(k);
    if (k == 1){
        cout << n << ' ' << m;
        return 0;
    }
    if (k == n){
        cout << n << ' ' << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {diset[i] = i; s[i] = 1;}
    for (int i = 0, x, y; i < m; i++){
        scan(x); scan(y);
        if (Find(x) != Find(y)) unite(x, y);
        else cycle[Find(y)] = 1;
    }
    for (int i = 1; i <= n; i++){
        int tmp = Find(i);
        if (s[tmp] >= k){
            ans1 += s[tmp] - s[tmp] % k;
            ans2 += (s[tmp] - 1) / k;
            if (cycle[tmp] && s[tmp] > k) ans2++;
            s[tmp] = 0;
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}