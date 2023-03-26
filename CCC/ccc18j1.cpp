#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool answer = true;
    if (b != c) answer = false;
    if (a != 8 && a != 9) answer = false;
    if (d != 8 && d != 9) answer = false;
    if(answer) cout << "ignore";
    else cout << "answer";
    return 0;
}