#include <bits/stdc++.h>

using namespace std;

vector <int> findMaxProduct(vector <int> arr) {
    vector<int> answer(arr.size());
    array<int, 3> best = {0, 0, 0};

    for (int i = 0; i < (int)arr.size(); i++) {
        auto iter = min_element(best.begin(), best.end());
        *iter = max(*iter, arr[i]);

        if (i < 2) {
            answer[i] = -1;
        } else {
            answer[i] = best[0] * best[1] * best[2];
        }
    }

    return answer;
}

