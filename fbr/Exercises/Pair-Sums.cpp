#include <bits/stdc++.h>

using namespace std;

int numberOfWays(vector<int>& arr, int k) {
    unordered_map<int, int> ump;
    int answer = 0;

    for (int i : arr) {
        answer += ump[k - i];
        ump[i]++;
    }

    return answer;
}
