#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define flood(x) ms(x, 0x3f)
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef pair<int, int> pii;
const int MOD = 1e9 + 7, MM = 1e5;
int n, q, ans, maxn = 1;
priority_queue<pii, vector<pii>, greater<pii>> p;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, q);
    for (int i = 1, x, y; i <= n; i++){
        sc(x, y);
        if (i == q) ans += x;
        else if (x >= y) p.push(make_pair(x, y));
    }
    while(!p.empty()){
        int x = p.top().first, y = p.top().second; p.pop();
        if (ans >= y){
            ans += x - y;
            maxn++;
        }   
    }
    pr(ans, nl, maxn);
    return 0;
}
