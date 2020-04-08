#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
string s, ana;
int c[25],d[25];
bool anagram = true;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> ana;
    for (int i = 0; i < s.length(); i++){
        c[s[i] - 'a']++;
        if (ana[i] == '*') d[24]++;
        else d[ana[i] - 'a']++;
    }
    for(int i = 0; i < 24; i++){
        if (d[i] > c[i]) anagram = false;
    }
    if (anagram) cout << 'A';
    else cout << 'N';
    return 0;
}