#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 100100;

ll moves[MAXN];

void solve(ll n, ll M, vector<ll> v) {

    set<pair<ll,ll>> frq;
    ll offset = 0;

    moves[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        moves[i] = (moves[i / 2]) + 1;
    }

    ll ans = 0;

    while (v.size()) {

        ll lv = v.back();
        ll cnt = 1;
        v.pop_back();

        while (v.size() && v.back() == lv) {
            v.pop_back();
            cnt++;
        }

        frq.insert({lv, cnt});

    }

    auto second_most = [&]() {

        auto it = frq.rbegin();
        return *(++it);

    };

    auto add_to_last = [&](ll x, ll y) {

        auto cc = *frq.rbegin();
        frq.erase(cc);
        cc.second += y;
        cc.first += x;

        frq.insert(cc);

    };

    auto add_to_val = [&](ll x, ll y) {

        if (y == 0) return;

        auto it = frq.lower_bound({x, -1e9});
        if (it == frq.end() || (it->first != x)) {
            frq.insert({x, y});
        }
        else {
            ll cv = it->second;
            frq.erase({x, cv});
            frq.insert({x, cv + y});
        }

    };

    auto step_forward = [&]() {

        // move forward by one bet
        // cout << "step fw" << endl;

        ans++;

        ll ch = frq.rbegin()->second;
        ll lval = frq.rbegin()->first;

        frq.erase({lval, ch});

        add_to_val(lval - 1, (ch + 1) / 2);
        add_to_val(lval, ch / 2);

        offset++;

    };

    while ((frq.rbegin()->first) + offset < M) {

        // cout << "currently" << endl;
        // for (auto [vv, ff] : frq)
        //     cout << " (" << vv + offset << " " << ff << ")\n";

        ll cmax = (frq.rbegin()->first) + offset;

        if (frq.rbegin()->second == 1) {
            ll td = second_most().first + offset;
            td = (cmax - td);
            frq.erase(frq.find(*frq.rbegin()));
            add_to_last(0, 1);
            ans += td;
            offset += td;
            // cout << "upd offset by " << td << endl;
            continue;
        }

        ll need = moves[frq.rbegin()->second];

        if (frq.size() == 1) {

            // cout << cmax << " " << need << " " << M << endl;

            if (cmax + (need - 1) >= M) {

                while (frq.rbegin()->first + offset < M) {
                    step_forward();
                }

            }
            else {

                ll blocks = (M - cmax);
                blocks = blocks / (need - 1) - (blocks % (need - 1) == 0);

                ans += (blocks * need);
                offset += (blocks * (need - 1));

            }

        }
        else {

            ll steps = cmax - second_most().first - offset;

            if (cmax + (steps) * (need - 1) >= M) {

                ll td = M - cmax;
                td = (td / (need - 1)) - (td % (need - 1) == 0);

                offset += (td * need);
                ans += (td * need);
                add_to_last(-td, 0);

                while (frq.rbegin()->first + offset < M) {
                    step_forward();
                }

            }
            else {

                ans += steps * need;
                offset += (steps * need);

                // cout << "step by " << steps << " * " << need << endl;

                ll ff = frq.rbegin()->second;
                frq.erase(*frq.rbegin());
                add_to_last(0, ff);

            }

        }

    }

    vector<ll> rm;
    for (auto [val, cnt] : frq) {
        while (cnt--) {
            rm.push_back(val + offset);
        }
    }
    sort(rm.begin(), rm.end());
    reverse(rm.begin(), rm.end());

    // cout << "Now:\n";
    // for (ll i : rm)
    //     cout << i << " ";
    // cout << endl;

    cout << (ans + M - rm[1]) << "\n";

}

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

    solve(n, julia, v);
    return 0;

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
        if (maxv + (maxcnt - 1) <= julia) {
            maxv += maxcnt - 1;
            incr += (maxcnt - 1) * 2;
            while (!v.empty() && v.back() + incr <= maxv) {
                v.pop_back();
                maxcnt++;
            }
            continue;
        }

        cout << maxv << " " << maxcnt << " " << incr << " " << v.size() << endl;
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
