#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template<typename T>void read(T &s){s=0;char ch=getchar();T f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-48,ch=getchar();s*=f;}
template<typename T, typename...A>void read(T&f,A&...a){read(f);read(a...);}
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
int t, a, b, c, d; bool dp[31][31][31][31];
int main(){
	for (int i = 0; i <= 30; i++)
		for (int j = 0; j <= 30; j++)
			for (int k = 0; k <= 30; k++)
				for (int l = 0; l <= 30; l++){
					bool &cur = dp[i][j][k][l];
					if (i >= 2 && j && l >= 2) cur |= !dp[i - 2][j - 1][k][l - 2];
					if (i && j && k && l) cur |= !dp[i - 1][j - 1][k - 1][l - 1];
					if (k >= 2 && l) cur |= !dp[i][j][k - 2][l - 1];
					if (j >= 3) cur |= !dp[i][j - 3][k][l];
					if (i && l) cur |= !dp[i - 1][j][k][l - 1];
				}
	t = re;
	while(t--){
		read(a, b, c, d); 
		pr(dp[a][b][c][d] ? "Patrick\n" : "Roland\n");
	}
	return 0;
}

