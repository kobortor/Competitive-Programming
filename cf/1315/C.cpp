#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// remain should be sorted
bool solvable(vector<int> b, vector<int> remain) {
    sort(allof(b));
    reverse(allof(b));

    int cnt = 0;
    for (int bi : b) {
        cnt--;
        while (!remain.empty() && remain.back() > bi) {
            remain.pop_back();
            cnt++;
        }

        if (cnt < 0) {
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> remain(2 * n);
        for (int i = 1; i <= 2 * n; i++) {
            remain[i - 1] = i;
        }

        bool solved = true;

        vector<int> b(n);
        for (int &bi : b) {
            cin >> bi;

            auto iter = find(allof(remain), bi);
            if (iter == remain.end()) {
                solved = false;
            } else {
                remain.erase(iter);
            }
        }

        if (!solved) {
            cout << "-1\n";
            continue;
        }

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            int start = upper_bound(allof(remain), b[i]) - remain.begin();
            for (int j = start; j < (int)remain.size(); j++) {
                int val = remain[j];
                remain.erase(remain.begin() + j);

                vector<int> nb(b.begin() + i + 1, b.end());
                if (solvable(nb, remain)) {
                    answer.push_back(b[i]);
                    answer.push_back(val);
                    // use this!
                    break;
                } else {
                    remain.insert(remain.begin() + j, val);
                }
            }
            if ((int)remain.size() + i == n) {
                solved = false;
                break;
            }
        }

        if (solved) {
            for (int i : answer) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << "-1\n";
        }
    }
}
