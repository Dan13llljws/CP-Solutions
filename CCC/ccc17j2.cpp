#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int x, y, sum;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    scan(x); scan(y);
    for (int i = 0; i <= y; i++){
        sum += x;
        x *= 10;
    }
    cout << sum;
    return 0;
}