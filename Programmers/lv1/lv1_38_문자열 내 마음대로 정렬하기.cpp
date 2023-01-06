#include <string>
#include <vector>
#include <algorithm>

#define SWAP(a, b, type) { type tmp; tmp = a; a = b; b = tmp;}

using namespace std;

vector<string> solution(vector<string> strings, int n) {

    for (int i = 0; i < strings.size(); i++)
    {
        for (int j = i; j < strings.size(); j++)
        {
            if (strings[i][n] > strings[j][n])
            {
                SWAP(strings[i], strings[j], string);
            }
            else if (strings[i][n] == strings[j][n])
            {
                if (strings[i].compare(strings[j]) > 0)
                    SWAP(strings[i], strings[j], string);
            }
        }
    }

    return strings;
}
