#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cout << n << " in Ottawa\n";
    int temp = n - 300;
    if (temp < 0) temp += 2400;
    cout << temp << " in Victoria\n";
    temp = n - 200;
    if (temp < 0) temp += 2400;
    cout << temp << " in Edmonton\n";
    temp = n - 100;
    if (temp < 0) temp += 2400;
    cout << temp << " in Winnipeg\n";
    cout << n << " in Toronto\n";
    temp = n + 100;
    if (temp >= 2400) temp -= 2400;
    cout << temp << " in Halifax\n";
    temp = n + 130;
    if (temp >= 2400) temp -= 2400;
    if (temp % 100 >= 60){
        temp -= 60;
        temp += 100;
    }
    cout << temp << " in St. John's\n";
    return 0;
}