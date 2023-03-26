#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	while(1){
		string in; cin >> in;
		bool f = 0;
		for (char c : in)
			if (c == '>' || c == '<' || c == '+' || c == '-' || c == '[' || c == ']' || c == '.') s.push_back(c);
			else if (c == '#') f = 1;
		if (f) break;
	}
	vector<unsigned char> a(30005);
	int ptr = 0;
		int n = s.size(), t = 0;
		vector<int> l(n), r(n), st(n + 1);
		for (int i = 0; i < n; i++)
			if (s[i] == '[') st[++t] = i;
			else if (s[i] == ']') l[i] = st[t], r[st[t]] = i, t--;
		for (int i = 0; i < n; i++)
			if (s[i] == '#') return 0;
			else if (s[i] == '>') ptr++;
			else if (s[i] == '<') ptr--;
			else if (s[i] == '+') a[ptr]++;
			else if (s[i] == '-') a[ptr]--;
			else if (s[i] == '[' && !a[ptr]) i = r[i];
			else if (s[i] == ']' && a[ptr]) i = l[i];
			else if (s[i] == '.') cout << a[ptr];
}

