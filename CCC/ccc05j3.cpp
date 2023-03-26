#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack <char> dir;
    stack <string> street;
    char d; string s;
    cin >> d >> s;
    dir.push(d);
    street.push(s);
    while (s != "SCHOOL"){
        cin >> d >> s;
        dir.push(d);
        street.push(s);
    }
    street.pop();
    while (!street.empty()){
        if(dir.top() == 'R') cout << "Turn LEFT onto ";
        else cout << "Turn RIGHT onto ";
        cout << street.top() << " street." <<endl;
        dir.pop();
        street.pop();
    }
    if(dir.top() == 'R') cout << "Turn LEFT into ";
    else cout << "Turn RIGHT into ";
    cout << "your HOME." <<endl;
    return 0;
}