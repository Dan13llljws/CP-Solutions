#include <iostream>
#include <algorithm>
using namespace std;
int dmoj[101], peg[101];
int q, n;
int main() {
	cin >> q >> n;
	for (int i = 0; i < n; ++i){
		int a;
		cin >> a;
		dmoj[i] = a;
	}
	for (int i = 0; i < n; ++i){
		int a;
		cin >> a;
		peg[i] = a;
	}
	sort(dmoj, dmoj + n);
	sort(peg, peg + n);
	if (q == 2){
		reverse(peg, peg+n);
	}
	int t = 0;
	for (int i = 0; i < n; ++i){
		t = t + max(dmoj[i],peg[i]);
	}
	cout << t;
}