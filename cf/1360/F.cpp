#include<bits/stdc++.h>

// Created by kobortor On 14:57:55 on 27-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<pair<char, int>> bits[10];

string answer;

bool recur(int idx, int bitmask) {
    if (idx == m) {
        return true;
    }

    for (pair<char, int> p : bits[idx]) {
        if (!(p.second & bitmask)) {
            answer += p.first;
            if (recur(idx + 1, bitmask | p.second)) {
                return true;
            }
            answer.pop_back();
        }
    }

    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        vector<string> v(n);
        for (string &s : v) cin >> s;

        for (int j = 0; j < m; j++) {
            bits[j].clear();
            map<char, int> mp;
            for (int i = 0; i < n; i++) {
                mp[v[i][j]] |= 1 << i;
            }

            for (pair<char, int> au : mp) {
                bits[j].push_back({au.first, ((1 << n) - 1) ^ au.second});
            }
        }

        if (recur(0, 0)) {
            cout << answer << "\n";
            answer.clear();
        } else {
            cout << "-1\n";
        }
    }
}
