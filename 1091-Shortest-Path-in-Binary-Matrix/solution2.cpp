// Using BFS Algorithm to solve the problem

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
  int x;
  int y;
};

class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    if (grid[0][0] == 1)
      return -1;
    queue<Node> pos;
    Node startPoint = {0, 0};
    grid[0][0] = 1;
    pos.push(startPoint);
    while (pos.size())
    {
      Node target = pos.front();
      pos.pop();
      int pathCount = grid[target.x][target.y];
      if (target.x == grid.size() - 1 && target.y == grid.size() - 1)
        break;
      if (target.x > 0)
      {
        if (grid[target.x - 1][target.y] == 0)
        {
          grid[target.x - 1][target.y] = pathCount + 1;
          Node newPoint = {target.x - 1, target.y};
          pos.push(newPoint);
        }
        if (target.y > 0 && grid[target.x - 1][target.y - 1] == 0)
        {
          grid[target.x - 1][target.y - 1] = pathCount + 1;
          Node newPoint = {target.x - 1, target.y - 1};
          pos.push(newPoint);
        }
        if (target.y < grid.size() - 1 && grid[target.x - 1][target.y + 1] == 0)
        {
          grid[target.x - 1][target.y + 1] = pathCount + 1;
          Node newPoint = {target.x - 1, target.y + 1};
          pos.push(newPoint);
        }
      }
      if (target.x < grid.size() - 1)
      {
        if (grid[target.x + 1][target.y] == 0)
        {
          grid[target.x + 1][target.y] = pathCount + 1;
          Node newPoint = {target.x + 1, target.y};
          pos.push(newPoint);
        }
        if (target.y > 0 && grid[target.x + 1][target.y - 1] == 0)
        {
          grid[target.x + 1][target.y - 1] = pathCount + 1;
          Node newPoint = {target.x + 1, target.y - 1};
          pos.push(newPoint);
        }
        if (target.y < grid.size() - 1 && grid[target.x + 1][target.y + 1] == 0)
        {
          grid[target.x + 1][target.y + 1] = pathCount + 1;
          Node newPoint = {target.x + 1, target.y + 1};
          pos.push(newPoint);
        }
      }
      if (target.y > 0 && grid[target.x][target.y - 1] == 0)
      {
        grid[target.x][target.y - 1] = pathCount + 1;
        Node newPoint = {target.x, target.y - 1};
        pos.push(newPoint);
      }
      if (target.y < grid.size() - 1 && grid[target.x][target.y + 1] == 0)
      {
        grid[target.x][target.y + 1] = pathCount + 1;
        Node newPoint = {target.x, target.y + 1};
        pos.push(newPoint);
      }
    }
    if (grid[grid.size() - 1][grid.size() - 1] == 0 || grid[grid.size() - 1][grid.size() - 1] == 1)
      return -1;
    return grid[grid.size() - 1][grid.size() - 1];
  }
};