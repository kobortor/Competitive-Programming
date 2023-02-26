#include<bits/stdc++.h>

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
    
    ll julia;
    cin >> julia;

    vector<ll> v;
    for(int i = 1; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    sort(allof(v));

    ll maxv = v.back();
    ll maxcnt = 1;
    v.pop_back();

    while (!v.empty() && v.back() == maxv) {
        v.pop_back();
        maxcnt++;
    }

    // Increase by 2 causes maxv to increase by 1, incr to increase by 2
    ll incr = 0;
    while (maxv <= julia) {
        if (maxcnt != 1) {
            maxv++;
            maxcnt--;
            v.push_back(maxv - 1 - (incr + 1));
        }

        incr++;
        while (!v.empty() && v.back() + incr <= maxv) {
            v.pop_back();
            maxcnt++;
        }
    }
    cout << incr - 1 << endl;
}
