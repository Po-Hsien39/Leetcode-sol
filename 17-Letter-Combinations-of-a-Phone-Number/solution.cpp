#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{

private:
    vector<string> numbers;

public:
    Solution()
    {
        string numArr[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        numbers.assign(&numArr[0], &numArr[8]);
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> output;
        vector<string> phoneList;
        vector<int> repeatList;

        int outputLength;
        if (digits.size() == 0)
            outputLength = 0;
        else
            outputLength = 1;

        for (int i = 0; i < digits.size(); i++)
        {
            int phoneNum = digits[i] - '0';
            string character = this->numbers[phoneNum - 2];
            outputLength *= character.size();
            phoneList.push_back(character);
            if (i == 0)
                repeatList.push_back(1);
            else
                repeatList.push_back(repeatList[i - 1] * phoneList[i - 1].size());
        }

        for (int i = 0; i < outputLength; i++)
        {
            string target = "";
            for (int j = 0; j < digits.size(); j++)
            {
                string current = phoneList[j];
                int repeat = repeatList[j];
                int targetPosition = ceil((i % (current.size() * repeat)) / repeat);
                target += current[targetPosition];
            }
            output.push_back(target);
        }
        return output;
    }
};
