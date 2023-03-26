#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define lb lower_bound
#define ub upper_bound
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
int L;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> L;
    while(L--){
        int n; cin >> n;
        int old = n * 10, layer = 0, maxLayer = 0;
        vector<string> depth;
        for (int i = 0; i < n; i++){
            string name; cin >> name;
            depth.pb(name);
        }
        map<string, int> dict;
        dict[depth[n - 1]] = 1;
        for (int i = 0; i < n; i++){
            if (!dict.count(depth[i])) layer++;
            else layer--;
            dict[depth[i]] = 1;
            maxLayer = max(maxLayer, layer);
        }
        cout << old - maxLayer * 20 << nl;
    }
    return 0;
}