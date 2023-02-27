#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        string mySkill = "";
        bool success = true;
        for (int j = 0; j < skill_trees[i].length(); j++)
        {
            int index = skill.find(skill_trees[i][j]);
            if (index == -1)
                mySkill += skill_trees[i][j];
            else
            {
                string prevSkill = skill.substr(0, index);
                for (int k = 0; k < prevSkill.length(); k++)
                {
                    if (mySkill.find(prevSkill[k]) == -1)
                        success = false;
                }

                if (success)
                    mySkill += skill_trees[i][j];
                else
                    break;
            }
        }
        if (success) answer++;
    }

    return answer;
}