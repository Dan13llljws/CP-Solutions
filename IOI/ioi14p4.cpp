#include <bits/stdc++.h>
using namespace std;

bool normalize(int n, int a[]) {
	auto i = min_element(a, a + n) - a;
	if (a[i] > n) return false;
	int shift = (i - (a[i] - 1) + n) % n;
	rotate(a, a + shift, a + n);
	return true;
}

int valid(int n, int inputSeq[]) {
	unordered_set<int> seen(inputSeq, inputSeq + n);
	if (seen.size() != n) return 0;
	if (!normalize(n, inputSeq)) return 1;
	for (int i = 0; i < n; i++)
		if (inputSeq[i] <= n && inputSeq[i] - inputSeq[0] != i) return 0;
	return 1;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
	normalize(n, gondolaSeq);
	vector<int> idx;
	for (int i = 0; i < n; i++)
		if (gondolaSeq[i] > n) idx.push_back(i);
	int ans = 0;
	ranges::sort(idx, [&](int i, int j) { return gondolaSeq[i] < gondolaSeq[j]; });
	for (int i : idx) {
		int cur = i + 1;
		while(cur < gondolaSeq[i]) replacementSeq[ans] = cur, cur = n + ++ans;
	}
	return ans;
}

const int mod = 1e9 + 9;

int fpow(int x, int k) {
	int ret = 1;
	while(k) {
		if (k & 1) ret = 1LL * ret * x % mod;
		x = 1LL * x * x % mod, k >>= 1;
	}
	return ret;
}

int countReplacement(int n, int inputSeq[]) {
	bool random = normalize(n, inputSeq);
	vector<int> a;
	for (int i = 0; i < n; i++)
		if (inputSeq[i] > n) a.push_back(inputSeq[i] - n);
	if (a.empty()) return 1;
	int m = a.size();
	ranges::sort(a);
	int ans = fpow(m--, a[0] - 1);
	for (auto [last, cur] : a | views::adjacent<2>) {
		if (last == cur) return 0;
		ans = 1LL * ans * fpow(m--, cur - last - 1) % mod;
	}
	if (!random) ans = 1LL * ans * n % mod;
	return ans;
}