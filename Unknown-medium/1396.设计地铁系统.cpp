/*
 * @lc app=leetcode.cn id=1396 lang=cpp
 *
 * [1396] 设计地铁系统
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class UndergroundSystem {
private:
  unordered_map<int, pair<string, int>> record;
  unordered_map<string, pair<double, int>> count;

public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    record[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    string name = record[id].first + stationName;
    t -= record[id].second;
    count[name].first += double(t);
    count[name].second++;
  }

  double getAverageTime(string startStation, string endStation) {
    string name = startStation + endStation;
    return count[name].first / double(count[name].second);
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end
