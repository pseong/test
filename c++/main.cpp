#include <bits/stdc++.h>

using namespace std;

int find(vector<int> v) {
    if(v.size() < 2) return 0;

    int result = 0;

    int a = 0;
    for(int i : v) {
        if (a > i) { 
            result += 1;
            break;
        }
        a = i;
    }

    for(auto i = v.begin(); i < v.end() - 1; i++) {
        int a = *i;
        int b = *(i+1);
        int j = a^b;

        v.erase(i); *(i+1) = j;
        result += find(v);
        v.insert(i, a); *(i+1) = b;
    }
    return result;
}

int main() {
    ios_base :: sync_with_stdio(false); 
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
    int result;
    result = find(v);

    if(result == 0) {
        cout << -1;
    } else {
        cout << result;
    }
}