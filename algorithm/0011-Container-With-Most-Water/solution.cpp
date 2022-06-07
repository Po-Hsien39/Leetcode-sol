#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int sPoint = 0;
    int ePoint = height.size() - 1;
    int maxWater = 0;
    while (sPoint < ePoint) {
      maxWater = max(maxWater, (ePoint - sPoint) * min(height[sPoint], height[ePoint]));
      if (height[sPoint] < height[ePoint])
        sPoint++;
      else
        ePoint--;
    }
    return maxWater;
  }
};