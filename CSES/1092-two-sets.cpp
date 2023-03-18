#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if (n % 4 == 0){
		cout << "YES\n";
		vector<int> a, b;
		for (int i = 1; i <= n / 2; i++)
			if (i & 1) a.push_back(i), a.push_back(n - i + 1);
			else b.push_back(i), b.push_back(n - i + 1);
		cout << n / 2 << '\n';
		for (int x : a) cout << x << ' ';
		cout << '\n';
		cout << n / 2 << '\n';
		for (int x : b) cout << x << ' ';
		cout << '\n';
	} else if (n % 4 == 3){
		cout << "YES\n";
		vector<int> a, b;
		a.push_back(1), a.push_back(2), b.push_back(3);
		for (int i = 4; i <= n / 2 + 2; i++)
			if (i & 1) a.push_back(i), a.push_back(n - i + 4);
			else b.push_back(i), b.push_back(n - i + 4);
		cout << a.size() << '\n';
		for (int x : a) cout << x << ' ';
		cout << '\n';
		cout << b.size() << '\n';
		for (int x : b) cout << x << ' ';
		cout << '\n';
	 } else cout << "NO\n";
}
