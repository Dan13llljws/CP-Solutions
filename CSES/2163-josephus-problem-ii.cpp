#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    ordered_set os;
    for (int i = 0; i < n; i++) os.insert(i);
    for (int i = 0, j = 0; i < n; i++){
        int t = os.order_of_key(j);
        int s = *os.find_by_order((t + k) % os.size());
        j = s;
        os.erase(os.find(j));
        cout << j + 1 << ' ';
    }
    cout << '\n';
}

