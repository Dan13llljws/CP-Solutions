#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin >> s;
    if (next_permutation(s.begin(), s.end())) cout << s;
    else cout << 0;
    return 0;
}