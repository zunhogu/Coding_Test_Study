#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int convolutionCount = 0;
    int removeZeroCount = 0;
    while (s != "1")
    {
        string removeZero = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                removeZero += '1';
            else
                removeZeroCount++;
        }
        int len = removeZero.length();

        s = "";
        while (len != 1)
        {
            s += to_string(len % 2);
            len = len / 2;
        }
        s += "1";

        reverse(s.begin(), s.end());
        convolutionCount++;
    }

    answer.push_back(convolutionCount);
    answer.push_back(removeZeroCount);

    return answer;
}