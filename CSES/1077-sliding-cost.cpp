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
	long long sum = 0;
	for (int i = 0; i < k; i++) sum += abs(a[i] - (*it).first);
	cout << sum << ' ';
	for (int i = k; i < n; i++){
		pair<int,int> cur = {a[i], i}, pre = {a[i - k], i - k};
		s.insert(cur);
		sum += abs(a[i] - (*it).first);
		sum -= abs(a[i - k] - (*it).first);
		long long v = 0;
		if (cur <= *it && pre >= *it){
			v = (*it).first - (*--it).first;
			sum += v * (k / 2);
			sum -= v * (k - k / 2);
		} else if (cur >= *it && pre <= *it){
			v = -(*it).first, v += (*++it).first;			
			sum += v * (k / 2 - ((k & 1) == 0));
			sum -= v * (k - k / 2 + ((k & 1) == 0));
		}
		s.erase(pre);
		cout << sum << ' ';
	}	
}

