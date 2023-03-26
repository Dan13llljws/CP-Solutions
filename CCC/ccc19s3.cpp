#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll g[3][3], cr[3], cc[3], done, cancer = -1e9 - 1, mother = -1e9 - 1, fucker = -1e9 - 1;
void solr(int i){
	if (cr[i] != 2) return; 
	if (g[i][0] == -1e9 - 1) g[i][0] = g[i][1] * 2 - g[i][2], cc[0]++; 
	else if (g[i][1] == -1e9 - 1) g[i][1] = (g[i][0] + g[i][2]) / 2, cc[1]++;
	else g[i][2] = g[i][1] * 2 - g[i][0], cc[2]++;
	done++, cr[i]++;
}
void solc(int i){
	if (cc[i] != 2) return;
	if (g[0][i] == -1e9 - 1) g[0][i] = g[1][i] * 2 - g[2][i], cr[0]++;
	else if (g[1][i] == -1e9 - 1) g[1][i] = (g[0][i] + g[2][i]) / 2, cr[1]++;
	else g[2][i] = g[1][i] * 2 - g[0][i], cr[2]++;
	done++, cc[i]++;
}
void get(){
	done = 0; ms(cr, 0); ms(cc, 0);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (g[i][j] == -1e9 - 1) continue;
			done++, cr[i]++, cc[j]++;
			if (i == 1 && j == 1) cancer = g[i][j];
			else if (i == 1 || j == 1) mother = g[i][j];
			else fucker = g[i][j];
		}
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			string s; sc(s);
			if (s == "X") g[i][j] = -1e9 - 1;
			else {
				g[i][j] = stoi(s), cr[i]++, cc[j]++, done++;
				if (i == 1 && j == 1) cancer = g[i][j];
				else if (i == 1 || j == 1) mother = g[i][j];
				else fucker = g[i][j];
			}
		}
	if (done == 1 || !done){
		cancer = mother;
		if (cancer == -1e9 - 1) cancer = fucker;
		if (cancer == -1e9 - 1) cancer = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) pr(cancer, sp); pr(nl);
		}
		return 0;
	}
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	if (done == 9){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++)
				pr(g[i][j], sp);
			pr(nl);
		}
		return 0;
	}
	if (done == 2) {
		if (cancer != -1e9 - 1){
			g[0][1] = cancer;
		}
		else if (mother != -1e9 - 1){
			g[1][1] = mother;
			cr[1]++, cc[1]++;
		}
		else if (fucker != -1e9 - 1){
			g[1][1] = fucker;
			cancer = fucker;
		}
	}
	get();
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	if (done == 3){
		if (cancer != -1e9 - 1){
			if (mother != -1e9 - 1){
				g[0][0] = mother;
			}
			else if (fucker != -1e9 - 1){
				int tmp = 0;
				if (g[0][0] != -1e9 - 1) tmp += g[0][0];
				if (g[0][2] != -1e9 - 1) tmp += g[0][2];
				if (g[2][0] != -1e9 - 1) tmp += g[2][0];
				if (g[2][2] != -1e9 - 1) tmp += g[2][2];
				tmp /= 2;
				if (g[0][0] == -1e9 - 1) g[0][0] = tmp;
				else g[0][2] = tmp;
			}
			
		}
		else g[1][1] = mother;
	}
	get();
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	if (done == 9){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++)
				pr(g[i][j], sp);
			pr(nl);
		}
		return 0;
	}
	if (cr[0] == 3){
		if (cc[0] == 3) g[1][1] = g[1][0] + g[0][1] - g[0][0];
		else if (cc[1] == 3) g[1][0] = g[0][0] + g[1][1] - g[0][1];
		else if (cc[2] == 3) g[1][0] = g[0][0] + g[1][2] - g[0][2];
	}
	else if (cr[1] == 3){
		if (cc[0] == 3) g[0][1] = g[0][0] + g[1][1] - g[1][0];
		else if (cc[1] == 3) g[0][2] = g[0][1] + g[1][2] - g[1][1];
		else if (cc[2] == 3) g[0][1] = g[0][2] + g[1][1] - g[1][2];
	}
	else if (cr[2] == 3){
		if (cc[0] == 3) g[1][1] = g[1][0] + g[2][1] - g[2][0];
		else if (cc[1] == 3) g[1][0] = g[2][0] + g[1][1] - g[2][1];
		else if (cc[2] == 3) g[1][0] = g[2][0] + g[1][2] - g[2][2];
	} 
	get();
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	solr(0); solc(0); solr(1); solc(1); solr(2); solc(2);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			pr(g[i][j], sp);
		pr(nl);
	}
	return 0;
}

/*--bruce in a nutshell
int a[3][3], miss[3][3], row[3], col[3], x; string s;
int ord[5][2] = {{1,1}, {0, 1}, {1, 0}, {1, 2}, {2, 1}};
void solveR(int i){
    if(miss[i][0]){ a[i][0] = 2*a[i][1] - a[i][2]; miss[i][0] = 0; col[0]--; }
    if(miss[i][1]){ a[i][1] = (a[i][0] + a[i][2])/2; miss[i][1] = 0; col[1]--;}
    if(miss[i][2]){ a[i][2] = 2*a[i][1] - a[i][0]; miss[i][2] = 0; col[2]--; }
    row[i]--; x--;
}
void solveC(int j){
    if(miss[0][j]){ a[0][j] = 2*a[1][j] - a[2][j]; miss[0][j] = 0; row[0]--;}
    if(miss[1][j]){ a[1][j] = (a[0][j] + a[2][j])/2; miss[1][j] = 0; row[1]--; }
    if(miss[2][j]){ a[2][j] = 2*a[1][j] - a[0][j]; miss[2][j] = 0; row[2]--;}
    col[j]--; x--;
}
void fillCell(int i, int j){
    a[i][j] = 0; miss[i][j] = 0; row[i]--; col[j]--; x--;
}
int main(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> s;
            if(s == "X") { miss[i][j]=1; row[i]++; col[j]++; x++; }
            else a[i][j] = stoi(s);
        }
    }
    while(x > 0 && x < 9){
        for(int i=0; i<3; i++)
            if(row[i] == 1) { solveR(i); goto next; }
        for(int j=0; j<3; j++)
            if(col[j] == 1) { solveC(j); goto next; }
        for(int i=0; i<5; i++){
            if(miss[ord[i][0]][ord[i][1]]) { fillCell(ord[i][0], ord[i][1]); goto next;}
        }
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(miss[i][j]) {fillCell(i, j); goto next;}
next: ;
    }
    for(int i=0; i<3; i++, cout<<endl)
        for(int j=0; j<3; j++)
            cout << a[i][j] << " ";
}
*/

