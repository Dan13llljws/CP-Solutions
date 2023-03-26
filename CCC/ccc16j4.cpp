#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    int h, m;
    scanf("%d:%d", &h, &m);
    for (int i = 0; i < 12; i++){
        if((h >= 7 && h < 10) || (h >= 15 && h < 19)){
            m += 20;
        }
        else m += 10;
        if (m >= 60){
            h++;
            m -= 60;
        }
        if (h >= 24) h -= 24;
    }
    printf("%02d:%02d", h, m);
    return 0;
}