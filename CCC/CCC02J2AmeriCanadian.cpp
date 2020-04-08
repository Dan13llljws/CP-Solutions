#include <bits/stdc++.h>
using namespace std;
int main()
{
    string ameri;
    cin >> ameri;
    char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    while (ameri != "quit!"){
        bool consonant = true;
        for (int i = 0; i < 6; i++){
            if (ameri[ameri.length() - 3] == vowels[i]) consonant = false;
        }
        if (consonant && ameri.substr(ameri.length() - 2, 2) == "or" && ameri.length() > 4)
            ameri = ameri.substr(0, ameri.length() - 2) + "our";
        cout << ameri <<endl;
        cin >> ameri;
    }
        return 0;
}