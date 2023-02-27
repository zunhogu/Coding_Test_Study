#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> poketmons;

    for (int i = 0; i < nums.size(); i++)
        poketmons.insert(nums[i]);

    return poketmons.size() > nums.size() / 2 ? nums.size() / 2 : poketmons.size();

}