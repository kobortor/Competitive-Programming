#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        vector<pair<char, int>> v;
        for (char c : s) {
            if (v.empty() || v.back().first != c) {
                v.push_back({c, 1});
            } else {
                v.back().second++;
            }
        }

        cout << "Case #" << t << ": ";
        for (int i = 0; i < v.size(); i++) {
            cout << string(v[i].second, v[i].first);
            if (i + 1 != v.size() && v[i].first < v[i + 1].first) {
                cout << string(v[i].second, v[i].first);
            }
        }
        cout << "\n";
    }
}
