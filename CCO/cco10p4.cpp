#include <bits/stdc++.h>
using namespace std;
struct component{
    int c, v;
};
int T, N, B, dp[3001];
vector<component> components[6]; 
int main(){
    cin >> T >> N;
    for (int i = 0, c, v, t; i < N; i++){
        cin >> c >> v >> t;
        components[t].push_back({c, v});
    }
    cin >> B;
    for (int i = 1; i <= T; i++){
        if (components[i].empty()){cout << -1; return 0;}
        for (int j = B; j > 0; j--)
            for (int k = 0; k < components[i].size(); k++)
                if (j >= components[i][k].c) dp[j] = max(dp[j], dp[j - components[i][k].c] + components[i][k].v);
    }
    cout << dp[B];
}
