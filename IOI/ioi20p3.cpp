#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll find_maximum(int k, vector<vector<int>> x) {
	int n = x.size(), m = x[0].size();	
	vector<vector<int>> s(n, vector<int>(m, -1));
	ll sum = 0;

	struct Item { int i, j, val; };
	priority_queue<Item, vector<Item>, decltype([](Item a, Item b) {
		return a.val < b.val;
	})> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			sum -= x[i][j];
			s[i][j] = -2; // sub
		}
		q.emplace(i, m - 1, x[i][m - 1] + x[i][k - 1]);
	}

	for (int t = 0; t < k * n / 2; t++) {
		auto [i, j, v] = q.top(); q.pop();
		sum += v;
		s[i][j - m + k] = -1;
		s[i][j] = -3; // add
		if (j > m - k) q.emplace(i, j - 1, x[i][j - 1] + x[i][j - m + k - 1]);
	}

	int c = 0;
	for (int i = 0; i < n; i++) {
		vector<int> used(k);
		for (int j = 0; j < m; j++) {
			if (s[i][j] == -2) {
				used[s[i][j] = c++] = 1;
				if (c == k) c = 0;
			}
		}
		for (int j = 0, l = 0; j < m; j++) {
			if (s[i][j] == -3) {
				while(used[l]) l++;
				s[i][j] = l++;
			}
		}
	}

	allocate_tickets(s);
	return sum;
}