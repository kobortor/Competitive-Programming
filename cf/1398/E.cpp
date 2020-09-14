#include<bits/stdc++.h>

// Created by kobortor On 01:13:15 on 14-09-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;

    ll n_lightning = 0;

    set<tuple<ll, ll, ll>> lft, rht;

    ll normal_damage = 0;
    ll extra_damage = 0;
    ll left_lighting = 0;

    while (n--) {
        ll tp, d;
        cin >> tp >> d;

        normal_damage += d;
        
        if (d > 0) { // add
            if (tp == 1) n_lightning++;

            lft.insert({d, tp, n});
            extra_damage += d;
            if (tp == 1) left_lighting++;
        } else {
            d *= -1;

            if (tp == 1) n_lightning--;

            auto iter = lft.lower_bound({d, 0, 0});
            if (iter != lft.end() && get<0>(*iter) == d) {
                lft.erase(iter);
                extra_damage -= d;

                if (tp == 1) left_lighting--;
            } else {
                iter = rht.lower_bound({d, 0, 0});
                rht.erase(iter);
            }
        }

        // rebalance
        while ((ll)lft.size() > n_lightning) {
            auto first = lft.begin();
            if (get<1>(*first) == 1) left_lighting--;

            extra_damage -= get<0>(*first);
            rht.insert(*first);
            lft.erase(first);

        }

        while ((ll)lft.size() < n_lightning) {
            auto last = prev(rht.end());
            if (get<1>(*last) == 1) left_lighting++;

            extra_damage += get<0>(*last);
            lft.insert(*last);
            rht.erase(last);
        }

        if (!lft.empty() && !rht.empty()) {
            auto lft_iter = lft.begin();
            auto rht_iter = prev(rht.end());
            while (get<0>(*lft_iter) < get<0>(*rht_iter)) {
                rht.insert(*lft_iter);
                lft.insert(*rht_iter);

                if (get<1>(*lft_iter) == 1) left_lighting--;
                if (get<1>(*rht_iter) == 1) left_lighting++;

                extra_damage -= get<0>(*lft_iter);
                extra_damage += get<0>(*rht_iter);

                lft.erase(lft_iter);
                rht.erase(rht_iter);

                lft_iter = lft.begin();
                rht_iter = prev(rht.end());
            }
        }

        ll out = normal_damage + extra_damage;
        if (left_lighting && left_lighting == (ll)lft.size()) {
            out -= get<0>(*lft.begin());
            if (!rht.empty()) {
                out += get<0>(*rht.rbegin());
            }
        }

        cout << out << "\n";
    }
}
