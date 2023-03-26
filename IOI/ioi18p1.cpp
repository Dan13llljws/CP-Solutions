#include <bits/stdc++.h>
using namespace std;
string guess_sequence(int N){
    string s, ans;
    if (press("AB")) ans = press("A") ? "A" : "B";
    else ans = press("X") ? "X" : "Y";
    if (N == 1) return ans;
    for (char c : "ABXY")
        if (c != ans[0]) s.push_back(c);
    for (int i = 1; i < N - 1; i++){
        string ns = ans;
        ns.push_back(s[0]);
        ns += ans, ns.push_back(s[1]), ns.push_back(s[0]);
        ns += ans, ns.push_back(s[1]), ns.push_back(s[1]);
        ns += ans, ns.push_back(s[1]), ns.push_back(s[2]);
        int res = press(ns);
        if (res == i) ans.push_back(s[2]);
        else if (res == i + 1) ans.push_back(s[0]);
        else ans.push_back(s[1]);
    } ans.push_back(s[0]);
    for (int i = 1; i < 3; i++)
        if (press(ans) == N) break;
        else ans.pop_back(), ans.push_back(s[i]);
    return ans;
}
int main(){}
