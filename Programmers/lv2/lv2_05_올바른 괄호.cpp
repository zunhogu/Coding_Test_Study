#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    vector<char> opers;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            bool flag = false;
            for (int j = opers.size() - 1; j >= 0; j--)
            {
                if (opers[j] == '(')
                {
                    opers.pop_back();
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return false;
        }
        else if (s[i] == '(')
            opers.push_back(s[i]);
    }

    if (opers.size() == 0)
        return true;
    else
        return false;
}