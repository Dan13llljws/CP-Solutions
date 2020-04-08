#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
int n, k, a1, a2, b1, b2, ans[101];
int next(int x){
	if (a1 <= x && a2 >= x) x = a2 + a1 - x;
	if (b1 <= x && b2 >= x) x = b2 + b1 - x;
	return x;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n, k, a1, a2, b1, b2);
	for (int i = 1; i <= n; i++){
		int swaps = 1, nex = next(i);
		while(nex != i){
			swaps++;
			nex = next(nex);
		}
		for (int j = 0; j < k % swaps; j++) nex = next(nex);
		ans[nex] = i;
	}
	for (int i = 1; i <= n; i++) pr(ans[i], nl);
	return 0;
}
