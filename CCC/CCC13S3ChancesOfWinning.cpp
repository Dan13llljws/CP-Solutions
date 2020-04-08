#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int t, g, score[5];
bool vis[5][5];
int rec(int n, int score[]){
    if (n == 0) {
        for (int i = 1; i < 5; i++){
            if (i == t) continue;
            if (score[t] <= score[i]) return 0;
        }
        return 1;
    }
    int ans = 0;
    for (int i = 1; i < 4; i++){
        for (int j = i + 1; j < 5; j++){
            if (!vis[i][j]){
                vis[i][j] = 1;
                score[i] += 3; ans += rec(n - 1, score); score[i] -= 3;
                score[j] += 3; ans +=  rec(n - 1, score); score[j] -= 3;
                score[i]++; score[j]++; ans += rec(n - 1, score); score[i]--; score[j]--;
                vis[i][j] = 0;
                return ans;
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> t >> g;
    for (int i = 0, a, b, x, y; i < g; i++){
        cin >> a >> b >> x >> y;
        if (x > y) score[a] += 3;
        else if (x < y) score[b] += 3;
        else {
            score[a]++; score[b]++;
        }
        vis[a][b] = true;
    }
    cout << rec(6 - g, score) << nl;
    return 0;
}
