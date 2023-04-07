#include <iostream>
#include <string>

using namespace std;

bool find(string str)
{
    int index = 0;
    while(index < str.size())
    {
        if(str[index] == 0)
        {
            if(str[index+1] != 0) return false;
            else if(str[index+1] == 1) index++;
        }
        else if(str[index] == 1)
        {
            if(str[index+1] == 0) return false;
        }

        index++;
    }
    str.find("01", 0);
    
    return true;
}


//(100+1+ | 01)+
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string input;
        cin>>input;
        cout<<find(input)<<endl;
    }
}   