#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> id_name;
    vector<pair<string, string>> id_action;
    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string action, id, name;
        ss >> action >> id >> name;

        if (action == "Enter")
        {
            map<string, string>::iterator iter = id_name.find(id);
            if (iter == id_name.end())
                id_name.insert(make_pair(id, name));
            else
                iter->second = name;

            id_action.push_back(make_pair(id, action));
        }
        else if (action == "Leave")
            id_action.push_back(make_pair(id, action));
        else if (action == "Change")
        {
            map<string, string>::iterator iter = id_name.find(id);
            iter->second = name;
        }
    }

    for (int i = 0; i < id_action.size(); i++)
    {
        string id = id_action[i].first;
        string action = id_action[i].second;

        if (action == "Enter")
            action = "들어왔습니다.";
        else if (action == "Leave")
            action = "나갔습니다.";

        string name = id_name.find(id)->second;

        answer.push_back(name + "님이 " + action);
    }

    return answer;
}