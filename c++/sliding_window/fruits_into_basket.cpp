#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n^3)
// space complexity is O(1);

int maximum_fruit_brute(vector<int>& v){
    int n=v.size();
    int maxlength=0;
    for(int i=0;i<n;i++){
        int element1=v[i];
        int element2;
        int j=i;
        for(;j<n;j++){
            if(v[j]!=element1){
                element2=v[j];
                break;
            }
        }
        for(int k=j-1;k<n;k++){
            if(element1==v[k] || element2==v[k]){
                maxlength=max(maxlength,k-i+1);
            }else{
                break;
            }
        }
    }
    return maxlength;
}
// better apporach (good concept)
// time copmplexity is O(n^2)
// space complxity is O(3);

int maximum_fruit_better(vector<int>& v){
    int n=v.size();
    int maxlength=0;
    for(int i=0;i<n;i++){
        set<int> s;
        for(int j=i;j<n;j++){
            s.insert(v[j]);
            if(s.size()<=2){
                maxlength=max(maxlength,j-i+1);
            }else{
                break;
            }
        }
    }
    return maxlength;
}


// optimal apporach 2 using map data structure
// time complexity is O(2*n)
// space complexity is O(3)
int maximum_fruit_optimal2(vector<int>& v){
    int n=v.size();
    unordered_map<int,int> m;
    int maxlength=0;
    int i=0;
    int j=0;
    while(j<n){
        m[v[j]]++;
        if(m.size()<=2){
            maxlength=max(maxlength,j-i+1);
        }else{
            while(m.size()>2){
                m[v[i]]--;
                if(m[v[i]]==0){
                    m.erase(v[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxlength;
}

// optimal apporach but time 
// time complexity is O(2*n);
// space complexity is O(1);
int maximum_fruit_optimal(vector<int>& v){
   int n=v.size();
    int i=0;
    int j=0;
    int maxlength=0;
    int element1=v[0];
    int element2;
    for(int k=0;k<n;k++){
        if(v[k]!=v[0]){
            j=k;
            break;
        }
    }
    if(j==0){
        return n-1;
    }else{
        element2=v[j];
    }
   
    while(j<n){
        int k=j;
        k--;
        if(element1==v[j] || element2==v[j]){
            maxlength=max(maxlength,j-i+1);
        }else{
            while(v[k-1]==v[k]){
                k--;
            }
            i=k;
            if(element1==v[i]){
                element2=v[j];
            }else{
                element1=v[j];
            }
        }
        j++;
    }
    return maxlength;
}

// optimal apporach 3 using map data structure
// time complexity is O(n)
// space complexity is O(3)
int maximum_fruit_optimal3(vector<int>& v){
    int n=v.size();
    unordered_map<int,int> m;
    int maxlength=0;
    int i=0;
    int j=0;
    while(j<n){
        m[v[j]]++;
        if(m.size()<=2){
            maxlength=max(maxlength,j-i+1);
        }else{
            if(m.size()>2){
                m[v[i]]--;
                if(m[v[i]]==0){
                    m.erase(v[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxlength;
}




int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=maximum_fruit_brute(v);
    cout<<brute<<endl;

    int better=maximum_fruit_better(v);
    cout<<better<<endl;

    int optimal=maximum_fruit_optimal(v);
    cout<<optimal<<endl;

    int optimal2=maximum_fruit_optimal2(v);
    cout<<optimal2<<endl;
    
    int optimal3=maximum_fruit_optimal(v);
    cout<<optimal3<<endl;
}