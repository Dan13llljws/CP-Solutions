#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> x;
int main(){
    for (int i = 1; i < 15; i++){
        if (i % 3 && i % 5) x.push_back(i);
    }
    cin >> n;
    int ans = n / 8 * 15, tmp = n % 8;
    ans += x[tmp - 1];
    if (ans % 15 == 0) ans--;
    cout << ans;
}