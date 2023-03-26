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
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 2e3 + 5, C = 1e6;
int H, k, h[MM], maxd, idx, ans = INF; 
vector<int> shifted;
bool check(int x){
	int cnt = 1, cur = 0;
	for (int i = 0; i < H; i++){
		if (shifted[i] > x + cur){
			cnt++;
			cur = shifted[i];
		}
	}
	return cnt <= k;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(H);
	for (int i = 0; i < H; i++) sc(h[i]); 
	sort(h, h + H);
	for (int i = H; i < 2 * H; i++) h[i] = h[i - H] + C;
	sc(k);
	shifted.resize(H);
	for (int i = 0; i < H; i++){
		for (int j = i; j < i + H; j++)
			shifted[j - i] = h[j] - h[i];
		int l = 0, r = C;
		while(l < r){
			int mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		ans = min(ans, l / 2 + l % 2);
	}
	pr(ans);
	return 0;
}

