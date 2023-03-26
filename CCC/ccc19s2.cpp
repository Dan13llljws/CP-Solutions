#include <bits/stdc++.h>
using namespace std;
bool primes[2000001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i * i < 2000001; i++){
        if (!primes[i]){
            for (int j = i * i; j < 2000001; j += i)
                primes[j] = true;
        }
    }
    int n;
    cin >> n;
    for (int cases = 0; cases < n; cases++){
        int x;
        cin >> x;
        int y;
        for (int i = 2; i <= x; i++){
            int diff = x - i;
            if (!primes[i] && !primes[x + diff]){
                cout << i << " " << x + diff <<endl;
                break;
            }
        }
    }
    return 0;
}