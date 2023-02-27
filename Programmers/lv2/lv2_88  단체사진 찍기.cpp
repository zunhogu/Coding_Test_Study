#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    sort(friends.begin(), friends.end());

    do
    {
        bool check = true;
        for (int i = 0; i < data.size(); i++)
        {
            int first_idx = friends.find(data[i][0]);
            int second_idx = friends.find(data[i][2]);
            char oper = data[i][3];
            int dist = data[i][4] - 48;
            int diff = abs(first_idx - second_idx) - 1;
            switch (oper)
            {
            case '=':
                if (diff != dist) check = false;
                break;
            case '>':
                if (diff <= dist) check = false;
                break;
            case '<':
                if (diff >= dist) check = false;
                break;
            }
            if (!check) break;
        }
        if (check) answer++;
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}