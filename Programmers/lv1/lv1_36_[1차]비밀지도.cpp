#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> converse(vector<int> arr, int n);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<string> maze1 = converse(arr1, n);
    vector<string> maze2 = converse(arr2, n);

    for (int i = 0; i < n; i++)
    {
        string str = "";
        string str1 = maze1[i];
        string str2 = maze2[i];

        for (int j = 0; j < n; j++)
        {
            if (str1[j] == '1' || str2[j] == '1')
                str += "#";
            else if (str1[j] == '0' && str2[j] == '0')
                str += " ";
        }

        answer.push_back(str);
    }

    return answer;
}

vector<string> converse(vector<int> arr, int n)
{
    vector<string> maze;

    for (int i = 0; i < arr.size(); i++)
    {
        string str = "";

        int num = arr[i];
        if (num != 0)
        {
            while (num != 1)
            {
                str += to_string(num % 2);
                num /= 2;
            }
            str += "1";
        }

        while (str.length() != n)
        {
            str += "0";
        }
        reverse(str.begin(), str.end());

        maze.push_back(str);
    }

    return maze;
}