#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 25;

ll n, c;
ll fakeW[MAXN];
ll fakeSum = 0;
bool fakeB[MAXN];

int simulate() {
    ll newFakeSum;
    cin >> newFakeSum;
    return newFakeSum;

    int idx = rand() % n;
    if (fakeB[idx]) {
        fakeSum -= fakeW[idx];
    } else {
        fakeSum += fakeW[idx];
    }
    fakeB[idx] ^= 1;
    return fakeSum;
}

vector<ll> get_to_remove(vector<ll> ws, ll c) {
    ll best = -1;
    ll best_mask = 0;
    for (int i = 0; i < (1 << ws.size()); i++) {
        ll tot = 0;
        for (int j = 0; j < ws.size(); j++) {
            if (i & (1 << j)) {
                tot += ws[j];
            }
        }
        if (tot <= c && tot > best) {
            best = tot;
            best_mask = i;
        }
    }
    vector<ll> ans;
    for (int j = 0; j < ws.size(); j++) {
        if (best_mask & (1 << j)) {
            // keep
        } else {
            ans.push_back(ws[j]);
        }
    }
    return ans;
}

int main() {
    // cin.tie(0);
    // cin.sync_with_stdio(0);

    cin >> n >> c;

    /*
    for (int i = 0; i < n; i++) {
        cin >> fakeW[i];

        fakeB[i] = rand() % 2;
        // cin >> fakeB[i];

        if (fakeB[i]) {
            fakeSum += fakeW[i];
        }
    }    
    */

    ll prevB = simulate();
    cout << "accept" << endl;

    // reduce to 0
    while (prevB != 0) {
        ll B = simulate();
        if (B < prevB) {
            cout << "accept" << endl;
            prevB = B;
        } else {
            cout << "decline" << endl;
        }
    }

    vector<ll> foundW;
    vector<ll> to_remove;
    while (foundW.size() < n) {
        ll B = simulate();
        if (B > prevB) {
            foundW.push_back(B - prevB);
            prevB = B;

            if (foundW.size() == n) {
                to_remove = get_to_remove(foundW, c);
                if (to_remove.empty()) {
                    cout << "stop" << endl;
                    return 0;
                }
            }
            cout << "accept" << endl;
        } else {
            cout << "decline" << endl;
        }
    }

    while (!to_remove.empty()) {
        ll B = simulate();
        if (B < prevB) {
            auto iter = find(to_remove.begin(), to_remove.end(), prevB - B);
            if (iter != to_remove.end()) {
                to_remove.erase(iter);

                if (to_remove.empty()) {
                    cout << "stop" << endl;
                    return 0;
                }

                prevB = B;
                cout << "accept" << endl;
            } else {
                cout << "decline" << endl;
            }
        } else {
            cout << "decline" << endl;
        }
    }
}
