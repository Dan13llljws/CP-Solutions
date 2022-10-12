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
#define pb push_back
int n, m, k, a, b;
bool A[2001][2001];
vector<int> adj[2001];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    FOR(i, k){
        cin >> a >> b;
        for(int u : adj[a]){
            if (A[u][b]){
                cout << "NO";
                return 0;
            }
            else {
                A[u][b] = 1; A[b][u] = 1;
            }
        }
        adj[a].pb(b);
    }
    cout << "YES";
    return 0;
}