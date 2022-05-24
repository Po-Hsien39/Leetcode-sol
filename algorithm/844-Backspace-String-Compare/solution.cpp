#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "";
        string b = "";
        for (int i = 0; i < s.size(); i++)
        {
          if (s[i] != '#') a += s[i];
          else if (a.size() != 0) a.pop_back();
        }
        for (int i = 0; i < t.size(); i++)
        {
          if (t[i] != '#') b += t[i];
          else if (b.size() != 0) b.pop_back();
        }
        
        if (a.compare(b) == 0) return true;
        return false;

    }
};