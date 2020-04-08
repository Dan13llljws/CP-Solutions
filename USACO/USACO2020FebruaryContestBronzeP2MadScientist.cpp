#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
int n, ans; string a, b;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n, a, b); bool flag = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != b[i]){
			if (!flag){
				ans++;
				flag = 1;
			}
		}
		else flag = 0;
	}
	pr(ans);
	return 0;
}

