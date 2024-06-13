#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if(n<38){
            cout<<"no"<<endl;
            continue;
        }else{
            n=n-4;
        }
        vector<int> high_primefactor(N, 0); // store high prime factor of ith element
        vector<int> low_primefactor(N, 0);  // store low prime factor of ith element
        vector<int> v(N, 1);                // let assume all numbers are prime
        v[1] = v[0] = 0;
        // sleves algorithm
        for (int i = 2; i < N; i++)
        { // time complexity is O(n*log(log(n)))
            if (v[i] == 1)
            {
                low_primefactor[i] = i;
                high_primefactor[i] = i;
                for (int j = i * 2; j < N; j += i)
                {
                    v[j] = 0;
                    if (low_primefactor[j] == 0)
                    {
                        low_primefactor[j] = i;
                    }
                    high_primefactor[j] = i;
                }
            }
        }

        int i = 0;
        while (v[i] != 1)
        {
            i++;
        }
        int j = n;
        while (v[j] != 1)
        {
            j--;
        }
        int sum = v[i] * v[i] + v[j] * v[j];
        while (i < j)
        {
            if (sum == n)
            {
                cout << "yes" << endl;
                break;
            }
            if (sum < n)
            {
                sum = sum - v[i]*v[i];
                i++;
                while (v[i] != 1)
                {
                    i++;
                }
                if (i < j)
                {
                    sum = sum + v[i]*v[i];
                }
                else
                {
                    cout << "no" << endl;
                    break;
                }
            }
            else
            {
                sum = sum - v[j]*v[j];
                j--;
                while (v[j] != 1)
                {
                    j--;
                }
                if (i < j)
                {
                    sum = sum + v[j]*v[j];
                }
                else
                {
                    cout << "no" << endl;
                    break;
                }
            }
        }
    }
}
