class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n,1);        //return array does not count as per description
        for(int i = n-2; i >= 0; --i){
            ret[i] = nums[i+1]*ret[i+1]; // making return array as suffix product array
        }
        int l = 1; // instead of using prefix array, for constant space
        for(int i = 0; i < n; ++i){
            ret[i] = l*ret[i]; // another way of saying ret[i] = pre[i]*suf[i]
            l *= nums[i];
        }
        return ret;
    }
};

// 2nd solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // step1: creating right array
        vector<int> right(nums.size());
        int prod = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            prod *= nums[i];
            right[i] = prod;
        }

        // step2 maintain left product

        prod = 1;

        vector<int> res(nums.size());
        for(int i =0; i < nums.size()-1; i++){
            int lp = prod;
            int rp = right[i+1];

            res[i] = lp*rp;
            prod *= nums[i];
        }
        res[nums.size()-1] = prod;
        return res;
    }
};
