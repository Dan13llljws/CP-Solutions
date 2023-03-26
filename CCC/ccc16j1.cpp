#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int w, l;
char a;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 6; i++){
        cin >> a;
        if (a == 'W') w++;
        else l++;
    }
    if (w >= 5) cout << 1;
    else if (w >= 3) cout << 2;
    else if (w >= 1) cout << 3;
    else cout << -1;
    return 0;
}