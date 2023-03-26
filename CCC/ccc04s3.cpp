#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<ll, ll> pll;
string in[11][10], line;
int vis[11][10], out[11][10];
void solve(int x, int y){
    if (vis[x][y]) {
        out[x][y] = -1;
        return;
    }
    vis[x][y] = 1;
    int ans = 0, r, c;
    for (int i = 0; i < sz(in[x][y]); i += 3){
        r = in[x][y][i] - 'A' + 1; c = in[x][y][i + 1] - '0';
        if (out[r][c] == -1){
            out[x][y] = -1;
            return;
        }
        if (out[r][c] != INF) ans += out[r][c];
        else {
            solve(r, c);
            if (out[r][c] == -1) {
                out[x][y] = -1;
                return;
            }
            else ans += out[r][c];
        }
    }
    out[x][y] = ans;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    ms(out, INF);
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 10; j++){
            cin >> in[i][j];
            if (in[i][j][0] >= '0' && in[i][j][0] <= '9') out[i][j] = stoi(in[i][j]);
        }
    }
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 10; j++){
            ms(vis, 0);
            if (out[i][j] == INF) solve(i, j);
            if (out[i][j] != -1) cout << out[i][j] << ' ';
            else cout << "* ";
        }
        cout << nl;
    }
    return 0;
}