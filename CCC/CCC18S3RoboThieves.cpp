#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int , pii> piii;
typedef pair<ll, pll> plll;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, dist[101][101]; bool vis[101][101];
char grid[101][101];
pii st; vector<pii> cams;
priority_queue<piii, vector<piii>, greater<piii>> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ms(dist, INF);
    sc(n, m); 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            sc(grid[i][j]);
            if (grid[i][j] == 'S') st.f = i, st.s = j;
            if (grid[i][j] == 'C') cams.pb(mp(i, j));
        }
    }
    for (auto p : cams){
        for (int i = 0; i < 4; i++){
            int nr = p.f, nc = p.s;
            while(grid[nr][nc] != 'W'){
                if (grid[nr][nc] == '.' || grid[nr][nc] == 'S') vis[nr][nc] = 1;
                nr += dir[i][0], nc += dir[i][1]; 
            }
        }
    }
    if (!vis[st.f][st.s]) q.push(mp(0, mp(st.f, st.s))); 
    dist[st.f][st.s] = 0;
    while(!q.empty()){
        int d = q.top().f, x = q.top().s.f, y = q.top().s.s; q.pop();
        if (d > dist[x][y]) continue;
        if (grid[x][y] == 'L' && dist[x][y - 1] > d && !vis[x][y - 1] && grid[x][y - 1] != 'W'){
            q.push(mp(d, mp(x, y - 1)));
            dist[x][y - 1] = d;
        }
        else if (grid[x][y] == 'R' && dist[x][y + 1] > d && !vis[x][y + 1]  && grid[x][y + 1] != 'W'){
            q.push(mp(d, mp(x, y + 1)));
            dist[x][y + 1] = d;
        }
        else if (grid[x][y] == 'U' && dist[x - 1][y] > d && !vis[x - 1][y]  && grid[x - 1][y] != 'W'){
            q.push(mp(d, mp(x - 1, y)));
            dist[x - 1][y] = d;
        }
        else if (grid[x][y] == 'D' && dist[x + 1][y] > d && !vis[x + 1][y]  && grid[x + 1][y] != 'W'){
            q.push(mp(d, mp(x + 1, y)));
            dist[x + 1][y] = d;
        }
        else if (grid[x][y] == '.' || grid[x][y] == 'S'){
            for (int i = 0; i < 4; i++){
                int nr = x + dir[i][0], nc = y + dir[i][1];
                if (grid[nr][nc] != 'W' && !vis[nr][nc] && dist[nr][nc] > d + 1) {
                    q.push(mp(d + 1, mp(nr, nc)));
                    dist[nr][nc] = d + 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '.') pr(dist[i][j] == INF ? -1 : dist[i][j], nl);
        }
    }
    return 0;
}