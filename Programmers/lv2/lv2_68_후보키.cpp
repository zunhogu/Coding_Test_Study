#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int count(vector<string>& list, vector<vector<string>>& relation)
{
    vector<string> result;

    for (int i = 0; i < list.size(); i++)
    {
        bool tf = true;
        vector<string> data;
        for (int j = 0; j < relation.size(); j++)
        {
            string cols = "";
            string str = "";
            for (int k = 0; k < list[i].size(); k++)
            {
                cols += list[i][k];
                str += relation[j][list[i][k] - 48];
            }

            // 弥家己 眉农
            for (int m = 0; m < result.size(); m++)
            {
                if (result[m].length() < cols.length())
                {
                    bool tf2 = true;
                    for (int n = 0; n < result[m].length(); n++)
                    {
                        if (cols.find(result[m][n]) == -1)
                        {
                            tf2 = false;
                            break;
                        }
                    }
                    if (tf2) tf = false;
                }
            }

            // 蜡老己 眉农
            if (tf)
            {
                vector<string>::iterator iter = find(data.begin(), data.end(), str);
                if (iter != data.end())
                {
                    tf = false;
                    break;
                }
                else data.push_back(str);
            }
        }
        if (tf) result.push_back(list[i]);
    }

    return result.size();
}

int solution(vector<vector<string>> relation) {

    int C = relation[0].size();
    vector<string> list;
    vector<int> cols;

    for (int i = 0; i < C; i++)
        cols.push_back(i);

    for (int i = 0; i < (1 << C); i++)
    {
        string str = "";
        for (int j = 0; j < C; j++)
        {
            if (i & (1 << j))
                str += to_string(cols[j]);
        }
        list.push_back(str);
    }

    return count(list, relation);
}