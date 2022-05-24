#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxConsecutive(int bottom, int top, vector<int> &special)
  {

    sort(special.begin(), special.end());
    if (special.size() == 1)
    {
      int left = special[0] - bottom;
      int right = top - special[0];
      if (left < right)
        return right;
      return left;
    }
    else
    {
      int maxFloor = special[0] - bottom;
      for (int i = 1; i < special.size(); i++)
      {
        if (special[i] - special[i - 1] - 1 > maxFloor)
          maxFloor = special[i] - special[i - 1] - 1;
      }
      if (top - special[special.size() - 1] > maxFloor)
        maxFloor = top - special[special.size() - 1];
      return maxFloor;
    }
    return 0;
  }
};