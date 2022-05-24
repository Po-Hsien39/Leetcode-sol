#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  int parenNum;
  vector<string> parenthesis;

public:
  vector<string> generateParenthesis(int n)
  {
    this->parenNum = n;
    getParenthesis(0, 0, "");
    return parenthesis;
  }
  void getParenthesis(int stock, int leftParenSum, string current)
  {
    if (current.size() == (this->parenNum * 2))
    {
      parenthesis.push_back(current);
      return;
    }
    if (leftParenSum < this->parenNum)
      getParenthesis(stock + 1, leftParenSum + 1, current + '(');
    if (stock > 0)
      getParenthesis(stock - 1, leftParenSum, current + ')');
  }
};