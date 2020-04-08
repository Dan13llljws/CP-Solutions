#include <iostream>
using namespace std;
int n, ans;
pair<int, int> get(int x){
	for (int i = 2; i < x; i++)
		if (x % i == 0) return {i, x / i};
	return {x, 1};
}
int main(){
	cin >> n;
	while(n != 1){
		pair<int, int> p = get(n);
		n -= p.second;
		ans += p.first - 1;
	}
	cout << ans;
	return 0;
}
