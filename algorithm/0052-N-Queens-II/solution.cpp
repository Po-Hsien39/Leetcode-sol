#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int totalNQueens(int n)
  {
    int results = 0;
    vector<string> current(n, string(n, '.'));
    getQueenCombination(0, n, results, current);
    return results;
  }
  void getQueenCombination(int layer, int n, int &result, vector<string> &current)
  {
    for (int i = 0; i < n; i++)
    {
      // Check if this is valid
      bool inValid = false;
      int col = layer - 1;
      int row1 = i - 1;
      int row2 = i + 1;
      while (col >= 0)
      {
        if (current[col][i] != '.' ||
            row1 >= 0 && current[col][row1] != '.' ||
            row2 < n && current[col][row2] != '.')
        {
          inValid = true;
          break;
        }
        col--;
        row1--;
        row2++;
      }
      if (inValid)
        continue;
      // Answer
      current[layer][i] = 'Q';
      if (layer == n - 1)
        result++;
      else
        getQueenCombination(layer + 1, n, result, current);
      current[layer][i] = '.';
    }
  }
};

int main()
{
  Solution mySol;
  int res = mySol.totalNQueens(4);
  cout << res << "\n";

  return 0;
}