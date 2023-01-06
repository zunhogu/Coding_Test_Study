#include <iostream>
#include <cmath>
using namespace std;

long long solution(int w, int h) {
    long long answer = (long long)w * h;

    long long count = 0;
    for (long long i = 0; i < w; i++)
        count += (ceil(((double)h * (i + 1)) / w) - floor(((double)h * i) / w));

    return answer - count;
}