#include <bits/stdc++.h>

using namespace std;

vector<int> helper(const vector<int> &arr) {
    vector<int> answer;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(-1, 1000000000));

    for (int i = 0; i < (int)arr.size(); i++) {
        while (pq.top().second < arr[i]) {
            pq.pop();
        }

        answer.push_back(i - pq.top().first);
        pq.push(make_pair(i, arr[i]));
    }

    return answer;
}

vector<int> CountSubarrays(vector <int> arr) {
    vector<int> v1 = helper(arr);
    reverse(arr.begin(), arr.end());

    vector<int> v2 = helper(arr);
    reverse(v2.begin(), v2.end());

    for (int i = 0; i < (int)v1.size(); i++) {
        v1[i] += v2[i] - 1;
    }

    return v1;
}
