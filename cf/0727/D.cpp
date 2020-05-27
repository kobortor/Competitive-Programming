#include<bits/stdc++.h>

// Created by kobortor On 15:10:13 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[6];

int name_to_int(string s) {
    if (s == "S") return 0;
    if (s == "M") return 1;
    if (s == "L") return 2;
    if (s == "XL") return 3;
    if (s == "XXL") return 4;
    if (s == "XXXL") return 5;
    return -1;
}

string names[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int &i : cnt) cin >> i;

    int n;
    cin >> n;

    vector<int> soln(n);

    vector<pii> twos;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find(',') == string::npos) {
            int idx = name_to_int(s);
            cnt[idx]--;
            if (cnt[idx] < 0) {
                cout << "NO";
                return 0;
            }
            soln[i] = idx;
        } else {
            int idx = s.find(',');
            twos.push_back({name_to_int(s.substr(0, idx)), i});
        }
    }

    sort(allof(twos));
    reverse(allof(twos));

    for (int i = 0; i < 6; i++) {
        while (cnt[i] && !twos.empty()) {
            if (twos.back().first == i || twos.back().first == i - 1) {
                soln[twos.back().second] = i;
                twos.pop_back();
                cnt[i]--;
            } else {
                break;
            }
        }
    }

    if (!twos.empty()) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i : soln) {
            cout << names[i] << "\n";
        }
    }
}
