#include <bits/stdc++.h>

using namespace std;

bool mp[65][65]{ 0 };
int n;

bool valid(int i, int j, int i2, int j2) {
    bool pre = mp[i][j];
    for(int i  = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mp[i][j] != pre) return false;
        }
    }
    return true;
}

void partition(int i, int j, int i2, int j2) {
    cout << '(';
    if(valid(i, j, i2, j2)) cout << mp[i][j];
    else {
        int gap = (i + j - 1) / 2;
        partition(i, j, i+gap-1, j+gap-1);
        partition(i, j+gap, i+gap-1, j+2*gap-1);
        partition(i+gap, j, i+2*gap-1, j+gap-1);
        partition(i+gap, j+gap, i+2*gap-1, j+2*gap-1);
    }
    cout << ')';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string s;
    for(int i  = 1; i <= n; i++) {
        cin >> s;
        for(int j = 1; j <= n; j++) {
            mp[i][j] = s[j - 1];
        }
    }

    partition(1, 1, n, n);
}