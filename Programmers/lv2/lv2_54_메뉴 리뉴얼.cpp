#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    map<string, int> counts;

    for (int i = 0; i < course.size(); i++)
    {
        for (int j = 0; j < orders.size(); j++)
        {
            vector<int> temp(orders[j].length(), 0);
            for (int k = 0; k < course[i]; k++)
            {
                if (k >= orders[j].length()) break;
                temp[k] = 1;
            }

            do
            {
                string menus = "";
                for (int k = 0; k < orders[j].length(); k++)
                {
                    if (temp[k] == 1)
                        menus += orders[j][k];
                }
                if (menus.length() < course[i]) continue;
                sort(menus.begin(), menus.end());

                map<string, int>::iterator iter = counts.find(menus);
                if (iter == counts.end())
                    counts.insert(make_pair(menus, 1));
                else
                    iter->second += 1;

            } while (prev_permutation(temp.begin(), temp.end()));
        }
    }


    for (int i = 0; i < course.size(); i++)
    {
        int maxCount = -1;

        for (map<string, int>::iterator iter = counts.begin(); iter != counts.end(); iter++)
        {
            if (iter->first.length() == course[i])
            {
                if (maxCount < iter->second)
                    maxCount = iter->second;
            }
        }
        for (map<string, int>::iterator iter = counts.begin(); iter != counts.end(); iter++)
        {
            if (iter->first.length() == course[i] && iter->second == maxCount && iter->second >= 2)
                answer.push_back(iter->first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}