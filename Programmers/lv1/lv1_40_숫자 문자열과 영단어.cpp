#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        string temp = "";
        if (isdigit(s[i]))
            result += s[i];
        else
        {
            int cnt = i;
            while (!isdigit(s[cnt]))
            {
                temp += s[cnt];

                if (temp == "zero")
                {
                    result += "0";
                    break;
                }
                else if (temp == "one")
                {
                    result += "1";
                    break;
                }
                else if (temp == "two")
                {
                    result += "2";
                    break;
                }
                else if (temp == "three")
                {
                    result += "3";
                    break;
                }
                else if (temp == "four")
                {
                    result += "4";
                    break;
                }
                else if (temp == "five")
                {
                    result += "5";
                    break;
                }
                else if (temp == "six")
                {
                    result += "6";
                    break;
                }
                else if (temp == "seven")
                {
                    result += "7";
                    break;
                }
                else if (temp == "eight")
                {
                    result += "8";
                    break;
                }
                else if (temp == "nine")
                {
                    result += "9";
                    break;
                }

                cnt++;
            }

        }
    }

    return stoi(result);
}