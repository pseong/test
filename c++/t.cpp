#include <bits/stdc++.h>

using namespace std;

short m, n;

bool valid(short i, short j) {
    if(i < 1 || j < 1 || i > n || j > m) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    short box[1010][1010]{ 0 };
    cin >> m >> n;

    queue<tuple<short, short, short>> que;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) que.push({i, j, 1});
        }
    
    while(!que.empty()) {
        auto a = que.front(); que.pop();
        int i = get<0>(a); int j = get<1>(a); int k = get<2>(a);
        box[i][j] = k;

        if(box[i - 1][j] == 0 && valid(i - 1, j)) que.push({i - 1, j, k + 1});
        if(box[i + 1][j] == 0 && valid(i + 1, j)) que.push({i + 1, j, k + 1});
        if(box[i][j - 1] == 0 && valid(i, j - 1)) que.push({i, j - 1, k + 1});
        if(box[i][j + 1] == 0 && valid(i, j + 1)) que.push({i, j + 1, k + 1});
    }

    short mx = 0;
    bool result = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            mx = max(mx, box[i][j]);
            if(box[i][j] == 0) result = 0;
        }
    if(result) cout << mx - 1;
    else cout << -1;
}