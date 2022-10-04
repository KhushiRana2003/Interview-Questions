# include <bits/stdc++.h>
using namespace std;

void subarrayWithGivenSum(vector<int> nums, int target, int n){
    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    
    while(j < n && sum+nums[j] <= target){
        sum += nums[j];
        j++;
    }

    if(sum == target){
        cout<< i+1 <<endl;
        cout<<j<<endl;
    }

    while(j < n){
        sum += nums[j];
        while(sum > target){
            sum -= nums[j];
            i++;
        }
        if(sum == target){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en<<endl;
}

int main(){
    int n;
    cin>>n;

    int sum = 0;
    cin>>sum;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    subarrayWithGivenSum(nums, sum, n);
    return 0;
}
