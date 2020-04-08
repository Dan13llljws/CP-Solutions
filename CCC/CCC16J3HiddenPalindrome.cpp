#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
string s; int m;
bool isPalindrome(string s){
    if (s.length() <= 1) return true;
    else if (s[0] == s[s.length() - 1]) return isPalindrome(s.substr(1, s.length() - 2));
    else return false;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        for (int j = i + 1; j < s.length(); j++){
            if (isPalindrome(s.substr(i, j - i + 1))){
                int n = s.substr(i, j - i + 1).length();
                m = max(m, n);
            }
        }
    }
    cout << m;
    return 0;
}