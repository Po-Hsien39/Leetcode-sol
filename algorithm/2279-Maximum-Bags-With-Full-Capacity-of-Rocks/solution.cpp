#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
  {
    vector<int> bagDiff;
    for (int i = 0; i < rocks.size(); i++)
      bagDiff.push_back(capacity[i] - rocks[i]);
    sort(bagDiff.begin(), bagDiff.end());

    for (int i = 0; i < rocks.size(); i++)
      cout << bagDiff[i] << " ";
    int fullBags = 0;
    for (int i = 0; i < bagDiff.size(); i++)
    {
      if (additionalRocks >= bagDiff[i])
      {
        additionalRocks -= bagDiff[i];
        fullBags++;
      }
      else
      {
        break;
      }
    }
    return fullBags;
  }
};