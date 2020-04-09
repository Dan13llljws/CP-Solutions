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
const int MM = 1 << 25;
int n, st; bool vis[MM];
queue<pii> q;
int main(){
	n = re; 
	for (int i = 0; i < n; i++) st |= (re << i);
	q.push({st, 0}); vis[st] = 1;
	while(!q.empty()){
		int mask = q.front().f, d = q.front().s; q.pop();
		if (mask == 0) return 0 * printf("%d", d);
		for (int i = 0; i < n; i++){
			if (!(mask >> i & 1)){
				int new_mask = mask | (1 << i), con = 0;
				for (int j = 0; j < n; j++){
					if (new_mask >> j & 1) con++;
					else {
						if (con >= 4){
							for (int k = j - con; k < j; k++)
								new_mask &= ~(1 << k);
						}
						con = 0;
					}
				}
				if (con >= 4){
					for (int j = n - con; j < n; j++)	
						new_mask &= ~(1 << j);
				}
				if (!vis[new_mask]){
					q.push({new_mask, d + 1});
					vis[new_mask] = 1;
				}
			}
		}
	}
	return 0;
}



