#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
int n, k, a[2000], b[1000], maxb, ans;
bool cmp(int a, int b) {return a > b;}
int check(int x){
    int f = 0, tmp = b[f], sum = 0;
    ms(a, 0);
    for (int i = 0; i < 2 * k; i++){
        if (tmp > x){
            a[i] = x; tmp -= x;
        }
        else{
            a[i] = tmp; f++;
            if (f == n) break;
            else tmp = b[f];
        }
    }
    sort(a, a + 2 * k, cmp);
    for (int i = k / 2; i < k; i++) sum += a[i];
    return sum;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("berries.in", "r", stdin); freopen("berries.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> b[i];
        maxb = max(maxb, b[i]);
    }
    sort(b, b + n, cmp);
    if (b[0] == 0) {
        cout << 0;
        return 0;
    }
    if (b[0] == b[k - 1]){
        cout << b[0];
        return 0;
    }
    for (int i = 1; i <= maxb; i++) ans = max(ans, check(i));
    cout << ans;
    return 0;
}
