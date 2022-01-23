#include <bits/stdc++.h>

using namespace std;

vector <int> findMedian(vector <int> arr) {
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

    vector<int> answer(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        upper.push(arr[i]);

        while (upper.size() > lower.size()) {
            int top = upper.top();
            lower.push(top);
            upper.pop();
        }

        while (!lower.empty() && !upper.empty() && lower.top() > upper.top()) {
            int bot = lower.top();
            int top = upper.top();
            lower.pop();
            upper.pop();
            lower.push(top);
            upper.push(bot);
        }

        if (lower.size() > upper.size()) {
            answer[i] = lower.top();
        } else {
            answer[i] = (lower.top() + upper.top()) / 2;
        }
    }

    return answer;
}

