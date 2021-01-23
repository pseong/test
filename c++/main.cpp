#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a;
    vector<int> b;

    int n, m;
    cin >> n >> m;

    int d;
    for(int i = 1; i <= n; i++) {
        cin >> d;
        a.push_back(d);
    }
    for(int i = 1; i <= m; i++) {
        cin >> d;
        b.push_back(d);
    }

    vector<int> result;

    int size_a = a.size();
    int size_b = b.size();

    int i = 0;
    int j = 0;

    while(1) {
        if(a[i] >= b[j]) {
            result.push_back(b[j]);
            ++j;
        }
        else {
            result.push_back(a[i]);
            ++i;
        }
        if(i == size_a || j == size_b) break;
    }
    if(j == size_b) {
        swap(a, b);
        swap(i, j);
    }
    while(i != size_a) {
        result.push_back(a[i]);
        i++;
    }
    for(int re : result) {
        cout << re << ' ';
    }
}