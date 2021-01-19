#include <bits/stdc++.h>

using namespace std;

char m[26][26]{ 0 };

int n = 0;
int sizee = 0;

void find(int i , int j ) {
    if(i < 1 || j < 1 || i > n || j > n || m[i][j] == '0') return;
    if(m[i][j] == '1') {
        m[i][j] = '0';
        sizee++;
    }
    find(i - 1, j);
    find(i, j + 1);
    find(i + 1, j);
    find(i, j - 1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}