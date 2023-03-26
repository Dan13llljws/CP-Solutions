#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define pb push_back
#define endl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
int p, dist[10001], pCount = 1, ans = INT_MAX;
vector<int> book[10001];
bool visit[10001];
queue<int> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> p;
    for (int i = 1, m; i < p + 1; i++){
        cin >> m;
        for (int j = 0, a; j < m; j++){
            cin >> a;
            book[i].pb(a);
        }
    }
    dist[1] = 1;
    visit[1] = 1;
    q.push(1);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for (int i = 0; i < book[c].size(); i++){
            if(!visit[book[c][i]]){
                visit[book[c][i]] = 1;
                q.push(book[c][i]);
                dist[book[c][i]] = dist[c] + 1;
                pCount++;
            }
        }
    }
    cout << (pCount == p ? 'Y' : 'N') <<endl;
    for (int i = 1; i < p + 1; i++){
        if (book[i].size() == 0 && dist[i] != 0) ans = min(dist[i], ans);
    }
    cout << ans <<endl;
    return 0;
}