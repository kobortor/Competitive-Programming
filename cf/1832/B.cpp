#include<bits/stdc++.h>

// Created by kobortor On 10:48:38 on 26-05-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        deque<int> dq(n);
        for (int &xi : dq) cin >> xi;

        sort(allof(dq));

        ll tmp = accumulate(dq.end() - k, dq.end(), 0ll);
        ll best = tmp;
        for (int i = 0; i < k; i++) {
            tmp += dq[i * 2];
            tmp += dq[i * 2 + 1];
            tmp -= dq[dq.size() - k + i];
            best = min(best, tmp);
        }
        cout << accumulate(allof(dq), 0ll) - best << "\n";
    }
}
