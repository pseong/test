#include <bits/stdc++.h>

using namespace std;

int a[501]{ 0 };
int tree[20000]{ 0 };
int tree_size[20000]{ 0 };
int ans = 0;

int init(int start, int end, int node) {
    if(start == end) {
        tree_size[node] = 1;
        return tree[node] = a[start];
    }
    int mid = (start + end) / 2;
    int a = init(start, mid, node * 2);
    tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    tree_size[node] = tree_size[node * 2] + tree_size[node * 2 + 1];
    return tree[node];
}

void bubble(int node) {
    if(out_of_range || !tree_size[node]) return;
    if(tree[node * 2] > tree[node * 2 + 1]) {
        ans += (tree_size[node * 2] + tree_size[node * 2 + 1]);
    } 
    else {
        bubble
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    init(1, n, 1);
    for(int i = 1; i <= n * 4; i++) {
        cout << tree[i] << ' ';
    }
}