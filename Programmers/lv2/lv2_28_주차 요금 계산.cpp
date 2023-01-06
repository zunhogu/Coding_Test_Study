#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2) { return p1.first < p2.first; }

int find(vector<pair<string, int>> list, string str)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].first == str)
            return i;
    }

    return list.end() - list.begin();
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    vector<pair<string, int>> inTime;
    vector<pair<string, int>> outTime;

    vector<pair<string, int>> accuTimes;

    for (int i = 0; i < records.size(); i++)
    {
        stringstream ss(records[i]);
        string time, carNum, action;

        ss >> time;
        ss >> carNum;
        ss >> action;

        string t = "";
        t += time[0];
        t += time[1];
        t += time[3];
        t += time[4];

        if (action == "IN")
            inTime.push_back(make_pair(carNum, stoi(t)));
        if (action == "OUT")
            outTime.push_back(make_pair(carNum, stoi(t)));
    }

    for (int i = 0; i < inTime.size(); i++)
    {
        int time = 0;

        int index = find(outTime, inTime[i].first);
        if (index != outTime.end() - outTime.begin())
        {
            int in = (inTime[i].second / 100) * 60 + (inTime[i].second % 100);
            int out = (outTime[index].second / 100) * 60 + (outTime[index].second % 100);

            time += out - in;

            outTime.erase(outTime.begin() + index);
        }
        else
        {
            int in = (inTime[i].second / 100) * 60 + (inTime[i].second % 100);
            int t = 2359 - inTime[i].second;
            int hour = t / 100;
            int minute = t % 100;

            time += (hour * 60 + minute);
        }

        index = find(accuTimes, inTime[i].first);
        if (index != accuTimes.end() - accuTimes.begin())
            accuTimes[index].second += time;
        else
            accuTimes.push_back(make_pair(inTime[i].first, time));
    }

    sort(accuTimes.begin(), accuTimes.end(), compare);

    for (int i = 0; i < accuTimes.size(); i++)
    {
        float a = (float)(accuTimes[i].second - fees[0]) / (float)fees[2];
        if (a < 0.0f) a = 0.0f;
        int price = fees[1] + ceil(a) * fees[3];
        answer.push_back(price);
    }

    return answer;
}