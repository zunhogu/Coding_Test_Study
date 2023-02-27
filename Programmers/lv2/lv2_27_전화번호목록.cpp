#include <string>
#include <vector>
#include <set>
using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;

    set<string> tree;

    for (int i = 0; i < phone_book.size(); i++)
        tree.insert(phone_book[i]);

    for (set<string>::iterator iter1 = tree.begin(); iter1 != tree.end(); iter1++)
    {
        for (set<string>::iterator iter2 = iter1; iter2 != tree.end(); iter2++)
        {
            if (iter1 != iter2)
            {
                if (iter2->find(*iter1) == 0)
                    return false;
                else
                    break;
            }
        }
    }

    return true;
}