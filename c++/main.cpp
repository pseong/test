#include <bits/stdc++.h>

using namespace std;

int a[500001]{ 0 };
int sorted[500001]{ 0 };
int cnt = 0;
int ans = 0;

void merge(int m, int mid, int n) {
    int i = m;
    int j = mid + 1;
    int k = m;

    while(i <= mid && j <= n) {
        if(a[i] <= a[j]) {

        }
    }
}

void mergeSort(int m, int n) {
    if(m < n) {
        int mid = (m + n) / 2;
        mergeSort(m, mid);
        mergeSort(mid + 1, n);
        merge(m, mid, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}