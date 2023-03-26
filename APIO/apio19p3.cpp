#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
#define fi first
#define se second
const int mod = 1e9 + 7, MM = 3e5 + 5;
struct Q{pi p; int tl, tr;}; 
int n, q, on[MM], ans[MM]; char s[MM]; ll bit[2][MM]; set<pair<pi,int>> st; vector<Q> qq;
void upd(int i, int x, ll v){
    for (; x <= q; x += x & -x) bit[i][x] += v;
}
void add(int l, int r, ll x){
    upd(0, l, x), upd(0, r + 1, -x), upd(1, l, x * (l - 1)), upd(1, r + 1, -x * r);
}
ll get(int i, int x){
    ll ret = 0;
    for (; x; x -= x & -x) ret += bit[i][x];
    return ret;
}
ll sum(int r){
    return get(0, r) * r - get(1, r);
}
void cdq(int l, int r, vector<Q>& qu){
    if (l > r || !qu.size()) return;
    int mid = (l + r) >> 1; vector<Q> lft, rit; 
    for (auto u : qu){
        if (u.tr == -1){
            if (u.p.se <= mid){
                ans[u.tl] += sum(u.tl);
                if (u.p.se != mid) lft.push_back(u);
            } else rit.push_back(u);
        } else {
            if(u.p.se >= mid){
                add(u.tl, u.tr, 1);
                if (u.p.se != mid) rit.push_back(u);
            } else lft.push_back(u);
        }
    }
    for (auto u : qu)
        if (u.tr != -1 && u.p.se >= mid) add(u.tl, u.tr, -1);
    cdq(l, mid - 1, lft), cdq(mid + 1, r, rit);
}
void add(int i, int t){
    auto it = st.lower_bound(make_pair(make_pair(i, 0), 0)); 
    auto it1 = it; it1--;
    if (it1->fi.se == i - 1 && it->fi.fi == i + 1){
        qq.push_back({it1->fi, it1->se, t}), qq.push_back({it->fi, it->se, t});
        st.insert({{it1->fi.fi, it->fi.se}, t + 1}), st.erase(it1), st.erase(it);
    } else if (it1->fi.se == i - 1)
        qq.push_back({it1->fi, it1->se, t}), st.insert({{it1->fi.fi, i}, t + 1}), st.erase(it1);
    else if (it->fi.fi == i + 1)
        qq.push_back({it->fi, it->se, t}), st.insert({{i, it->fi.se}, t + 1}), st.erase(it);
    else st.insert({{i, i}, t + 1});
}
void rem(int i, int t){
    auto it = st.upper_bound(make_pair(make_pair(i, 1e9), 1e9)); it--;
    if (it->fi.fi == i && it->fi.se == i) qq.push_back({it->fi, it->se, t}), st.erase(it);
    else if (it->fi.fi == i)
        qq.push_back({it->fi, it->se, t}), st.insert({{i + 1, it->fi.se}, t + 1}), st.erase(it);
    else if (it->fi.se == i) 
        qq.push_back({it->fi, it->se, t}), st.insert({{it->fi.fi, i - 1}, t + 1}), st.erase(it);
    else{
        qq.push_back({it->fi, it->se, t});
        st.insert({{it->fi.fi, i - 1}, t + 1}), st.insert({{i + 1, it->fi.se}, t + 1}), st.erase(it);
    }
}
int main(){
    scanf("%d%d %s", &n, &q, s + 1); s[n + 1] = '0';
    st.insert({{-1, -1}, 0}), st.insert({{1e9, 1e9}, 0});
    for (int i = 1, lst = 0; i <= n + 1; i++){
        if (s[i] == '0' && lst) st.insert({{lst, i - 1}, 1}), lst = 0;
        else if (s[i] == '1'){
            on[i] = 1;
            if (!lst) lst = i;
        }
    } char cmd[10];
    for (int i = 1; i <= q; i++){
        scanf("%s", cmd); int a, b;
        if (cmd[0] == 't')
            scanf("%d", &a), on[a] ? rem(a, i) : add(a, i), on[a] ^= 1;
        else scanf("%d%d", &a, &b), qq.push_back({{a, b - 1}, i, -1});
    }
    for (auto u : st) 
        if (u.fi.fi > 0 && u.fi.se <= n) qq.push_back({u.fi, u.se, q});
    sort(qq.begin(), qq.end(), [](Q a, Q b){return a.p.fi == b.p.fi ? a.tr > b.tr : a.p.fi < b.p.fi;});
    cdq(1, n, qq); sort(qq.begin(), qq.end(), [](Q a, Q b){return a.tl < b.tl;});
    for (auto u : qq)
        if (u.tr == -1) printf("%d\n", ans[u.tl]);
}
