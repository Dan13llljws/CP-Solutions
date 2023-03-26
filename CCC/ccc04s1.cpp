#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define sz(x) (int)(x.size())
int n; string s1, s2, s3;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    cin >> n;
    while(n--){
        cin >> s1 >> s2 >> s3;
        if (sz(s1) >= sz(s2)){
            if (s1.substr(0, sz(s2)) == s2){
                cout << "No" << nl; 
                continue;
            }
            else if (s1.substr(sz(s1) - sz(s2), sz(s2)) == s2){
                cout << "No" << nl;
                continue;
            }
        }
        else {
            if (s2.substr(0, sz(s1)) == s1){
                cout << "No" << nl; 
                continue;
            }
            else if (s2.substr(sz(s2) - sz(s1), sz(s1)) == s1){
                cout << "No" << nl;
                continue;
            }
                
        }
        if (sz(s1) >= sz(s3)){
            if (s1.substr(0, sz(s3)) == s3){
                cout << "No" << nl; 
                continue;
            }
            else if (s1.substr(sz(s1) - sz(s3), sz(s3)) == s3){
                cout << "No" << nl;
                continue;
            }
        }
        else {
            if (s3.substr(0, sz(s1)) == s1){
                cout << "No" << nl; 
                continue;
            }
            else if (s3.substr(sz(s3) - sz(s1), sz(s1)) == s1){
                cout << "No" << nl;
                continue;
            }
                
        }
        if (sz(s3) >= sz(s2)){
            if (s3.substr(0, sz(s2)) == s2){
                cout << "No" << nl; 
                continue;
            }
            else if (s1.substr(sz(s3) - sz(s3), sz(s2)) == s2){
                cout << "No" << nl;
                continue;
            }
        }
        else {
            if (s2.substr(0, sz(s3)) == s3){
                cout << "No" << nl; 
                continue;
            }
            else if (s2.substr(sz(s2) - sz(s2), sz(s3)) == s3){
                cout << "No" << nl;
                continue;
            }
                
        }
        cout << "Yes" << nl;
    }
    return 0;
}
