#include <bits/stdc++.h>

using namespace std;

int cng = 100010;
void find(vector<int> v, int lv) {
    if(v.size() < 2 || lv >= cng) return;

    int pre = 0;
    for(int i : v) {
        if (pre > i) {
            cng = min(cng, lv);
            return;
        }
        pre = i;
    }

    for(auto i = 0; i < v.size() - 1; i++) {
        int a = v[i];
        int b = v[i + 1];
        int f = a^b;

        v[i] = f;
        v.erase(v.begin() + i + 1);

        int pre = 0;
        for(int i : v) {
            if (pre > i) {
                cng = min(cng, lv + 1);
                return;
            }
            pre = i;
        }

        v[i] = a;
        v.insert(v.begin() + i + 1, b);
    }

    for(auto i = 0; i < v.size() - 1; i++) {
        int a = v[i];
        int b = v[i + 1];
        int f = a^b;

        v[i] = f;
        v.erase(v.begin() + i + 1);

        find(v, lv + 1);

        v[i] = a;
        v.insert(v.begin() + i + 1, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int t;
    cin >> t;
    vector<int> v;
    while(t--) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    find(v, 0);

    cout << ((cng == 100010) ? -1 : cng);
}