#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define lsb(x) ((x) & (-x))
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 3005; 
int N, K, a[MM][MM], bit[MM][MM]; ll ans;
void add(int x, int y, int v){
	for (int i = x; i <= N; i += lsb(i))
		for (int j = y; j <= N; j += lsb(j))
			bit[i][j] = max(bit[i][j], v);
}
int get(int x, int y){
	int ret = 0;
	for (int i = x; i > 0; i -= lsb(i))
		for (int j = y; j > 0; j -= lsb(j))
			ret = max(ret, bit[i][j]);
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, K);
	for (int i = 1; i <= N; i++)
		for (int j = N - i + 1; j <= N; j++)
			sc(a[i][j]);
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= i; j++){
			int x = N - i + j, y = N - j;
			add(x, y, a[x][y]);
			if (y + K - 1 <= N) ans += get(x, y + K - 1);
		}
	}
	pr(ans);
	return 0;
}

