#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int getBillionUsersDay(vector <float> growthRates) {
    float max_growth = *max_element(growthRates.begin(), growthRates.end());
    float lo = 0, hi = log(1e9) / log(max_growth);
    int n_iters = log2(hi) + 5;

    for (int iter = 0; iter < n_iters; iter++) {
        float t = (lo + hi) / 2;
        float sum = 0;
        for (float g : growthRates) {
            sum += pow(g, t);
        }

        if (sum < 1e9) {
            lo = t;
        } else {
            hi = t;
        }
    }

    return (int)ceil(lo);
}

