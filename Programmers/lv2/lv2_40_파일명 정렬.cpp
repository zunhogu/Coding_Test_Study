#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void getToken(string str, string& head, int& number)
{
    string str_head = "";
    string str_number = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            str_head += str[i];
        else
        {
            int j = i;
            while (isdigit(str[j]))
            {
                str_number += str[j];
                j++;
            }
            break;
        }
    }

    head = str_head;
    number = stoi(str_number);
}

bool compare(string str1, string str2)
{
    string str1_head = "";
    int str1_number;
    string str2_head = "";
    int str2_number;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    getToken(str1, str1_head, str1_number);
    getToken(str2, str2_head, str2_number);

    if (str1_head < str2_head)
        return true;
    else if (str1_head == str2_head)
    {
        if (str1_number < str2_number)
            return true;
        else
            return false;
    }
    else
        return false;
}

vector<string> solution(vector<string> files) {

    stable_sort(files.begin(), files.end(), compare);

    return files;
}