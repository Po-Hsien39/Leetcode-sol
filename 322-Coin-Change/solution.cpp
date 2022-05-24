#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<vector<int>> coinList;
    for (int i = 0; i < coins.size() + 1; i++)
    {
      cout << "i: " << i << "\n";
      vector<int> temp;
      for (int j = 0; j < amount + 1; j++)
      {
        if (j == 0)
          temp.push_back(0);
        else
          temp.push_back(-1);
      }
      coinList.push_back(temp);
    }
    for (int i = 1; i < coins.size() + 1; i++)
    {
      for (int j = 1; j < amount + 1; j++)
      {
        cout << "i: " << i << " j: " << j << "\n";
        if (j < coins[j - 1])
          coinList[i][j] = coinList[i - 1][j];
        else
          coinList[i][j] = max(coinList[i - 1][j], coinList[i][j - coins[j - 1]]);
      }
    }
    // return 0;
    return coinList[coins.size()][amount];
  }
};