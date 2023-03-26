#include <bits/stdc++.h>
using namespace std;
int n; long long p[32];
bool check(int b){
	int i = 0, tmp = n;
	for (i = 1; i < 32; i++){
		p[i] = p[i - 1] * b;
		if (p[i] * b > n) break;
	}
	vector<int> a;
	for (; i >= 0; i--)
		assert(p[i] != 0), a.push_back(tmp / p[i]), tmp %= p[i];
	i = a.size();
	for (int j = 0; j < i; j++)
		if (a[j] != a[i - j - 1])  return 0;
	return 1;
}
int main(){
	scanf("%d", &n), p[0] = 1;
	if (n == 2) return 0;
	for (int i = 2; i * i <= n; i++)
		if (check(i)) printf("%d\n", i);
	for (int i = sqrt(n - 1); i >= 1; i--){
		if (n % i || n / i - 1 <= i) continue;
		printf("%d\n", n / i - 1);
	}
}

