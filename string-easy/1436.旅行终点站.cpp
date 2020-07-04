/**
 * 1436. 旅行终点站
 *
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> map;
    for (auto&& i : paths) {
      map[i[0]] += 1;
      map[i[1]] += 0;
    }
    for (auto&& i : map)
      if (i.second == 0) return i.first;
    return "";
  }
};
int main() {
  vector<vector<string>> paths = {
      {"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
  cout << Solution().destCity(paths);
  return 0;
}