#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    vector<pair<int, int>> reportLog;
    vector<pair<int, int>> reportedLog;

    for (int i = 0; i < id_list.size(); i++)
    {
        answer.push_back(0);
        reportedLog.push_back(make_pair(i, 0));
    }


    set<string> reportSet;

    for (int i = 0; i < report.size(); i++)
        reportSet.insert(report[i]);

    for (set<string>::iterator iter = reportSet.begin(); iter != reportSet.end(); iter++)
    {
        stringstream ss(*iter);

        string reporter;
        string reported;

        ss >> reporter;
        ss >> reported;

        int reportIndex = find(id_list.begin(), id_list.end(), reporter) - id_list.begin();
        int reportedIndex = find(id_list.begin(), id_list.end(), reported) - id_list.begin();
        reportLog.push_back(make_pair(reportIndex, reportedIndex));

        reportedLog[reportedIndex].second++;
    }


    for (int i = 0; i < reportedLog.size(); i++)
    {
        if (reportedLog[i].second >= k)
        {
            for (int j = 0; j < reportLog.size(); j++)
            {
                if (reportLog[j].second == reportedLog[i].first)
                {
                    answer[reportLog[j].first]++;
                }
            }
        }
    }


    return answer;
}