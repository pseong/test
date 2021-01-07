#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;
int main()
{
    indexed_set s;
    s.insert(7);
    s.insert(9);
    s.insert(2);
    s.insert(3);

    cout << s.order_of_key(8) << "\n";
    return 0;
}