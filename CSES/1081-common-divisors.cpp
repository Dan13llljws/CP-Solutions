#include <bits/stdc++.h>
using namespace std;
int cnt[1000005];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1000000; i > 0; i--){
        int x = 0;
        for (int j = i; j <= 1e6; j += i)
            x += cnt[j];
        if (x > 1){
            cout << i << '\n';
            return 0;
        }
    }
}
