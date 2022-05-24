// DP solution

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<int>> routeTable;

public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    this->routeTable.resize(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
    routeTable[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] = 1;
    return getPaths(obstacleGrid, 0, 0);
  }
  int getPaths(vector<vector<int>> &obstacleGrid, int posX, int posY)
  {
    if (obstacleGrid[posX][posY] == 1)
      return 0;
    if (this->routeTable[posX][posY] != -1)
      return this->routeTable[posX][posY];
    int routeFromBottom = 0;
    int routeFromRight = 0;
    if (posX < obstacleGrid.size() - 1 && obstacleGrid[posX + 1][posY] != 1)
      routeFromBottom = getPaths(obstacleGrid, posX + 1, posY);
    if (posY < obstacleGrid[0].size() - 1 && obstacleGrid[posX][posY + 1] != 1)
      routeFromRight = getPaths(obstacleGrid, posX, posY + 1);
    this->routeTable[posX][posY] = routeFromBottom + routeFromRight;
    return this->routeTable[posX][posY];
  }
};