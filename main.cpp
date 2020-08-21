#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> f(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            f[j] = f[j] + f[j - 1];
        }
    }
    cout << f[n - 1] << endl;
    return 0;
}
