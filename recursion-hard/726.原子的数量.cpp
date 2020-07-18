/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    int i;
    map<string, int> parse(string &formula) {
        int n = formula.length();
        map<string, int> ret;
        while (i < n && formula[i] != ')') {
            if (formula[i] == '(') {
                i++;
                map<string, int> tmp = parse(formula);
                for (auto &m : tmp)
                    ret[m.first] += m.second;
            } else {
                int start = i;
                i++; //跳过第一个大写字母
                while (i < n && islower(formula[i]))
                    i++;
                string sub = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i]))
                    i++;
                string times = formula.substr(start, i - start);
                ret[sub] += stoi(times == "" ? "1" : times);
            }
        }
        i++; //跳过 )
        int start = i;
        while (i < n && isdigit(formula[i]))
            i++;
        if (start < i) {
            int multiple = stoi(formula.substr(start, i - start));
            for (auto m : ret)
                ret[m.first] *= multiple;
        }
        return ret;
    }

public:
    string countOfAtoms(string formula) {
        i = 0;
        map<string, int> counter = parse(formula);
        string ret;
        for (auto m : counter) {
            ret.append(m.first + (m.second > 1 ? to_string(m.second) : ""));
        }
        return ret;
    }
};
// @lc code=end