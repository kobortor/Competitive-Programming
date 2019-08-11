#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, c;
    cin >> n >> c;

    vector<int> t(n);
    for (int &ti : t) cin >> ti;

    int prv_tm = t.back();
    while (!t.empty() && prv_tm - t.back() <= c) {
        prv_tm = t.back();
        t.pop_back();
    }

    cout << n - t.size();
}
