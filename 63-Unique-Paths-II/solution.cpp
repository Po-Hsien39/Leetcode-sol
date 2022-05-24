// Slow Version
// TLE in big case
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  int totalPaths;

public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    this->totalPaths = 0;
    workPath(0, 0, obstacleGrid);
    return this->totalPaths;
  }
  void workPath(int x, int y, vector<vector<int>> &obstacleGrid)
  {
    if (obstacleGrid[x][y] == 1)
      return;
    if (x == obstacleGrid.size() - 1 && y == obstacleGrid[0].size() - 1)
    {
      this->totalPaths += 1;
      return;
    }
    if (x < obstacleGrid.size() - 1 && obstacleGrid[x + 1][y] != 1)
      workPath(x + 1, y, obstacleGrid);
    if (y < obstacleGrid[0].size() - 1 && obstacleGrid[x][y + 1] != 1)
      workPath(x, y + 1, obstacleGrid);
  }
};
