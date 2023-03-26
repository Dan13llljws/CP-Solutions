#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
const char sp=' ',nl='\n';
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template<typename T>void read(T &s){s=0;char ch=getchar();ll f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-48,ch=getchar();s*=f;}
template<typename T, typename...A>void read(T&f,A&...a){read(f);read(a...);}
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
int c, d, k, t[101], tot;
double dp[200005], totw, ans = 1e9;
pair<int, double> wt[101];
int main(){
	//freopen("C.10.dat", "r", stdin);
	c = re, d = re, k = re; 
	fill(dp, dp + 200005, -1e9); dp[0] = 0;
	for (int i = 1; i <= d; i++) sc(wt[i].f, wt[i].s);
	for (int i = 0; i < k; i++) t[i] = re, totw += wt[t[i]].s, tot += wt[t[i]].f;
	if (tot < c) return 0 * printf("too poor\n");
	for (int i = 0; i < k; i++)
		for (int j = tot; j >= wt[t[i]].f; j--)
			dp[j] = max(dp[j], dp[j - wt[t[i]].f] + wt[t[i]].s);
	sort(wt + 1, wt + d + 1, greater<pair<int, double>>());
	for (int i = c; i <= tot; i++){
		if (dp[i] < 0) continue;
		int tmp = i - c, cur = 1; double tmp2 = 0;
		while(tmp){
			if (tmp >= wt[cur].f){
				tmp -= wt[cur].f;
				tmp2 += wt[cur].s;
			}
			else cur++;
		}
		ans = min(ans, totw - dp[i] + tmp2);
	}
	printf("%.2f\n", ans);
	return 0;
}

