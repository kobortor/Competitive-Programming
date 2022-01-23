#include <bits/stdc++.h>

using namespace std;

vector <int> findSignatureCounts(vector <int> arr) {
    vector<int> answer(arr.size());

    for (int i = 0; i < (int)arr.size(); i++) {
        if (answer[i] != 0) {
            continue;
        }

        int cnt = 0;
        int j = i;
        do {
            j = arr[j] - 1;
            cnt++;
        } while (i != j);

        do {
            j = arr[j] - 1;
            answer[j] = cnt;
        } while (i != j);
    }

    return answer;
}

