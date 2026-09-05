class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int s = nums.size();
        vector<int>a1(s);
        vector<int>a2(s);
        
        int max =-1;
        for(int i=0;i<s;i++)    {
            if(nums[i]>max)   max = nums[i];
            a1[i] =max;
        }

        int min = INT_MAX;
        for(int i=s-1;i>=0;i--)    {
            if(nums[i]<min)    min = nums[i];
            a2[i] = min;
        }
        for(int i=0;i<s;i++)    {
            if((a1[i]-a2[i])<=k)    return i;
        }
        return -1;
    }
};