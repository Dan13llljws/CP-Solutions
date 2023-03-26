#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
string a, b;
char c;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> a >> c >> b;
    if (c == '+'){
        if (a == b) cout << 2 << a.substr(1, a.length() - 1);
        else if (a.length() > b.length()) cout << a.substr(0, a.length() - b.length()) + b;
        else cout << b.substr(0, b.length() - a.length()) + a;
    }  
    else cout << a + b.substr(1, b.length() - 1);
    return 0;
}