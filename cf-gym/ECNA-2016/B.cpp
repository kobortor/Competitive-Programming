#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    queue<string> q;

    string wo, bo, wd, bd;
    cin >> wo >> bo >> wd >> bd;

    for (int i = 4; i < n; i++) {
        string s;
        cin >> s;
        q.push(s);
    }

    string results;
    cin >> results;

    vector<pair<pair<string, string>, int>> dyns;

    pair<string, string> wteam = {wo, wd};
    pair<string, string> bteam = {bo, bd};

    int nxt = 4;
    for (char c : results) {
        if (c == 'W') {
            if (!dyns.empty() && dyns.back().first == wteam) {
                dyns.back().second++;
            } else {
                dyns.push_back({wteam, 1});
            }

            swap(wo, wd);

            q.push(bd);
            bd = bo;
            bo = q.front();
            q.pop();

            bteam = {bd, bo};
        } else {
            if (!dyns.empty() && dyns.back().first == bteam) {
                dyns.back().second++;
            } else {
                dyns.push_back({bteam, 1});
            }

            swap(bo, bd);

            q.push(wd);
            wd = wo;
            wo = q.front();
            q.pop();

            wteam = {wd, wo};
        }
    }

    int longest = 0;
    for (auto &au : dyns) {
        longest = max(longest, au.second);
    }
    for (auto &au : dyns) {
        if (au.second == longest) {
            cout << au.first.first << " " << au.first.second << "\n";
        }
    }
}