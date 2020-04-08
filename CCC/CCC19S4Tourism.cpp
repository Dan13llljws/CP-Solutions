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
const int MM = 1e6 + 5;
int N, K, a[MM];
ll dp[MM];
pair<ll, ll> q[MM];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, K);
	for (int i = 1; i <= N; i++) sc(a[i]);
	// naive
	for (int i = 1; i <= N; i++){
		
	}
	
	int l = 1, r = 1;
	for (int i = 1; i <= N; i++){
		while(l < r && q[r].s - q[l].s > K) l++;
		dp[i] = 
	}
	return 0;
}


