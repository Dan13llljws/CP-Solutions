#include <bits/stdc++.h>
using namespace std;
int n; bool vis[200005];
int main(){
	 cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 cin >> n;
	 for (int i = 1; i < n; i++){
		 int a;
		 cin >> a;
		 vis[a] = 1;
	 }
	 for (int i = 1; i <= n; i++)
		if (!vis[i]){
			cout << i << '\n';
			return 0;
		}
		
}
