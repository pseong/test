#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n, p, k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;

        int bound[100010] = {0};
        int start = p - 1;

        bound[start] = (s[start] == '1') ? 0 : x;
        for(int i = start + 1; i < start + k; i++) {
            if(i > n - 1) continue;
            bound[i] = y * (i - start);
            bound[i] += ((s[i] == '1') ? 0 : x);
        }
        for(int i = start + k; i < n; i++) {
            bound[i] = bound[i - k] + ((s[i] == '1') ? 0 : x);
        }
        
        int result = bound[n - 1];
        for(int i = 1; i < k; i++) {
            if(n - 1 - i < start) continue;
            result = min(result, bound[n - 1 - i]);
        }

        for(int i = n - 1; i > n - 1 - k; i--) {
            if(i < start) continue;
            result = min(result, i * y + ((s[i] == '1') ? 0 : x));
        }
        cout << result << '\n';
    }
}


// a = b + (3 > 1) ? 1 : 2; 주의해야한는게 괄호 꼭 쳐줘야한다.
// a = b + ((3 > 1) ? 1 : 2); 이렇게 그냥 모르겠으면 무조건 괄호 쓰는 습관ㄱ

// a.n-k+1 ~

// p, p+k, p+2k . . .
// x = add seconds, y = remove seconds

// n p k              1 <= p <= n <= 10e5,  1 <= k <= n
// level              a1 - an
// x y                1 <= x, y <= 10e4
// all sum n is under 10e5

// minimum number of seconds I need