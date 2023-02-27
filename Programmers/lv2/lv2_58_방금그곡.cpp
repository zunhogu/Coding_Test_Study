#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int findString(vector<string>& melodyAll, vector<string>& melody)
{
    if (melodyAll.size() < melody.size()) return -1;

    for (int i = 0; i < melodyAll.size(); i++)
    {
        if (melodyAll[i] == melody[0])
        {
            bool find = true;
            for (int j = 0; j < melody.size(); j++)
            {
                if (melodyAll[i + j] != melody[j])
                {
                    find = false;
                    break;
                }
            }
            if (find) return i;
        }
    }

    return -1;
}

int getTimeInterval(string start, string end)
{
    string startHour, startMinute;
    string endHour, endMinute;

    stringstream ss1(start);
    stringstream ss2(end);

    getline(ss1, startHour, ':');
    getline(ss1, startMinute, ':');
    getline(ss2, endHour, ':');
    getline(ss2, endMinute, ':');

    return  (stoi(endHour) * 60 + stoi(endMinute)) - (stoi(startHour) * 60 + stoi(startMinute));
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    vector<string> mv;

    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == '#')
        {
            string top = mv.at(mv.size() - 1);
            mv.pop_back();
            top += "#";
            mv.push_back(top);
        }
        else
        {
            string str = "";
            str += m[i];
            mv.push_back(str);
        }
    }

    int maxPlay = -1;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        stringstream ss(musicinfos[i]);
        string startTime, endTime, title, melody;
        getline(ss, startTime, ',');
        getline(ss, endTime, ',');
        getline(ss, title, ',');
        getline(ss, melody, ',');

        int interVal = getTimeInterval(startTime, endTime);

        int cnt = 0;
        vector<string> melodyAll;
        while (melodyAll.size() != interVal)
        {
            int index = cnt % melody.size();

            string str = "";
            if (index != melodyAll.size() - 1 && melody[index + 1] == '#')
            {
                str += melody[index];
                str += "#";
                melodyAll.push_back(str);
                cnt++;
            }
            else
            {
                str += melody[index];
                melodyAll.push_back(str);
            }
            cnt++;
        }

        if (findString(melodyAll, mv) != -1)
        {
            if (answer == "")
            {
                answer = title;
                maxPlay = melodyAll.size();
            }
            else
            {
                if (maxPlay < melodyAll.size())
                {
                    answer = title;
                    maxPlay = melodyAll.size();
                }
            }
        }
    }

    return answer == "" ? "(None)" : answer;
}