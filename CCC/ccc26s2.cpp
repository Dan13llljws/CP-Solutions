#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, L, Q; cin >> N >> L >> Q;
	vector<int> psa(N + 2);
	while(L--) {
		int P, S; cin >> P >> S;
		psa[min(N + 1, P + S + 1)]--;
		psa[max(0, P - S)]++;
	}
	for (int i = 1; i <= N; i++) psa[i] += psa[i - 1];
	while(Q--) {
		int x; cin >> x;
		cout << "NY"[psa[x] >= 1] << '\n';
	}
}