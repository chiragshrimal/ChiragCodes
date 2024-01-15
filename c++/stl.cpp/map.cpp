#include <bits/stdc++.h>
using namespace std;
void print(map<int, string> &m)
{ // by refrences ka use kro nhi toh time complexity o(n)
    cout << "size :" << m.size();
    for (auto &value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
}
int main()
{
    // normal map
    // inbuit implimentation of rad black tree
    // axsses or insert krne ki time complexity o(lon(n))
    map<int, string> m;
    m[1] = "chirag"; /////  o(log(n))
    m[3] = "shrimal";
    m[2] = "papa";
    m[9] = "mummy";
    // m[9]="palasha";// in the maps keys are unique
    m[6]; // o(lon(n))
    // input the maps
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        m[x] = s;
    }
    //insert the pair
    m.insert({2, "jak"}); // phle wali ko change nhi kr skta hai //o(log(n))

    //find operation 
    auto it1 = m.find(5); // o(log(n))
    if (it1 != m.end())
    {
        cout << (*it1).first;
    }
    else
    {
        cout << "invalid" << endl;
    }
    //erase operation
    //u can pass key 
    //or u can pass it
    //invalid it nhi hona chahiye
    if(it1!=m.end()){
    m.erase(it1);//o(log(n))
    }else{
        cout<<"invalid";
    }

    // print the maps
    map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    { // 1st methord
        cout << it->first << " " << it->second << endl;
    }
    for (auto value : m)
    { // 2nd methord
        cout << value.first << " " << value.second << endl;
    }
    print(m);
}