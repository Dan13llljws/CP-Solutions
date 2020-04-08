#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = abs(a - c) + abs(b - d);
    if (k >= x && (k - x) % 2 == 0) cout << "Y";
    else cout << "N";
    return 0;
}