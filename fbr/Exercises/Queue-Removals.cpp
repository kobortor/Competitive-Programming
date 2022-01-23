#include <bits/stdc++.h>

using namespace std;

vector <int> findPositions(vector <int> arr, int x) {
    queue<pair<int, int>> q;
    vector<int> answer;

    for (int i = 0; i < (int)arr.size(); i++) {
        q.push(make_pair(arr[i], i + 1));
    }

    for (int iter = 0; iter < x; iter++) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < x && !q.empty(); i++) {
            tmp.push_back(q.front());
            q.pop();
        }

        int best_idx = 0;
        for (int i = 1; i < (int)tmp.size(); i++) {
            if (tmp[i].first > tmp[best_idx].first) {
                best_idx = i;
            }
        }

        answer.push_back(tmp[best_idx].second);
        tmp.erase(tmp.begin() + best_idx);

        for (auto [val, idx] : tmp) {
            q.push(make_pair(max(0, val - 1), idx));
        }
    }

    return answer;
}

