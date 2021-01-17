#include <bits/stdc++.h>

using namespace std;

char rots(char c) {
    c += 13;
    if(c > 122) c = (c - 122) + 96;
}

char rotb(char c) {
    c += 13;
    if(c > 90) c = (c - 90) + 64;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    string s;
    cin >> s;

    char c[110]{ 0 };
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 65 && s[i] <= 90) c[i] = rotb(s[i]);
        else if(s[i] >= 97 && s[i] <= 122) c[i] = rots(s[i]);
        else c[i] = s[i];
    }

    for(int i = 0; i < s.size(); i++)
        cout << c[i];
}