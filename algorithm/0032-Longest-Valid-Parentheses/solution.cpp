#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
  int longestValidParentheses(string s)
  {
    vector<int> dp(s.size(), 0);
    int max = 0;
    for (int i = 1; i < s.size(); i++)
    {
      if (s[i] == '(')
        continue;
      int target = i - 1;
      while (target >= 0 && dp[target] != 0)
        target -= dp[target];

      if (target < 0)
        continue;
      if (s[target] == '(')
      {
        dp[i] = i - target + 1;
        if (target > 0)
          dp[i] += dp[target - 1];
        if (dp[i] > max)
          max = dp[i];
      }
    }
    return max;
  }
};
