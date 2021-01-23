#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bool prime[100001];
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;

    for(int i = 1; i*i <= 100000; i++) {
        if(!prime[i]) continue;
        for(int j = 2*i; j <= 10000; j += i) {
            prime[j] = 0;
        }
    }
    for(int i = 1; i <= 100000; i++) {
        if(prime[i]) {
            while(n%i == 0) {
                cout << i << '\n';
                n /= i;
            }
        }
        if(n == 1) break;
    }
}