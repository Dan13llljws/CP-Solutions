#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> f(26);
    string ans;
    for (char c : s) f[c - 'A']++;
    auto check = [&](int i) -> int{
        f[i]--;
        int ret = *max_element(f.begin(), f.end());
        f[i]++;
        return 2 * ret;
    };
    if (n + 1 < 2 * *max_element(f.begin(), f.end())){
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 26; j++){
            if (f[j] && (ans.size() && ans.back() != j + 'A' || !ans.size()) && n - i >= check(j)){
                ans.push_back(j + 'A');
                f[j]--;
                break;
            }
        }
    }
    cout << ans << '\n';
}

