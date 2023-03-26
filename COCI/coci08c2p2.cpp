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
int n, k, p[1001];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 2; i <= n; i++){
        if (!p[i]){
            for (int j = i; j <= n; j += i){
                if (!p[j]) k--;
                p[j] = 1;
                if (k == 0){
                    cout << j << nl;
                    return 0;
                }
            }
        }
    }
    return 0;
}