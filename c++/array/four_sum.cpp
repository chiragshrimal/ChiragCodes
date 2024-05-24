#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n^4)
// space complexity is O(number of qurduent *2)




// better apporach like three sum better apporaach like two sum bette apporach
// time complexity is O(n^3)
// space complexity is O(n) + O(number of qurduent *2)




// optimal apporach 
// time complexity is o(n^3)
// space complexity is O(number of qurduent *2)
vector<vector<int>> three_sum_optimal(vector<int>& v, int index, long long int target) {
    int n = v.size();
    vector<vector<int>> s;
    for (int i = index; i < n; i++) {
        if(i!=index && v[i]==v[i-1]){// because we want unique quadruplets;
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            long long int sum = v[i] + v[j];
            sum+=v[k];
            if (sum == target) {
                vector<int> temp = {v[index - 1], v[i], v[j], v[k]};
                s.push_back(temp);
                int tempj = v[j];
                int tempk = v[k];
                j++;
                while (j < n && v[j] == tempj) {
                    j++;
                }
                k--;
                while (k >= 0 && v[k] == tempk) {
                    k--;
                }
            } else {
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
    }
    return s;
}

vector<vector<int>> four_sum_optimal(vector<int>& v, long long int target) {
    sort(v.begin(), v.end());
    int n = v.size();
    vector<vector<vector<int>>> ans;
    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i - 1]) {
            continue;
        }
        long long int k = target - v[i];
        ans.push_back(three_sum_optimal(v, i + 1, k));
    }
    vector<vector<int>> store;
    for (auto it : ans) {
        for(auto it2 : it){
            store.push_back(it2);
        }
    }
    return store;
}

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> optimal=four_sum_optimal(v,target);
     for(auto it : optimal){
        for(auto it2 :it ){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}