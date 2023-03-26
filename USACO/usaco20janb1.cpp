#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define sz(x) (int)(x.size())
int n, m, cur;
string in;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("word.in", "r", stdin); freopen("word.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> in;
        if (cur + sz(in) <= m){
            if (cur) cout << ' ';
            cout << in;
            cur += sz(in);
        }
        else{
            cout << nl << in;
            cur = sz(in);
        }
    }
    return 0;
}
