# include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int> nums){
    const int N = 1e6+2;
    // int x = nums.size();
    vector<bool> check(N,false);

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= 0){
            check[nums[i]] = true;
        }
    }
    int ans = -1;
    for(int i = 0; i < N; i++){
        if(check[i] == false){
            ans = i;
            break; 
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    cout<<MissingNumber(nums);

    return 0;
}
