#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<string>> results;

public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<string> current(n, string(n, '.'));
    getQueenCombination(0, n, current);
    return this->results;
  }
  bool isValid(vector<string> &board, int row, int col)
  {
    for (int i = 1; i <= row; i++)
    {
      if (board[row - i][col] != '.')
        return false;
      if (row - i >= 0 && col + i < board.size() && board[row - i][col + i] != '.')
        return false;
      if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] != '.')
        return false;
    }
    return true;
  }
  void getQueenCombination(int layer, int n, vector<string> &current)
  {
    for (int i = 0; i < n; i++)
    {
      if (!isValid(current, layer, i))
        continue;
      current[layer][i] = 'Q';
      if (layer == n - 1)
        this->results.push_back(current);
      else
        getQueenCombination(layer + 1, n, current);
      current[layer][i] = '.';
    }
  }
};

int main()
{
  Solution mySol;
  mySol.solveNQueens(3);

  return 0;
}