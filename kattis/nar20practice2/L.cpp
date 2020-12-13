#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

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

    map<string, double> best;
    best["pink"] = 0.0; // log(1)

    while (n--) {
        string o, w;
        double rate;
        cin >> o >> w >> rate;
        double log_rate = log(rate);
        if (best.count(w)) {
            if (!best.count(o)) {
                best[o] = best[w] + log_rate;
            } else {
                best[o] = max(best[o], best[w] + log_rate);
            }
        }
    }

    if (best.count("blue")) {
        if (best["blue"] > 5) {
            cout << 10;
        } else {
            cout << fixed << setprecision(15) << (double)min(double(10.0), exp(best["blue"]));
        }
    } else {
        cout << 0;
    }
}
