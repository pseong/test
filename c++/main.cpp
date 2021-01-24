#include <bits/stdc++.h>

using namespace std;

bool mp[65][65]{ 0 };
int n;

bool valid(int i, int j, int i2, int j2) {
    bool pre = mp[i][j];
    for(int i  = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
}

void partition(int i, int j, int i2, int j2) {

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