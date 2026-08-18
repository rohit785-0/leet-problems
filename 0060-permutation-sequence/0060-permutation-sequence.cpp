class Solution {
public:
    int update(vector<int>&arr, int k)  {
        int c =0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]==0)   c++;
            if(c==k+1)    {
                return i+1;
            }
        }
        return -1;
    }

    void solve(int n, int k,vector<int>&arr, string &s, vector<int>fac) {
        if(k==n && k<=1)    {
            return;
        }
        int r = update(arr,k/fac[n-1]);
        arr[r-1] = 1;
        s += to_string(r);
        solve(n-1,k%fac[n-1], arr,s,fac);

    }

    string getPermutation(int n, int k) {
        vector<int>fac;
        fac.push_back(1);
        int a = 1;
        for(int i=1;i<10;i++)    {
            a *= i;
            fac.push_back(a);
        }

        vector<int>arr(n,0);

        string s;
        solve(n,k-1,arr,s,fac);

        return s;
    }
};