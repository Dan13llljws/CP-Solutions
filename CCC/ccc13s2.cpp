#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
int maxWeight, nCar, car[100000], maxCar, bridgeWeight;
int main()
{   cin.sync_with_stdio(0); cin.tie(0);
    cin >> maxWeight >> nCar;
    bool crack = false;
    for (int i = 0; i < nCar; i++){
        cin >> car[i];
        bridgeWeight += car[i];
        if (i > 3) bridgeWeight -= car[i - 4];
        if (bridgeWeight > maxWeight){
            cout << maxCar << nl;
            return 0;
        }
        maxCar++;
    }
    cout << maxCar << nl;
    return 0;
}