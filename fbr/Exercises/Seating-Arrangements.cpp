#include <bits/stdc++.h>

using namespace std;

int minOverallAwkwardness(vector <int> arr) {
    sort(arr.begin(), arr.end());
    int answer = arr[1] - arr[0];
    for (int i = 2; i < (int)arr.size(); i++) {
        answer = max(answer, arr[i] - arr[i - 2]);
    }

    return answer;
}
