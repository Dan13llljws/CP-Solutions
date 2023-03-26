#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
string s;
int c[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int key[26] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8};
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    while (s != "halt"){
        int counter = c[s[0] - 'a'];
        for (int i = 1; i < s.length(); i++){
            counter += c[s[i] - 'a'];
            if (key[s[i] - 'a'] == key[s[i - 1] - 'a']) counter += 2;
        }
        cout << counter << "\n";
        cin >> s;
    }
    return 0;
}