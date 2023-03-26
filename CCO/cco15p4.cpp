#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define f first
#define s second
typedef pair<int, int> pii;
const int MM = 2e3 + 5;
int N, M, t; char grid[MM][MM];
unordered_map<char, pii> dict = {{'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}};
void dfs(int x, int y, char D){
    pii dir = dict[D]; 
    for (int i = x + dir.f, j = y + dir.s; i >= 0 && i < N && j >= 0 && j < M; i += dir.f, j += dir.s)
        if (grid[i][j] != '.') dfs(i, j, grid[i][j]);
    grid[x][y] = '.';
    pr('(', x, ',', y, ')', nl);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sc(N, M);
    for (int i = 0; i < N; i++) sc(grid[i]);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (grid[i][j] != '.'){
                dfs(i, j, grid[i][j]);
            }
        }
    }
    return 0;
}