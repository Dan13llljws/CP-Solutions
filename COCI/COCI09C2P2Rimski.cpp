#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
string str;
map<char, int> cnt;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(str);
	for (int i = 0; i < str.size(); i++) cnt[str[i]]++;
	if (cnt['C']){
		pr("XC");
		cnt['X']--; cnt['C']--;
	}
	if (cnt['L']){
		if ((cnt['X'] == 1) || (cnt['X'] == 2 && cnt['I'] == 1 && !cnt['V'])){
			pr('X'); cnt['X']--; 
		}
		pr('L'); cnt['L']--;
	}
	while(cnt['X'] > 1){pr('X'); cnt['X']--;}
	if (cnt['X']){
		if (cnt['I'] == 1 && !cnt['V']) {pr("IX"); cnt['I']--; cnt['X']--;}
		else {pr('X'); cnt['X']--;}
	}
	if (cnt['V']){
		if (cnt['I'] == 1){
			pr('I'); cnt['I']--;
		}
		pr('V'); cnt['V']--;
	}
	for (int i = 0; i < cnt['I']; i++) pr('I');
	return 0;
}

