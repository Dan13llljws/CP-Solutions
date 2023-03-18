#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n + 2);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<int> st = {0};
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++){
        while(st.size() && h[st.back()] >= h[i]) 
            ans = max(ans, 1LL * h[st.back()] * (i - 1 - st[st.size() - 2])), st.pop_back();
        st.push_back(i);
    }
    cout << ans << '\n';
}
