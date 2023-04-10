#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string input;
        cin>>input;
        
        regex pattern("(100+1+|01)+");
        cout<< (regex_match(input, pattern) ? "YES\n" : "NO\n");
    }
}   