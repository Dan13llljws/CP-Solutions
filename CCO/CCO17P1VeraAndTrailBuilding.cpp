#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
int k, cur;
vector<pii> p;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> k;
    for (int i = 5000; i >= 2; i--){
        int m = i * (i - 1) / 2;
        while(k >= m){
            int a = cur + 1, b = cur + i;
            if (!p.empty()) p.pb(mp(a, cur));
            for (int j = a; j < b; j++)
                p.pb(mp(j, j + 1));
            p.pb(mp(b, a));
            k -= m;
            cur = b;
        }
        if (!k) break;
    }
    cout << cur << ' ' << p.size() << nl;
    for (int i = 0; i < p.size(); i++){
        cout << p[i].first << ' ' << p[i].second << nl;
    }
    return 0;
}