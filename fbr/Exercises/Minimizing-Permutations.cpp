#include <bits/stdc++.h>

using namespace std;

int minOperations(vector <int> arr) {
    int ans = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        auto iter = find(arr.begin() + i, arr.end(), i + 1);
        if (iter != arr.begin() + i) {
            ans++;
            reverse(arr.begin() + i, next(iter));
        }
    }

    return ans;
}
