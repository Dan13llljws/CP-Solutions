#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define For(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a) For(i, 0, a)
#define Forr(i, a, b) for(int i=a-1; i>=b; i--)
#define FORR(i, a) Forr(i, a, 0)
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
int dir[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int T, r, c, pr, pc, kr, kc, dist[101][101], stalemove, winmove; bool stalemate, win;
    cin >> T;
    while(T--){
        cin >> r >> c >> pr >> pc >> kr >> kc;
        win = false; stalemate = false;
        queue<pii> q;
        ms(dist, -1); dist[kr][kc] = 0;
        q.push(mp(kr, kc));
        while(!q.empty()){
            int x = q.front().f, y = q.front().s; q.pop();
            FOR(i, 8){
                int nr = x + dir[i][0], nc = y + dir[i][1];
                if (nr > r || nr <= 0 || nc > c || nc <= 0 || dist[nr][nc] != -1) continue;
                dist[nr][nc] = dist[x][y] + 1;
                q.push(mp(nr, nc));
            }
        }
        int tmp = pr;
        For(i, 0, r - tmp){   //this loop messed me up cuz i started at 1 instead of 1 and i debugged for 5hrs
            if (pr != r && dist[pr][pc] <= i && dist[pr][pc] != -1 && (i - dist[pr][pc]) % 2 == 0){
                win = 1;
                winmove = i;
                break;
            }
            else if (dist[pr + 1][pc] <= i && dist[pr + 1][pc] != -1 && (i - dist[pr + 1][pc]) % 2 == 0 && !stalemate){
                stalemate = 1;
                stalemove = i;
            }
            pr++;
        }
        if (win) cout << "Win in " << winmove <<" knight move(s)." << nl;
        else if (stalemate) cout << "Stalemate in " << stalemove <<" knight move(s)." << nl;
        else cout << "Loss in " << r - tmp - 1 << " knight move(s)." << nl;
    }
    return 0;
}