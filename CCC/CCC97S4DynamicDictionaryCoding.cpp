#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
int N;
string s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin.ignore();
    for (int c = 0; c < N; c++){
        map<string, int> w;
        string word = ""; int index = 1;
        getline(cin, s);
        s += ' ';
        while (s.length() != 0){
            for (int i = 0; i < s.length(); i++){
                if (s[i] != ' ')word += s[i];
                else{
                    if (w[word] == 0){
                        w[word] = index;
                        index++;
                        cout << word << " ";
                    }
                    else cout << w[word] << " ";
                    word = "";
                }
            }
            cout << "\n";
            getline(cin, s);
            if (s.length() != 0) s += ' ';
        }
        cout << "\n";
    }
    return 0;
}