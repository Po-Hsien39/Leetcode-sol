// Using two queues to perform

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MyStack
{
private:
  queue<int> queue1;
  queue<int> queue2;

public:
  MyStack()
  {
  }

  void push(int x)
  {
    if (!queue1.empty())
      queue1.push(x);
    else
      queue2.push(x);
  }

  int pop()
  {
    int temp;
    if (!queue1.empty())
    {
      while (queue1.size() != 1)
      {
        temp = queue1.front();
        queue1.pop();
        queue2.push(temp);
      }
      int result = queue1.front();
      queue1.pop();
      return result;
    }
    else
    {
      while (queue2.size() != 1)
      {
        temp = queue2.front();
        queue2.pop();
        queue1.push(temp);
      }
      int result = queue2.front();
      queue2.pop();
      return result;
    }
  }

  int top()
  {
    if (queue1.empty())
      return queue2.back();
    else
      return queue1.back();
  }

  bool empty()
  {
    if (queue1.empty() && queue2.empty())
      return true;
    return false;
  }
};

int main()
{
  vector<int> vect{0, 1, 2, 3};
  cout << vect[0];
  return 0;
}