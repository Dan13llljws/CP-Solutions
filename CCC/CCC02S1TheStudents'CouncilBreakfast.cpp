#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
int a, b, c, d, tot, cnt, m = INF;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(a, b, c, d, tot);
    for (int i = 0; i <= tot / a; i++)
        for (int j = 0; j <= tot / b; j++)
            for (int k = 0; k <= tot / c; k++)
                for (int l = 0; l <= tot / d; l++)
                    if (i * a + j * b + k * c + l * d == tot){
                        pr("# of PINK is ", i, " # of GREEN is ", j, " # of RED is ", k, " # of ORANGE is ", l, nl);
                        cnt++; m = min(m, i + j + k + l);
                    }
    pr("Total combinations is ", cnt, ".\n");
    pr("Minimum number of tickets to print is ", m, ".\n");
    return 0;
}