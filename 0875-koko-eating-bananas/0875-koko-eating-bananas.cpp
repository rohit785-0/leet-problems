#include <algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(l<=high) {
            int mid = l+(high-l)/2;
            int ans =0;
            for(auto x : piles) {
                ans += (x+mid-1)/mid;
                if(ans>h) break;
            }
            if(ans>h)   {
                l = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return l;
    }
};