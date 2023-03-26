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
int n, m, cnt; bool vis[1001][1001];
char grid[1001][1001];
queue<pii> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); // bad solve couldve make it smarter
    cin >> n >> m;
    FOR(i, n){
        FOR(j, m){
            cin >> grid[i][j];
        }
    }
    FOR(i, n){
        FOR(j, m){
            if (!vis[i][j]){
                cnt++;
                q.push(mp(i, j)); vis[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().f, y = q.front().s; q.pop();
                    if (grid[x][y] == 'N' && !vis[x - 1][y]){
                        vis[x - 1][y] = 1;
                        q.push(mp(x - 1, y));
                    }
                    if (grid[x][y] == 'S' && !vis[x + 1][y]){
                        vis[x + 1][y] = 1;
                        q.push(mp(x + 1, y));
                    }
                    if (grid[x][y] == 'W' && !vis[x][y - 1]){
                        vis[x][y - 1] = 1;
                        q.push(mp(x, y - 1));
                    }
                    if (grid[x][y] == 'E' && !vis[x][y + 1]){
                        vis[x][y + 1] = 1;
                        q.push(mp(x, y + 1));
                    }
                    if (x - 1 >= 0 && grid[x - 1][y] == 'S' && !vis[x - 1][y]){
                        vis[x - 1][y] = 1;
                        q.push(mp(x - 1, y));
                    }
                    if (x + 1 < n && grid[x + 1][y] == 'N' && !vis[x + 1][y]){
                        vis[x + 1][y] = 1;
                        q.push(mp(x + 1, y));
                    }
                    if (y + 1 < m && grid[x][y + 1] == 'W' && !vis[x][y + 1]){
                        vis[x][y + 1] = 1;
                        q.push(mp(x, y + 1));
                    }
                    if (y - 1 >= 0 && grid[x][y - 1] == 'E' && !vis[x][y - 1]){
                        vis[x][y - 1] = 1;
                        q.push(mp(x, y - 1));
                    }
                }
            }
        }
    }
    cout << cnt << nl;
    return 0;
}