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

bool g[51][51];
char cmd;

void add(int a, int b){
    g[a][b] = 1; g[b][a] = 1;
}
void dlt(int a, int b){
    g[a][b] = 0; g[b][a] = 0;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    add(1, 6); add(2, 6); add(3, 6); add(4, 6); add(5, 6);
    add(7, 6); add(3, 5); add(7, 8); add(8, 9); add(9, 10);
    add(10, 11); add(11, 12); add(9, 12); add(3, 15); add(3, 4);
    add(4, 5); add(15, 13); add(12, 13); add(13, 14); add(16, 17);
    add(17, 18); add(18, 16);

    cin >> cmd;
    while (cmd != 'q'){
        if (cmd == 'i'){
            int x, y; cin >> x >> y;
            add(x, y);
        }
        else if (cmd == 'd'){
            int x, y; cin >> x >> y;
            dlt(x, y);
        }
        else if (cmd == 'n'){
            int cnt = 0, x; cin >> x;
            for (int i = 1; i <= 50; i++){
                if (g[x][i]) cnt++;
            }
            cout << cnt << nl;
        }
        else if (cmd == 'f'){
            vector<int> q; bool visited[50];
            memset(visited, 0, sizeof(visited));
            int cnt = 0, x; cin >> x;
            visited[x] = 1;
            for (int i = 1; i <= 50; i++){
                if (g[x][i]){
                    q.pb(i);
                    visited[i] = 1;
                }
            }
            for (int y : q){
                for (int i = 1; i <= 50; i++){
                    if (g[y][i] && !visited[i]){
                        cnt++;
                        visited[i] = 1;
                    }
                }
            }
            cout << cnt << nl;
        }
        else {
            queue<int> q;
            int x, y; cin >> x >> y;
            int dist[51]; bool visited[51];
            memset(visited, 0, sizeof(visited));
            visited[x] = 1;
            dist[x] = 0;
            q.push(x);
            while(!q.empty()){
                int z = q.front();
                q.pop();
                for (int i = 1; i <= 50; i++){
                    if (g[z][i] && !visited[i]){
                        q.push(i);
                        visited[i] = 1;
                        dist[i] = dist[z] + 1;
                    }
                }
            }
            if (visited[y]) cout << dist[y] << nl;
            else cout << "Not connected" << nl;
        }
        cin >> cmd;
    }
    return 0;
}