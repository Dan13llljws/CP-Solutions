#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int a = 0; a < n; a++){
        string s;
        cin >> s;
        char x = s[0]; int counter = 0;
        for (int i = 0; i < s.length(); i++){
            if (x != s[i]){
                cout << counter << " " << x << " ";
                x = s[i]; counter = 1;
            }
            else counter++;
        }
        cout << counter << " " << x <<endl;
    }
    return 0;
}