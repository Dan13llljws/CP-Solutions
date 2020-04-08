#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll ans = 1e11;
pair<int, int> coord[101];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> coord[i].first >> coord[i].second;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            ll s = max(abs(coord[j].first - coord[i].first), abs(coord[j].second - coord[i].second));
            ans = min(ans, s * s);
        }
    }
    cout << ans;
}
