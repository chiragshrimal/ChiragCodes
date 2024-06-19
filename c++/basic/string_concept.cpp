#include<bits/stdc++.h>
using namespace std;
int main (){
    string  str="hello";
    string str2="world";
    if(str==str2){//comparision of strings 
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    cout<<endl;

    string str3;
    str3=str+str2;//concatination of strings 
    cout<<str3;
    cout<<endl;

    string str4;
    getline(cin,str4);//input of string cin space, /n k bad ki string ko consider nhi krta
    cout<<str4<<endl;
    //if u want to take input more no of lines ****
    int t;
    cin>>t;
    cin.ignore();
    while(t--){//pointer ka game hai 
        string s;
        getline(cin,s);
        cout<<s<<endl;
    }
    //remove an character from string 
    std::string str5 = "Hello, World!";
    int indexToRemove = 7;

    if (indexToRemove >= 0 && indexToRemove < str5.length()) {
        str5.erase(indexToRemove, 1);
        std::cout << "Modified String: " << str5 << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }

    //reverse the string 
    string str_rev;
    int k=0;
    for(int i=str4.size()-1;i>=0;i--){
        //str_rev=str_rev+str4[i];    //shi nhi hai wese
        str_rev.push_back(str4[i]);
    }
    cout<<str_rev<<endl;
    //chheck pelindrom 
    if(str4==str_rev){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    int i=0;
    int j=str4.size()-1;
    while(i<=j){
        if(str[i]!=str[j]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

}