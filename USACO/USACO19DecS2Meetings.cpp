#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
typedef long long ll;
struct cow{int w, pos, dir;} cows[50010];
int N, L, cnt, sum, ti; ll ans;
deque<int> l, r, w;
bool cmp(cow a, cow b){return a.pos < b.pos;}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N, L);
    for (int i = 0; i < N; i++){
        sc(cows[i].w, cows[i].pos, cows[i].dir);
        sum += cows[i].w;
    }
    sort(cows, cows + N, cmp);
    for (int i = 0; i < N; i++){
        cow c = cows[i];
        if (c.dir < 0) l.push_back(c.pos);
        else r.push_back(c.pos);
        w.push_back(c.w);
    }
    while(cnt * 2 < sum){
        int tleft = INF, tright = INF;
        if (!l.empty()) tleft = l.front();
        if (!r.empty()) tright = L - r.back();
        if (tleft < tright){
            cnt += w.front(); ti = tleft;
            if (!r.empty()) ans += upper_bound(af(r), l.front()) - r.begin();
            w.pop_front(); l.pop_front();
        }
        else {
            cnt += w.back(); ti = tright;
            if (!l.empty()) ans += sz(l) - (upper_bound(af(l), r.back()) - l.begin());
            w.pop_back(); r.pop_back();
        }
    }
    for (int t : l){
        ans += upper_bound(af(r), t) - upper_bound(af(r), t - 2 * ti);
    }
    pr(ans);
    return 0;
}
