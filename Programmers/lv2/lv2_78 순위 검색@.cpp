#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int count(map<string, vector<int>>& board, string str)
{
    int result = 0;

    string query_lang, query_group, query_career, query_food, query_score, dummy;
    stringstream ss(str);
    ss >> query_lang >> dummy >> query_group >> dummy >> query_career >> dummy >> query_food >> query_score;
    int score = stoi(query_score);
    string key = query_lang + query_group + query_career + query_food;

    map<string, vector<int>>::iterator iter = board.find(key);
    if (iter != board.end())
    {
        vector<int>::iterator low = lower_bound(iter->second.begin(), iter->second.end(), score);
        result += iter->second.size() - (low - iter->second.begin());
    }
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    map<string, vector<int>> board;

    for (int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]);
        string lang, group, career, food, score;
        ss >> lang >> group >> career >> food >> score;

        vector<string> tokens;
        tokens.push_back(lang);
        tokens.push_back(group);
        tokens.push_back(career);
        tokens.push_back(food);

        for (int j = 0; j < 1 << tokens.size(); j++)
        {
            string key = "";
            for (int k = 0; k < tokens.size(); k++)
            {
                if (j & 1 << k) key += tokens[k];
                else key += "-";
            }

            map<string, vector<int>>::iterator iter = board.find(key);
            if (iter == board.end())
            {
                vector<int> scores;
                scores.push_back(stoi(score));
                board.insert(make_pair(key, scores));
            }
            else iter->second.push_back(stoi(score));
        }
    }

    map<string, vector<int>>::iterator iter = board.begin();
    for (; iter != board.end(); iter++)
        sort(iter->second.begin(), iter->second.end());

    for (int i = 0; i < query.size(); i++)
        answer.push_back(count(board, query[i]));

    return answer;
}