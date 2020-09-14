#include<bits/stdc++.h>

// Created by kobortor On 02:14:08 on 14-09-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> a(n), b(n), cnt(n);
    for (ll &ai : a) cin >> ai;
    for (ll &bi : b) { 
        cin >> bi; 
        if (bi != -1) cnt[bi - 1]++; 
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!cnt[i]) q.push(i);
    }

    vector<int> order(n);
    vector<int> fwd, bck;

    ll ans = 0;
    while (!q.empty()) {
        int fr = q.front();
        q.pop();

        if (a[fr] > 0) {
            fwd.push_back(fr + 1);
            if (b[fr] != -1) {
                a[b[fr] - 1] += a[fr];
            }
        } else {
            bck.push_back(fr + 1);
        }
        
        if (b[fr] != -1 && --cnt[b[fr] - 1] == 0) {
            q.push(b[fr] - 1);
        }

        ans += a[fr];
    }

    cout << ans << "\n";

    for (int i : fwd) cout << i << " ";
    reverse(allof(bck));
    for (int i : bck) cout << i << " ";
}
