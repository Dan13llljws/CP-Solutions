#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	set<pair<int,int>> s;
	for (int i = 0; i < k; i++) s.insert({a[i], i});
	auto it = s.begin();
	for (int i = 0; i < (k + (k & 1)) / 2 - 1; i++) it++;
	cout << (*it).first << ' ';
	for (int i = k; i < n; i++){
		pair<int,int> cur = {a[i], i}, pre = {a[i - k], i - k};
		s.insert(cur);
		if (cur <= *it && pre >= *it) it--;
		else if (cur >= *it && pre <= *it) it++;
		cout << (*it).first << ' ';
		s.erase(pre);
	}	
}

