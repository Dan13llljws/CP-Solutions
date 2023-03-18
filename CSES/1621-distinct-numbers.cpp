
#include <bits/stdc++.h>
#define pb push_back
#define fastio cin.tie(0), cin.sync_with_stdio(0), cout.tie(0)
// #define int long long
using namespace std;    
int main(){
    int n, ans = 0;
    const int MM = 2e5 + 5;
    int arr[MM];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i-1])ans++;
    }
    cout << ans;
}
