#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {

    vector<int> tokens;

    stringstream ss(s);
    string token;

    while (ss >> token)
    {
        tokens.push_back(stoi(token));
    }

    int max = *max_element(tokens.begin(), tokens.end());
    int min = *min_element(tokens.begin(), tokens.end());

    return to_string(min) + " " + to_string(max);
}