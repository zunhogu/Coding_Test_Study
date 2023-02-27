#include <string>
#include <vector>
using namespace std;

bool find(vector<int> records, int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < records.size(); i += 4)
    {
        if (records[i] == x1 && records[i + 1] == y1 && records[i + 2] == x2 && records[i + 3] == y2)
            return true;
        else if (records[i] == x2 && records[i + 1] == y2 && records[i + 2] == x1 && records[i + 3] == y1)
            return true;
    }
    return false;
}

int solution(string dirs) {

    int x1 = 0;
    int y1 = 0;

    vector<int> records;

    for (int i = 0; i < dirs.length(); i++)
    {
        int x2 = x1;
        int y2 = y1;

        if (dirs[i] == 'U')
            y2++;
        else if (dirs[i] == 'D')
            y2--;
        else if (dirs[i] == 'R')
            x2++;
        else if (dirs[i] == 'L')
            x2--;

        if (x2 > 5 || x2 < -5 || y2 >5 || y2 < -5)
            continue;
        else
        {
            if (!find(records, x1, y1, x2, y2))
            {
                records.push_back(x1);
                records.push_back(y1);
                records.push_back(x2);
                records.push_back(y2);
            }

            x1 = x2;
            y1 = y2;
        }
    }

    return  records.size() / 4;
}