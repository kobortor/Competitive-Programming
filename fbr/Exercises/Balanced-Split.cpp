#include<bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here


bool balancedSplitExists(vector<int>& arr){
    long sum = accumulate(arr.begin(), arr.end(), 0ll);

    sort(arr.begin(), arr.end());

    long prefix = 0;
    for (int i = 0; i + 1 < (int)arr.size(); i++) {
        prefix += arr[i];
        if (arr[i] < arr[i + 1] && prefix * 2 == sum) {
            return true;
        }
    }

    return false;
}
