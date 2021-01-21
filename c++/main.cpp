#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool prime[10000]{ 0 };
    for(int i = 3; i < 10000; i += 2)
        prime[i] = 1;

    vector<int> vprime;
    pair<int, int> result[10000];
    prime[1] = 0;
    for(int i = 3; i < 10000; i += 2) {
        if(prime[i] == 0) continue;
        vprime.push_back(i);
        for(int j = i * 3; j < 10000; j += (i * 2))
            prime[j] = 0;
        result[i] = {0, 0};
    }



    int prm_size = vprime.size();

    while(1) {
        //int n;
        //cin >> n;
        for(int n = 6; n < 50; n += 2) {
            if(n == 0) break;

            if(result[n].first) {
                cout << n << " = " << result[n].first << 
                        " + " << result[n].second << '\n';
                continue;
            }
            int left = 0;
            int right = prm_size - 1;

            while(1) {
                int sum = vprime[left] + vprime[right];
                result[sum].first = vprime[left];
                result[sum].second = vprime[right];
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
}