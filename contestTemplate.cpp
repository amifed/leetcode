#include <bits/stdc++.h>
using namespace std;
#define it insert
#define pob pop_back
#define pub push_back
#define all(v) (v).begin(), (v).end()
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

class Solution {
public:
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    if (m == 0 || n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ret = 0;
    VVI f(m, VI(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '1') {
                if (i == 0 || j == 0) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
                }
                ret = max(ret, f[i][j]);
            }
        }
    }
    cout << ret * ret << endl;
    return 0;
}