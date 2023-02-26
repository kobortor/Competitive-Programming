#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 5;

int n;
ll E[MAXN];
ll D[MAXN];
vector<int> g[MAXN];
int indeg[MAXN];
int tindeg[MAXN];
int L[MAXN];

int ok(int val) {

    for (int i = 1; i <= n; i++) {

        if (val < E[i]) return 0;
        L[i] = val - E[i] + 1;
        L[i] = n + 1 - L[i];
        // cout << i << ": " << L[i] << endl;
        tindeg[i] = indeg[i];

    }

    set<pair<int,int>> curr;
    for (int i = 1; i <= n; i++) {
        if (tindeg[i] == 0) {        incr++;
        while (v.back() == )
            curr.insert({L[i], i});
        }
    }

    int sf = 1;
    while (curr.size()) {

        auto cv = *curr.begin();
        curr.erase(cv);

        int need = cv.first;
        if (need > sf) return 0;

        sf++;
        int x = cv.second;
        for (int i : g[x]) {
            tindeg[i]--;
            if (tindeg[i] == 0) {
                curr.insert({L[i], i});
            }
        }

    }

    return 1;


}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    // for (int i = 1; i <= n; i++) {
    //     cin >> E[i] >> D[i];
    // }

    for (int i = 1; i <= n; i++) {
        cin >> E[i] >> D[i];
        for (int j = 1; j <= D[i]; j++) {
            int x; cin >> x;
            g[i].push_back(x);
            indeg[x]++;
        }
    }

    // ok(4);
    // return 0;

    int lo = 0, hi = 2e6;
    while (lo != hi) {

        int avg = (lo + hi) / 2;

        if (ok(avg)) hi = avg;
        else lo = avg + 1;

    }

    cout << lo << "\n";

    
}
