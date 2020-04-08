#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string code;
    cin >> code;
    for (int i = 0; i < code.length(); i++){
        int p = i + 1;
        int s = 3 * p + k;
        code[i] -= s;
        if (code[i] < 'A') code[i] += 26;
    }
    cout << code <<endl;
    return 0;
}