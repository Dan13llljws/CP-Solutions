#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
int n, a[105], g;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n);
	for (int i = 1; i <= n; i++) sc(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = n; i > 1; i--) a[i] -= a[i - 1];
	g = a[2];
	for (int i = 3; i <= n; i++) g = gcd(g, a[i]);
	for (int i = 2; i * i <= g; i++){
	    int r1 = i, r2 = g / i;
	    if (g % r1 == 0){
	        printf("%d ", r1);
	        if (r2 != r1) printf("%d ", r2);
	    }
	}
	printf("%d\n", g);
	return 0;
}
