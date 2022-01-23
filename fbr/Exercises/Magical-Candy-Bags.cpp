#include <bits/stdc++.h>

using namespace std;


int maxCandies(vector <int> arr, int k) {
    priority_queue<int> pq(arr.begin(), arr.end());

    int answer = 0;
    while (k--) {
        int top = pq.top();
        answer += top();

        pq.pop();
        pq.push(top / 2);
    }

    return answer;
}

