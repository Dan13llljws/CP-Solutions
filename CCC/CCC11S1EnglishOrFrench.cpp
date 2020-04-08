#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
string s;
map<char, int> c;
int n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        string a;
        getline(cin, a);
        s += a;
    }
    for (int i = 0; i < s.length(); i++){
        c[s[i]]++;
    }
    if (c['s'] + c['S'] >= c['t'] + c['T']) cout << "French";
    else cout << "English";
    return 0;
}