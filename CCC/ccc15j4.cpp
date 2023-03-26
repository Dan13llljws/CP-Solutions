#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
pair<bool, int> f[101];
int n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        char c; int t;
        cin >> c >> t;
        if (c == 'R'){
            f[t].first = true;
            for (int j = 1; j < 101; j++){
                if (f[j].first) f[j].second++;
            }
        }
        else if (c == 'S'){
            f[t].first = false;
            for (int j = 1; j < 101; j++){
                if (f[j].first) f[j].second++;
            }
        }
        else if (c == 'W'){
            for (int j = 1; j < 101; j++){
                if (f[j].first) f[j].second += t - 1;
            }
        }
    }
    for (int i = 1; i < 101; i++){
        if (f[i].second > 0 && !f[i].first) cout << i << " " << f[i].second << "\n";
        else if (f[i].second > 0 && f[i].first) cout << i << " " << -1 << '\n';
    }
    return 0;
}