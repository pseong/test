#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    double lo = 0;
    double hi = 0;

    double rati = (double)1 / 3;

    for(int i = 0; i < 100; i++) {
        double mx1 = ax + (ax + bx) * rati;
        double my1 = ay + (ay + by) * rati;

        double mx2 = ax + (ax + bx) * (1 - rati);
        double my2 = ax + (ax + bx) * (1 - rati);

        double gx1 = cx + (cx + dx) * rati;
        double gy1 = cy + (cy + dy) * rati;

        double gx2 = cx + (cx + dx) * (1 - rati);
        double gy2 = cy + (cy + dy) * (1 - rati);

        lo = sqrt(pow(mx1 - gx1, 2) + pow(my1 - gy1, 2));
        hi = sqrt(pow(mx2 - gx2, 2) + pow(my2 - gy2, 2));

        if(lo <= hi) {
            rati *= (1 / 3);
        }
        else {
            rati += (1 - rati)*(1 / 3);
        }
    }

    std::cout << lo;
}