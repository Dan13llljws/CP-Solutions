#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int m, d;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> m >> d;
    if (m < 2) cout << "Before";
    else if (m == 2){
        if (d < 18) cout << "Before";
        else if (d == 18) cout << "Special";
        else cout << "After";
    }
    else cout << "After";
    return 0;
}