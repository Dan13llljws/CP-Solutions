#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int l = n / 2, r = n - l;
    unordered_map<long long,int> freq;
    for (int msk = 0; msk < (1 << l); msk++){
        long long sum = 0;
        for (int i = 0; i < l; i++)
            if (msk >> i & 1) sum += a[i];
        freq[sum]++;
    }
    long long ans = 0;
    for (int msk = 0; msk < (1 << r); msk++){
        long long sum = 0;
        for (int i = 0; i < r; i++)
            if (msk >> i & 1) sum += a[i + l];
        if (freq.count(x - sum)) ans += freq[x - sum];
    }
    cout << ans << '\n';
}
