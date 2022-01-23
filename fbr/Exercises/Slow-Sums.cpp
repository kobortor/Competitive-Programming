#include <bits/stdc++.h>

using namespace std;

int getTotalTime(vector<int> arr) {
    priority_queue<int> pq(arr.begin(), arr.end());
    int answer = 0;

    while (pq.size() > 1) {
        int x1 = pq.top(); pq.pop();
        int x2 = pq.top(); pq.pop();

        answer += x1 + x2;
        pq.push(x1 + x2);
    }

    return answer;
}

