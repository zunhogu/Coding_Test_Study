#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {

    string id = new_id;
    // phase 1 
    for (int i = 0; i < id.size(); i++)
    {
        if (isupper(id[i]))
            id[i] = tolower(id[i]);
    }

    // phase 2
    string str = "";
    for (int i = 0; i < id.size(); i++)
    {
        if (isalpha(id[i]) || isdigit(id[i]) || id[i] == '-' || id[i] == '_' || id[i] == '.')
        {
            str += id[i];
        }
    }
    id = str;

    // phase 3
    str = "";
    for (int i = 0; i < id.size(); i++)
    {
        if (!(id[i] == '.' && id[i + 1] == '.'))
            str += id[i];
    }
    id = str;

    // phase 4
    id = id[0] == '.' ? id.substr(1, id.size()) : id;
    id = id[id.size() - 1] == '.' ? id.substr(0, id.size() - 1) : id;


    // phase 5
    if (id == "")
    {
        id += 'a';
    }

    // phase 6 
    if (id.size() >= 16)
    {
        id = id.substr(0, 15);
        id = id[id.size() - 1] == '.' ? id.substr(0, id.size() - 1) : id;
    }

    // phase 7
    if (id.size() <= 2)
    {
        char last = id[id.size() - 1];
        while (id.size() != 3)
        {
            id += last;
        }
    }

    return id;
}