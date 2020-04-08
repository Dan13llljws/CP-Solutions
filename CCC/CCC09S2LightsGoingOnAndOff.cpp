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
int n, l, lights[31][10], ans = 1, st[31][10];
vector<string> oc;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < l; j++){
            cin >> lights[i][j];
        }
    }
    for (int i = 0; i < l; i++){
        for (int j = n - 1; j > 0; j--){
            int x = lights[j - 1][i];
            for (int k = j; k < n; k++){
                int y = lights[k][i];
                if (y != x) x = 1;
                else x = 0;
            }
            st[j][i] = x;
        }
    }
    string tmp;
    for (int i = 0; i < l; i++) tmp += lights[n - 1][i] + '0';
    oc.pb(tmp);
    for (int i = 1; i < n; i++){
        string str;
        for (int j = 0; j < l; j++){
            str += st[i][j] + '0';
        }
        oc.pb(str);
    }
    sort(oc.begin(), oc.end());
    for (int i = 1; i < oc.size(); i++){
        if (oc[i] != oc[i - 1]) ans++;
    }
    cout << ans << nl;
    return 0;
}