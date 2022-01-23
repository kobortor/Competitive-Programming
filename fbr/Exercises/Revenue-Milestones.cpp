#include <bits/stdc++.h>

using namespace std;

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
    vector<pair<int, int>> milestones_labelled;
    for (int i = 0; i < (int)milestones.size(); i++) {
        milestones_labelled.push_back(make_pair(milestones[i], i));
    }

    sort(milestones_labelled.begin(), milestones_labelled.end());

    vector<int> answer(milestones.size(), -1);

    int idx = 0;
    for (int i = 0, sum = 0; i < (int)revenues.size(); i++) {
        sum += revenues[i];
        while (idx < (int)milestones.size() && milestones_labelled[idx].first <= sum) {
            answer[milestones_labelled[idx++].second] = i + 1;
        }
    }

    return answer;
}

