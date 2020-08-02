/* https://leetcode-cn.com/contest/weekly-contest-200 */
#include <bits/stdc++.h>
using namespace std;
/* class Solution {
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
        int ret = 0;
        for (int i = 0; i < arr.size() - 2; i++) {
            for (int j = i + 1; j < arr.size() - 1; j++) {
                for (int k = j + 1; k < arr.size(); k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
                        ret++;
                }
            }
        }
        return ret;
    }
}; */
/* class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            int cnt = 0;
            for (int j = i + 1; j < arr.size() && arr[j] < arr[i]; j++)
                cnt++;
            if (cnt >= k) return arr[i];
            if (i > 0 && arr[i] > arr[i - 1] && cnt == k - 1) return arr[i];
        }
        return *max_element(arr.begin(), arr.end());
    }
}; */
/* class Solution {
public:
    int minSwaps(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> zero(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > -1 && grid[i][j] == 0; j--) {
                zero[i]++;
            }
        }
        int ret = 0;
        if (zero.size() < n - 1) return -1;
        for (int i = 0; i < zero.size() - 1; i++) {
            if (zero[i] >= n - i - 1) continue;
            int j = i + 1;
            while (j < zero.size() && zero[j] < n - i - 1)
                j++;
            if (j == zero.size()) return -1;
            ret += j - i;
            for (int k = j; k > i; k--)
                swap(zero[k], zero[k - 1]);
        }
        return ret;
    }
}; */

#define mod 1000000007
class Solution {
public:
    int maxSum(vector<int> &nums1, vector<int> &nums2) {
        long long sum1 = 0, sum2 = 0;
        long long ret = 0;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ret += max(sum1, sum2) + nums1[i];
                sum1 = 0, sum2 = 0;
                i++, j++;
            } else if (nums1[i] < nums2[j]) {
                sum1 += nums1[i++];
            } else {
                sum2 += nums2[j++];
            }
        }
        while (i < nums1.size()) {
            sum1 += nums1[i++];
        }
        while (j < nums2.size()) {
            sum2 += nums2[j++];
        }
        ret += max(sum1, sum2);
        return ret & mod;
    }
};