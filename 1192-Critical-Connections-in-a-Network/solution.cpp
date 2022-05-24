#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<int> low;
  vector<int> arrivedTime;
  vector<int> arrived;
  vector<vector<int>> result;
  vector<vector<int>> adjacency;
  int time;

public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
  {
    this->time = 0;
    for (int i = 0; i < n; i++)
    {
      vector<int> temp;
      this->adjacency.push_back(temp);
    }
    for (int i = 0; i < connections.size(); i++)
    {
      this->adjacency[connections[i][0]].push_back(connections[i][1]);
      this->adjacency[connections[i][1]].push_back(connections[i][0]);
    }

    this->arrived.assign(n, 0);
    this->arrivedTime.assign(n, -1);
    this->low.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
      if (!arrived[i])
        dfs(i, -1);
    }

    return result;
  }

  void dfs(int from, int prev)
  {
    this->time++;
    this->low[from] = this->time;
    this->arrivedTime[from] = this->time;
    for (int i = 0; i < this->adjacency[from].size(); i++)
    {
      int to = this->adjacency[from][i];
      if (prev == to)
        continue;
      if (arrived[to])
        this->low[from] = min(this->low[from], this->low[to]);
      else
      {
        arrived[to] = true;
        dfs(to, from);
        this->low[from] = min(this->low[from], this->low[to]);
        if (this->low[to] > this->arrivedTime[from])
        {
          vector<int> bridge{from, to};
          result.push_back(bridge);
        }
      }
    }
  }
};
