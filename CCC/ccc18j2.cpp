#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char today[n], yestarday[n];
    int counter = 0;
    for (int i = 0; i < n; i++){
        cin >> today[i];
    }
    for (int i = 0; i < n; i++){
        cin >> yestarday[i];
    }
    for (int i = 0; i < n; i++){
        if (today[i] == yestarday[i] && today[i] == 'C') counter++;
    }
    cout << counter;
    return 0;
}