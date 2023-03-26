#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define f first
#define s second
typedef pair<int, int> pii;
int N; double ans;
pii p[100010];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sc(N);
    for (int i = 0; i < N; i++) sc(p[i].f, p[i].s);
    sort(p, p + N);
    for (int i = 1; i <= N; i++){
        double tmp = (double)abs(p[i].s - p[i - 1].s) / (p[i].f - p[i - 1].f);
        ans = max(ans, tmp);
    }
    printf("%.5f", ans);
    return 0;
}
