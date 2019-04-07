#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int white = 0;
const int black = 1;
const int off = 0;
const int def = 1;

string player[2][2];
queue<string> wait;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    cin >> player[white][off];
    cin >> player[black][off];
    cin >> player[white][def];
    cin >> player[black][def];
    for (int a = 4; a < N; a++) {
        string s;
        cin >> s;
        wait.push(s);
    }

    string res;
    cin >> res;

    vector<pair<int, pair<string, string>>> soln;
    bool lost[2] = {false, false};

    for (int a = 0; a < (int)res.size(); a++) {
        int tp = res[a] == 'W' ? 0 : 1;
        lost[!tp] = true;

        int b = a;
        while (b + 1 < (int)res.size() && res[b + 1] == res[a]) {
            b++;
        }

        int len = b - a + 1;
        if (lost[tp]) {
            soln.push_back({len, {player[tp][def], player[tp][off]}});
        } else {
            soln.push_back({len, {player[tp][off], player[tp][def]}});
        }
        for (int i = 0; i < len; i++) {
            swap(player[tp][off], player[tp][def]);
            swap(player[!tp][off], player[!tp][def]);
            wait.push(player[!tp][off]);
            player[!tp][off] = wait.front();
            wait.pop();
        }

        a = b;
    }

    int best = 0;
    for (auto au : soln) {
        best = max(best, au.first);
    }
    for (auto au : soln) {
        if (au.first == best) {
            cout << au.second.first << " " << au.second.second << endl;
        }
    }
}
