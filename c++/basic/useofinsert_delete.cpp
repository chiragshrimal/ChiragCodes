#include <bits/stdc++.h>
using namespace std;
int main()
{
    string command;
    cin >> command;
    string str1 = "()";
    string str2 = "(al)";
    while (1)
    {
        int t=0;
        int y=0;
        int found = command.find(str1);
        if (found != std::string::npos)
        {
            command.erase(found, str1.length());
            command.insert(found, "o");
        }else{
            t=1;
        }
        int found2 = command.find(str2);
        if (found2 != std::string::npos)
        {
            command.erase(found2, str2.length());
            command.insert(found2, "al");
        }else{
            y=1;
        }
        if(t==1&&y==1){
            break;
        }
    }
    cout<<command;
}