#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
pii p[1001];
int n, x, ans1, ans2, ans3;
bool cmp(pii a, pii b){
    if (a.second == b.second) return a.first > b.first ;
    else return a.second > b.second;
}
bool cmp2(pii a, pii b){
    if (a.second == b.second) return a.first < b.first ;
    else return a.second > b.second;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i < 1001; i++){
        p[i].first = i;
    }
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        p[x].second++;
    }
    sort (p, p + 1001, cmp);
    if (p[0].second == p[1].second){
        ans1 = p[0].first;
        sort(p, p + 1001, cmp2);
        ans2 = p[0].first;
        cout << ans1 - ans2;
    }
    else{
        ans1 = p[0].first;
        ans2 = p[1].first;
        sort(p, p + 1001, cmp2);
        ans3 = p[1].first;
        cout << max(abs(ans1 - ans2), abs(ans1 - ans3));
    }
    return 0;
}