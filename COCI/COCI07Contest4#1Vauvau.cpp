#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define For(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a) For(i, 0, a)
#define Forr(i, a, b) for(int i=a-1; i>=b; i--)
#define FORR(i, a) Forr(i, a, 0);
int a, b, c, d, man[3] , cnt;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> c >> d >> man[0] >> man[1] >> man[2];
    for (int i = 0; i < 3; i++){
        cnt = 0;
        if (man[i] % (a + b) <= a && man[i] % (a + b)) cnt++;
        if (man[i] % (c + d) <= c && man[i] % (c + d)) cnt++;
        if (!cnt) cout << "none" << nl;
        else if (cnt == 1) cout << "one" << nl;
        else cout << "both" << nl;
    }
    return 0;
}