/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n1 = num1.length(), n2 = num2.length();
        int size = n1 + n2;
        int v[size] = {0};
        for (int i = n1 - 1; i > -1; i--) {
            for (int j = n2 - 1; j > -1; j--) {
                v[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = size - 1; i > 0; i--) {
            v[i - 1] += v[i] / 10;
            v[i] %= 10;
        }
        string ret;
        for (int i = v[0] == 0 ? 1 : 0; i < size; i++) {
            ret.push_back(v[i] + '0');
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    cout << 99 * 99 << endl;
    cout << Solution().multiply("123", "456");
    return 0;
}
