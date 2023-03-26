#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
string sub[26] = {"a", "bac", "cad", "def", "e", "feg", "geh", "hij", "i",
                "jik", "kil", "lim", "mon", "nop", "o", "poq", "qos", "ros",
                 "sut", "tuv", "u", "vuw", "wux", "xuy", "yuz", "zuz"};
string s, ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        ans += sub[s[i] - 'a'];
    }
    cout << ans;
    return 0;
}