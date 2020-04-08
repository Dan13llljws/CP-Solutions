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
typedef pair<string, int> psi;
typedef long long ll;
int n;
psi computer[10001];
bool cmp (psi a, psi b){
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0, r, s, d; i < n; i++){
        cin >> computer[i].first >> r >> s >> d;
        computer[i].second = 2 * r + 3 * s + d;
    }
    sort(computer, computer + n, cmp);
    cout << computer[0].first << nl << computer[1].first;
    return 0;
}