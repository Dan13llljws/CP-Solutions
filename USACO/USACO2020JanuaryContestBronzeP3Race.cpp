#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
typedef long long ll;
int k, n, x;
ll check(ll y){
    if (y <= x) return (1 + y) * y / 2;
    return (1 + y) * y / 2 + (x + y - 1) * (y - x) / 2;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("race.in", "r", stdin); freopen("race.out", "w", stdout);
    cin >> k >> n;
    while(n--){
        cin >> x;
        ll l = 1, r = k, mid, ans;
        while(l <= r){
            mid = l + (r - l) / 2;
            if (check(mid) <= k){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ll time;
        if (check(ans) == k){
            cout << ans << nl;
            continue;
        }
        if (ans <= x) time = ans;
        else time = ans + ans - x;
        time += (k - check(ans) - 1) / ans + 1;
        cout << time << nl;
    }
    return 0;
}
