#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool prime[1000001]{ 0 };
    for(int i = 3; i < 1000000; i += 2)
        prime[i] = 1;

    vector<int> vprime;
    prime[1] = 0;
    for(int i = 3; i < 1000000; i += 2) {
        if(prime[i] == 0) continue;
        vprime.push_back(i);
        for(int j = i * 3; j < 1000000; j += i * 2)
            prime[j] = 0;
    }

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
            else {
                cout << n << " = " << vprime[left] << 
                    " + " << vprime[right] << '\n';
                break;
            }
            if(left > right) {
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }
        }
    }
}