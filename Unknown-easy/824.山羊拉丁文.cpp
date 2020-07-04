/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<string> split(string s, char ch) {
    vector<string> ret;
    int index = 0, pos = 0;
    if (s.find_first_of(ch) != string::npos || s.length() > 0)
      s.push_back(ch);
    while (true) {
      pos = s.find(ch, index);
      if (pos == string::npos)
        break;
      ret.push_back(s.substr(index, pos - index));
      index = pos + 1;
    }
    return ret;
  }
  string toGoatLatin(string S) {
    vector<string> vs = split(S, ' ');
    string aeiou = "aeiou";
    for (auto &&i : vs) {
      if (aeiou.find(tolower(i[0])) != string::npos)
        continue;
      char ch = i[0];
      i.erase(i.begin());
      i.push_back(ch);
    }
    string ret;
    for (int i = 0; i < vs.size(); i++) {
      vs[i].append("ma");
      for (int j = 0; j < i + 1; j++)
        vs[i].push_back('a');
      ret.append(vs[i]);
      if (i < vs.size() - 1)
        ret.push_back(' ');
    }
    return ret;
  }
};
// @lc code=end
int main() {
  Solution().split("", ' ');
  return 0;
}