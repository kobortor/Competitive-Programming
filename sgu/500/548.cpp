#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

char tp[MAXN];
int val[MAXN];
int lim[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    for (int a = 2; a <= N; a++) {
        cin >> tp[a] >> val[a];
    }
    for (int a = N - 1, bi = 1e9; a >= 2; a--) {
        if (tp[a] == 'p') {
            bi = min(bi, val[a]);
        }
        lim[a] = bi;
    }

    priority_queue<pii, vector<pii>, greater<pii>> soln;
    int gold = 0;
    for (int a = 2; a <= N - 1; a++) {
        if (tp[a] == 'd') {
            if ((int)soln.size() + 1 < lim[a]) {
                gold += val[a];
                soln.push({val[a], a});
            } else if (!soln.empty() && val[a] > soln.top().first) {
                gold += val[a] - soln.top().first;
                soln.pop();
                soln.push({val[a], a});
            }
        }
    }

    if ((int)soln.size() < val[N]) {
        cout << -1;
    } else {
        vector<int> vec;
        while (!soln.empty()) {
            vec.push_back(soln.top().second);
            soln.pop();
        }
        sort(allof(vec));
        cout << gold << "\n";
        cout << vec.size() << "\n";
        for (int i : vec) {
            cout << i << " ";
        }
    }
}
