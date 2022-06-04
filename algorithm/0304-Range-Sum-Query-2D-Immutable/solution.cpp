#include <iostream>
#include <vector>

using namespace std;

class NumMatrix
{
private:
  vector<vector<int>> recordList;

public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    this->recordList.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
    for (int i = 0; i < matrix.size(); i++)
      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (i == 0 && j == 0)
          this->recordList[i + 1][j + 1] = matrix[i][j];
        else if (i == 0)
          this->recordList[i + 1][j + 1] = this->recordList[i + 1][j] + matrix[i][j];
        else if (j == 0)
          this->recordList[i + 1][j + 1] = this->recordList[i][j + 1] + matrix[i][j];
        else
          this->recordList[i + 1][j + 1] = this->recordList[i][j + 1] + this->recordList[i + 1][j] - this->recordList[i][j] + matrix[i][j];
      }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return this->recordList[row2 + 1][col2 + 1] - this->recordList[row2 + 1][col1] - this->recordList[row1][col2 + 1] + this->recordList[row1][col1];
  }
};
