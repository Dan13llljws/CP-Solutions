#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string sen;
    getline (cin, sen);
    int happy = 0, sad = 0;
    for (int i = 0; i < sen.length(); i++){
        if (sen.substr(i, 3) == ":-)") happy++;
        else if (sen.substr(i, 3) == ":-(") sad++;
    }
    if (happy == 0 && sad == 0) printf("none");
    else if (happy > sad) printf("happy");
    else if (happy < sad) printf("sad");
    else printf("unsure");
    return 0;
}