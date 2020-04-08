#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define For(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a) For(i, 0, a)
#define Forr(i, a, b) for(int i=a-1; i>=b; i--)
#define FORR(i, a) Forr(i, a, 0);
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<pll, pll> plll;
int N, ans = INF;
pii ing[11];
void minDiff(int n, int x, int y, int used){
    if (!n){
        if (!used) return;
        ans = min(ans, abs(x - y));
        return;
    }
    int s = ing[n - 1].f, b = ing[n - 1].s;
    minDiff(n - 1, x * s, y + b, used + 1);
    minDiff(n - 1, x, y, used);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    FOR(i, N){
        cin >> ing[i].f >> ing[i].s;
    }
    minDiff(N, 1, 0, 0);
    cout << ans << nl;
    return 0;
}