#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    vector<char> vc;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i ++)
        vc.push_back(s[i]);

    int cur = vc.size();
    int m;
    cin >> m;
    while(m--) {
        char cmd;
        cin >> cmd;
        switch(cmd) {
            case 'L':
                cur -= 1;
                if(cur < 0) cur = 0;
                break;
            case 'D':
                cur++;
                if(cur > vc.size()) cur = vc.size();
                break;
            case 'B':
                if(cur > 0) {
                    vc.erase(vc.begin() + cur - 1);
                    cur--;
                }
                break;
            case 'P':
                char a;
                cin >> a;
                vc.insert(vc.begin() + cur, a);
                cur++;
                break;
        }
    }
}