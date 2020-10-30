#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
int n, a[1005], b[1005]; bool vis[1005][1005], flag;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("photo.in", "r", stdin); freopen("photo.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    for (int i = 1; i < b[0]; i++){
        flag = 1; vis[i][i] = 1; a[0] = i;
        for (int j = 1; j < n; j++){
            if (a[j - 1] >= b[j - 1]){
                flag = 0; break;
            }
            a[j] = b[j - 1] - a[j - 1];
            if (vis[i][a[j]]){
                flag = false; break;
            }
            vis[i][a[j]] = 1;
        }
        if (flag){
            for (int i = 0; i < n; i++){
                cout << a[i];
                if (i == n - 1) cout << nl;
                else cout << ' ';
            }
            return 0;
        }
    }
    return 0;
}
