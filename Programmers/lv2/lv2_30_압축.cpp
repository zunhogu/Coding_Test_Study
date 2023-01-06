#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;

    for (int i = 65; i < 91; i++)
    {
        string s = "";
        s += (char)i;
        dic.insert(make_pair(s, i - 64));
    }

    while (msg != "")
    {
        // ÀÔ·Â °ª
        string s = "";
        int prevValue = 0;
        for (int j = 0; j < msg.length(); j++)
        {
            s += msg[j];
            map<string, int>::iterator iter = dic.find(s);
            if (iter != dic.end())
            {
                prevValue = iter->second;
                if (j == msg.length() - 1)
                {
                    answer.push_back(prevValue);
                    msg = "";
                }
                continue;
            }
            else
            {
                dic.insert(make_pair(s, dic.size() + 1));
                answer.push_back(prevValue);
                msg = msg.substr(j, msg.length());
                break;
            }
        }
    }


    return answer;
}