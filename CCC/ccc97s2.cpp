#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
		int n; cin >> n;
		bool flag = 0;
		set<int> minus, add;
		for (int i = 1; i * i <= n; i++){
			if (n % i == 0){
				int t1 = i + n / i, t2 = n / i - i;
				if (add.count(t2)) flag = 1;
				if (minus.count(t1)) flag = 1;
				minus.insert(t2);
				add.insert(t1);
				if (flag) break;
			}
		}
		cout << n << " is ";
		if (flag) cout << "nasty" << endl;
		else cout << "not nasty" << endl;
	}
    return 0;
}

