#include <bits/stdc++.h>
using namespace std;
bool isMonkey (string s){
    int x = s.find("ANA"), y = s.find("BAS");
    if (s == "A") return true;
    if (x == 0){
        s = "A" + s.substr(3, s.length() - x - 3);
        return isMonkey(s);
    }
    else if (x > 0){
        s = s.substr(0, x) + "A" + s.substr(x + 3, s.length() - x - 3);
        return isMonkey(s);
    }
    else if (y == 0){
        s = "A" + s.substr(3, s.length() - y - 3);
        return isMonkey(s);
    }
    else if (y > 0){
        s = s.substr(0, y) + "A" + s.substr(y + 3, s.length() - y - 3);
        return isMonkey(s);
    }
    return false;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    while(s != "X"){
        if (isMonkey(s)) cout << "YES" <<endl;
        else cout << "NO" << endl;
        cin >> s;
    }
    return 0;
}