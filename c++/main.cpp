#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp0[110]{ 0 };
    int dp1[110]{ 0 };
    int dp2[110]{ 0 };
    int dp3[110]{ 0 };
    int dp4[110]{ 0 };
    int dp5[110]{ 0 };
    int dp6[110]{ 0 };
    int dp7[110]{ 0 };
    int dp8[110]{ 0 };
    int dp9[110]{ 0 };

    
    dp0[1] = 0;
    dp1[1] = 1;
    dp2[1] = 1;
    dp3[1] = 1;
    dp4[1] = 1;
    dp5[1] = 1;
    dp6[1] = 1;
    dp7[1] = 1;
    dp8[1] = 1;
    dp9[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp0[i] = dp1[i - 1] % 1000000000;
        dp1[i] = (dp0[i - 1] + dp2[i - 1]) % 1000000000;
        dp2[i] = (dp1[i - 1] + dp3[i - 1]) % 1000000000;
        dp3[i] = (dp2[i - 1] + dp4[i - 1]) % 1000000000;
        dp4[i] = (dp3[i - 1] + dp5[i - 1]) % 1000000000;
        dp5[i] = (dp4[i - 1] + dp6[i - 1]) % 1000000000;
        dp6[i] = (dp5[i - 1] + dp7[i - 1]) % 1000000000;
        dp7[i] = (dp6[i - 1] + dp8[i - 1]) % 1000000000;
        dp8[i] = (dp7[i - 1] + dp9[i - 1]) % 1000000000;
        dp9[i] = dp8[i - 1] % 1000000000;
    }
    cout << (dp0[n] + dp1[n] + dp2[n] + dp3[n] + dp4[n] + dp5[n] + dp6[n] + dp7[n] + dp8[n] + dp9[n]) % 1000000000;
}