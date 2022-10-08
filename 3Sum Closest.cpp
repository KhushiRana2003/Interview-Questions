class Solution {
public:
// This is done by the approach by which calcualted the subarray with given and a similar question that i learned on gfg in that we have to find triplet.
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int close = 0;
        int mN = INT_MAX;
        // int sum;
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target){
                    return sum;
                }

                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }

                int diff = abs(sum-target);
                if(diff < mN){
                    mN = diff;
                    close = sum;
                }
            }
        }

        return close;

    }
};
