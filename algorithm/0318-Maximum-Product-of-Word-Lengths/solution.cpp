#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    vector<unordered_map<char, bool>> wordsMap(words.size());
    for (int i = 0; i < words.size(); i++)
    {
      string target = words[i];
      for (int j = 0; j < target.length(); j++)
        wordsMap[i][target[j]] = true;
    }
    int maxMultiply = 0;
    vector<vector<int>> test;
    for (int i = 0; i < words.size(); i++)
    {
      for (int j = 0; j < i; j++)
      {
        bool duplicate = false;
        for (auto &element : wordsMap[i])
        {
          if (wordsMap[j].find(element.first) != wordsMap[j].end())
          {
            duplicate = true;
            break;
          }
        }
        if (!duplicate && (words[i].length() * words[j].length() > maxMultiply))
          maxMultiply = words[i].length() * words[j].length();
      }
    }
    return maxMultiply;
  }
};

int main()
{
  return 0;
}