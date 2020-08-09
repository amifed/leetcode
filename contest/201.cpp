#include <bits/stdc++.h>
using namespace std;
/* class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        while (i < s.length()) {
            if (i < s.length() - 1 && s[i] - 32 == s[i + 1] || s[i] + 32 == s[i + 1]) {
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i = 0;
                continue;
            }
            i++;
        }
        return s;
    }
}; */
/* class Solution {
public:
    string invert(string s) {
        string ret;
        for (auto c : s) {
            ret.push_back(c == '0' ? '1' : '0');
        }
        return ret;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; i++) {
            string tmp = invert(s);
            reverse(tmp.begin(), tmp.end());
            s = s + "1" + tmp;
        }
        return s[k - 1];
    }
}; */
class Solution {
public:
    // 前缀和 + 哈希表优化 + 贪心选择
    int maxNonOverlapping(vector<int> &nums, int target) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, end = -1;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum - target) != mp.end()) {
                if (mp[sum - target] + 1 > end) {
                    ret++;
                    end = i;
                }
            }
            mp[sum] = i;
        }
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    return 0;
}
