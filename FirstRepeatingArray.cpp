#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    const int N = 1e6+2;

    vector<int> idx(n,-1);

    int minidx = INT_MAX;

    for(int i = 0; i < n; i++){
        if(idx[nums[i]] != -1){
            minidx = min(minidx, idx[nums[i]]);
        }
        else{
            idx[nums[i]] = i;
        }
    }
    
    if(minidx == INT_MAX){
        cout<<" -1 "<<endl;
    }

    else{
        cout<< minidx+1 <<endl;
    }

    return 0; 
}
