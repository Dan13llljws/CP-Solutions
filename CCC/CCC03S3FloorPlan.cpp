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
int f, R, C, flr, maxroom;
char grid[26][26]; int vis[26][26];
queue<pii> q;
vector<int> roomsize;
int dfs(int r, int c){
    if (r >= R || r < 0 || c >= C || c < 0 || grid[r][c] == 'I') return 0;
    else {
        grid[r][c] = 'I';
        return 1 + dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1);
    }
}
int main(){
    //cin.sync_with_stdio(0); cin.tie(0);
    cin >> f >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (grid[i][j] == '.') roomsize.pb(dfs(i, j));
        }
    }
    sort(roomsize.begin(), roomsize.end());
    for (int i = roomsize.size() - 1; i >= 0; i--){
        if (f - roomsize[i] >= 0){
            maxroom++;
            f -= roomsize[i];
        }
        else break;
    }
    cout << maxroom << (maxroom == 1 ? " room, " : " rooms, ") << f << " square metre(s) left over";
    return 0;
}