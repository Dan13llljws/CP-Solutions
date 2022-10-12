#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 1e6 + 5;
int n, k, q, ans, a[MM], tree[MM<<1], seg[MM<<1];
int comb(int i, int j){return a[i] > a[j] ? i : j;}
void upd(int p){
    for (p += n - 1; p > 1; p >>= 1) seg[p >> 1] = comb(seg[p], seg[p ^ 1]);
}
int get(int l, int r){
    int ret = 0;
    for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = comb(ret, seg[l++]);
        if (r & 1) ret = comb(ret, seg[--r]);
    } return ret;
}
void update(int p, int v){
    for (tree[p += n - 1] = v; p > 1; p >>= 1) tree[p >> 1] = max(tree[p], tree[p ^ 1]);
}
void updLR(int i){
    int mx = max(a[get(max(1, i - k + 1), i - 1)], a[get(i + 1, min(n, i + k - 1))]);
    if (a[i] >= mx) update(i, a[i] + mx);
}
int main(){
    n = re, k = re, q = re;
    for (int i = 1; i <= n; i++) a[i] = re, seg[i + n - 1] = i;
    for (int i = n - 1; i; i--) seg[i] = comb(seg[lc], seg[rc]);
    for (int i = 1; i <= n; i++) updLR(i);
    printf("%d\n", tree[1]);
    while(q--){
        int x = re, y = re;
        update(x, 0), a[x] = y, upd(x);
        int lft = get(max(1, x - k + 1), x - 1), rit = get(x, min(n, x + k - 1));
        if (a[x] >= max(a[lft], a[rit])) update(x, a[x] + max(a[lft], a[rit]));
        if (lft) updLR(lft);
        if (rit) updLR(rit);
        printf("%d\n", tree[1]);
    }
}
