#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool prime[1000001];
    for(int i = 0; i <= 1000000; i++)
        prime[i] = 1;

    prime[1] = 0;
    for(int i = 2; i <= 1000000; i++) {
        if(prime[i] == 0) continue;
        for(int j = i * 2; j <= 1000000; j += i)
            prime[j] = 0;
    }

    vector<int> vprime;
    for(int i = 2; i < 1000000; i++)
        if(prime[i]) vprime.push_back(i);

    int prm_size = vprime.size();
    while(1) {
        int n;
        cin >> n;
        if(n == 0) break;

        int left = 0;
        int right = prm_size - 1;

        while(1) {
            int sum = vprime[left] + vprime[right];
            if(sum > n) right--;
            else if(sum < n) left++;
            else cout << n << " = "
                << vprime[left] << " + " << vprime[right] << '\n';
            if(left > right)
                cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}