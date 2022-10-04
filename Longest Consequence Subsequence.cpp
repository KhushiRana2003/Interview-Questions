#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
// TLE error
// bool findNumber(int num, vector<int> &arr){
//     for(auto i : arr){
//         if(i == num)
//             return true;
//     }
//     return true;
// }
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
//     TLE error
//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         int start = arr[i];
//         while(findNumber(start, arr)){
//             start++;
//         }
//         ans = max(ans,start - arr[i]);
//     }
//     return ans;
//     sort(arr.begin(), arr.end());
//     int seqLen = 1;
//     int maxLen = 1;
//     for(int i = 1; i < arr.size(); i++){
//         if(arr[i] == arr[i-1]+1){
//             seqLen++;
//         }
//         else if(arr[i] == arr[i-1]) continue;
//         else{
            
//             seqLen = 1;
//             break;
//         }
//         maxLen = max(maxLen, seqLen);
//     }
//     return maxLen;
    
//     Third approach
    int ans = 1;
    unordered_set<int> st;
    for(int i = 0; i < arr.size(); i++){
        st.insert(arr[i]);
    }
    for(int i = 0; i < n; i++){
        int start = arr[i];
        if(st.find(start-1) != st.end()) continue;
        while(st.find(start) != st.end()){
            start++;
        }
        ans = max(ans, start-arr[i]);
    }
    return ans;
    
}
