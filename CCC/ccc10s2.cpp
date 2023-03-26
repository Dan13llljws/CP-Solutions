#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    pair<char, string> code[n];
    string encode, decode;
    for (int i = 0; i < n; i++){
        cin >> code[i].first >> code[i].second;
    }
    cin >> encode;
    while(encode.length() > 0){
        for (int i = 0; i < n; i++){
            int x = code[i].second.length();
            if (encode.substr(0, x) == code[i].second){
                decode += code[i].first;
                encode = encode.substr(x, encode.length() - x);
            }
        }
    }
    cout << decode <<endl;
    return 0;
}