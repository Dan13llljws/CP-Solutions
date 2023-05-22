#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, n;
    cin >> x >> n;
    priority_queue<int> q;
    long long ans = 0;
    while(n--){
        int y;
        cin >> y;
        q.push(-y);
    }
    while(q.size() > 1){
        int a = -q.top(); q.pop();
        int b = -q.top(); q.pop();
        ans += a + b;
        q.push(-a - b);
    }
    cout << ans << '\n';
}
