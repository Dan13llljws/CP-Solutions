#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int n, m, x[10], y[10], counter;
bool grid[100][100];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; i++){
        for (int j = 1; j < n + 1; j++){
            grid[j][y[i]] = true;
            grid[x[i]][j] = true;
        }
        for (int j = x[i], k = y[i]; j > 0 && k > 0; j--, k--){
            grid[j][k] = true;
        }
        for (int j = x[i], k = y[i]; j > 0 && k < n + 1; j--, k++){
            grid[j][k] = true;
        }
        for (int j = x[i], k = y[i]; j < n + 1 && k > 0; j++, k--){
            grid[j][k] = true;
        }
        for (int j = x[i], k = y[i]; j < n + 1 && k < n + 1; j++, k++){
            grid[j][k] = true;
        }
    }
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            if (!grid[i][j]) counter++;
        }
    }
    cout << counter;
    return 0;
}