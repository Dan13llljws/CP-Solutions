#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int b, n;
vector<char> songs;
int main() {
    songs.pb('A');
    songs.pb('B');
    songs.pb('C');
    songs.pb('D');
    songs.pb('E');
    cin >> b >> n;
    while (b != 4){
        for (int i = 0; i < n; i++){
            if (b == 1){
                songs.pb(songs[0]);
                songs.erase(songs.begin());
            }
            else if (b == 2){
                songs.insert(songs.begin(), songs[4]);
                songs.pop_back();
            }
            else{
                char tmp = songs[0];
                songs[0] = songs[1];
                songs[1] = tmp;
            }
        }
        cin >> b >> n;
    }
    for (int i = 0; i < 5; i++){
        cout << songs[i] << ' ';
    }
    return 0;
}