#include <bits/stdc++.h>
using namespace std;
#define su(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    getline (cin, s);
    if (s == "1 2 3 4 5 6 7 8") cout << "ascending";
    else if (s == "8 7 6 5 4 3 2 1") cout << "descending";
    else cout << "mixed";
}