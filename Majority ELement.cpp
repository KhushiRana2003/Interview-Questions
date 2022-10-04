#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
//     Approach 1: using map and counting frequency of element.
//     unordered_map<int,int> mp;
//     for(int i = 0; i < n; i++){
//         mp[arr[i]]++;
//         if(mp[arr[i]] > n/2)
//             return arr[i];
//     }
    
//     return -1;
    
    
//  Approach 2: Using sorting method;
//     sort(arr, arr+n);
//     int maj = arr[n/2]; //bcoz the middle element always comes in the range of the majority element;
//     int f = 0;
//     for(int i = 0; i < n; i++){
//         if(arr[i] == maj){
//             f++;
//         }
//     }
//     if(f > n/2){
//         return maj;
//     }
//     return -1;
    
//     Approach 3: Using Voting Algorithm
    int candidate = arr[0];
    int votes = 1;
    int f = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] == candidate){
            votes++;
        }
        else{
            votes--;
        }
        if(votes == 0){
            candidate = arr[i];
            votes = 1;
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == candidate)
            f++;
    }
    if(f > n/2){
        return candidate;
    }
    return -1;
}
