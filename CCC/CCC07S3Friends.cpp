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
int f[10000], n, t1, t2;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        f[a] = b;
    }
    cin >> t1 >> t2;
    while(t1){
        int x = t1, cnt = 0, in = 0;
        while(f[x] != t1){
            if (f[x] == t2) in = 1;
            if (!in) cnt++;
            x = f[x];
        }
        if (!in) cout << "No" << nl;
        else cout << "Yes " << cnt << nl;
        cin >> t1 >> t2;
    }
    return 0;
}