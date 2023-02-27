#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; participant.size(); i++)
    {
        if (participant[i] == completion[i])
            continue;
        else
            return participant[i];
    }
}