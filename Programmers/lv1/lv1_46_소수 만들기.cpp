#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (isPrime(nums[i] + nums[j] + nums[k]))
                    cnt++;
            }
        }
    }

    return cnt;
}