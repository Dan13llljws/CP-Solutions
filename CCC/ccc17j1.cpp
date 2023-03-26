#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int x, y;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> x >> y;
    
    if (x > 0){
        if (y > 0) cout << 1;
        else cout << 4;
    }
    else {
        if (y > 0) cout << 2;
        else cout << 3;
    }
    return 0;
}