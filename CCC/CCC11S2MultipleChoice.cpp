#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int n, counter;
char t[10000], s[10000];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t[i];
    }
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    for (int i = 0; i < n; i++){
        if (t[i] == s[i]) counter++;
    }
    cout << counter;
    return 0;
}