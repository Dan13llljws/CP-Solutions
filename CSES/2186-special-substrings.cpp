#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    vector<int> rnd(26);
    mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
    long long all = 0;
    for (int i = 0; i < 26; i++) rnd[i] = rng();
    vector<int> f(26);
    string s;
    cin >> s;
    vector<int> f2(s.size() + 1);
    int n = 0;
    for (char c : s){
        f[c - 'a']++;
        if (f[c - 'a'] == 1) n++, all += rnd[c - 'a'];
    }
    fill(f.begin(), f.end(), 0);
    long long ans = 0, hsh = 0;;
    map<long long,int> cnt;
    cnt[0] = 1;
    for (char c : s){
        f[c - 'a']++, f2[f[c - 'a']]++, hsh += rnd[c - 'a'];
        if (f2[f[c - 'a']] == n) hsh -= all;
        ans += cnt[hsh], cnt[hsh]++;
    }
    cout << ans << '\n';

    
}
