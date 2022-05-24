#include <iostream>
#include <vector>

using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
  return v1[0] < v2[0];
}

class Solution
{
public:
  int minimumLines(vector<vector<int>> &stockPrices)
  {
    if (stockPrices.size() <= 1)
      return 0;
    sort(stockPrices.begin(), stockPrices.end(), sortcol);
    int mX = stockPrices[1][0] - stockPrices[0][0];
    int mY = stockPrices[1][1] - stockPrices[0][1];
    int lineNum = 1;

    for (int i = 2; i < stockPrices.size(); i++)
    {
      long targetX = stockPrices[i][0] - stockPrices[i - 1][0];
      long targetY = stockPrices[i][1] - stockPrices[i - 1][1];
      long temp1 = targetY * mX;
      long temp2 = targetX * mY;
      if (!(temp1 == temp2))
      {
        mX = targetX;
        mY = targetY;
        lineNum++;
      }
    }
    return lineNum;
  }
};