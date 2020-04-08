#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> boss;
    int n;
    cin >>n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x != 0){
            boss.push(x);
        }
        else boss.pop();
    }
    int sum = 0;
    while (!boss.empty()){
        sum += boss.top();
        boss.pop();
    }
    cout << sum <<endl;

    return 0;
}