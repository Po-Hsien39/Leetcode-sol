#include <iostream>
#include <vector>

using namespace std;

class Solution
{

private:
  vector<vector<int>> adjacencyList;
  vector<vector<int>> adjacencyWeight;
  vector<int> currentSpendTime;
  int maximumTime;

public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    maximumTime = -1;
    for (int i = 0; i < n; i++)
    {
      vector<int> temp1;
      vector<int> temp2;
      this->currentSpendTime.push_back(INT_MAX);
      this->adjacencyList.push_back(temp1);
      this->adjacencyWeight.push_back(temp2);
    }
    for (int i = 0; i < times.size(); i++)
    {
      int from = times[i][0] - 1;
      int to = times[i][1] - 1;
      int weight = times[i][2];
      this->adjacencyList[from].push_back(to);
      this->adjacencyWeight[from].push_back(weight);
    }
    this->currentSpendTime[k - 1] = 0;
    goAdjacentNode(k - 1);

    for (int i = 0; i < n; i++)
      if (currentSpendTime[i] == INT_MAX)
        return -1;
      else if (currentSpendTime[i] >= maximumTime)
        maximumTime = currentSpendTime[i];
    return maximumTime;

    return 0;
  }

  void goAdjacentNode(int target)
  {
    for (int i = 0; i < this->adjacencyList[target].size(); i++)
    {
      int to = this->adjacencyList[target][i];
      int weight = this->adjacencyWeight[target][i];
      int currentWeight = this->currentSpendTime[target];
      if (currentWeight + weight < currentSpendTime[to])
      {
        currentSpendTime[to] = currentWeight + weight;
        goAdjacentNode(to);
      }
    }
  }
};
