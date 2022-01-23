#include <bits/stdc++.h>

using namespace std;

vector<int> findMinArray(vector<int> arr, int k) {
    for (int i = 0; i < (int)arr.size() && k > 0; i++) {
        auto iter = min_element(arr.begin() + i, min(arr.end(), arr.begin() + i + k + 1));
        k -= iter - (arr.begin() + i);

        while (iter != arr.begin() + i) {
            iter_swap(iter, prev(iter));
            iter--;
        }
    }

    return arr;
}

