#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >>n;
    for (int i = 0; i < n; i++){
        int s, v, o;
        cin >>s >>v >>o;
        cin.ignore();
        string subject[s], verb[v], object[o];
        for (int j = 0; j < s; j++){
            getline(cin, subject[j]);
        }
        for (int j = 0; j < v; j++){
            getline(cin, verb[j]);
        }
        for (int j = 0; j < o; j++){
            getline(cin, object[j]);
        }
        for (int j = 0; j < s; j++){
            for (int k = 0; k < v; k++){
                for (int l = 0; l < o; l++){
                    cout <<subject[j] << " " << verb[k] << " " <<object[l] << "." <<endl;
                }
            }
        }
        cout <<endl;
    }
    return 0;
}