#include <bits/stdc++.h>
using namespace std;
#define it insert
#define pob pop_back
#define pub push_back
#define emb emplace_back
#define all(v) (v).begin(), (v).end()
#define mkp(a, b) make_pair(a, b)
#define forr(n, s, e) for (int(n) = (s); (n) < (e); (n)++)
#define rfor(n, s, e) for (int(n) = (s); (n) > (e); (n)--)
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;

/**
 * 线段树， 区间修改 and 懒惰标记
 */
LL n, a[MAXN], d[4 * MAXN], b[4 * MAXN];
void build(LL s, LL t, LL p) {
    if (s == t) {
        d[p] = a[s];
        return;
    }
    LL m = (s + t) >> 1;
    build(s, m, p << 1), build(m + 1, t, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}
LL getsum(LL l, LL r, LL s = 1, LL t = n, LL p = 1) {
    if (l <= s && t <= r) return d[p];
    LL m = (s + t) >> 1;
    if (b[p])
        d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
            b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
    b[p] = 0;
    LL sum = 0;
    if (l <= m) sum += getsum(l, r, s, m, p << 1);
    if (r > m) sum += getsum(l, r, m + 1, t, (p << 1) | 1);
    return sum;
}
void update(LL l, LL r, LL c, LL s, LL t, LL p) {
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * c, b[p] += c;
        return;
    }
    LL m = (s + t) >> 1;
    if (b[p])
        d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
            b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
    b[p] = 0;
    if (l <= m) update(l, r, c, s, m, p << 1);
    if (r > m) update(l, r, c, m + 1, t, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}
int main() {
    LL q, op, x, y, k;
    scanf("%lld %lld", &n, &q);
    forr(i, 1, n + 1) scanf("%lld", &a[i]);
    build(1, n, 1);
    while (q--) {
        scanf("%lld %lld %lld", &op, &x, &y);
        if (op == 1) {
            scanf("%lld", &k);
            update(x, y, k, 1, n, 1);
        } else {
            printf("%lld\n", getsum(x, y, 1, n, 1));
        }
    }
    return 0;
}