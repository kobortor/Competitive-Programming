#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> atk, def;

    while (n--) {
        string type;
        int value;
        cin >> type >> value;

        if (type == "ATK")  atk.push_back(value);
        else                def.push_back(value);
    }

    vector<int> cards(m);
    for (int &ci : cards) {
        cin >> ci;
    }

    sort(allof(atk));
    sort(allof(def));
    sort(allof(cards));

    ll best = 0;

    // try first `k` attack cards
    for (int k = 1, sum_atk = 0, sum_cards = 0; k <= (int)atk.size() && k <= (int)cards.size(); k++) {
        if (cards[cards.size() - k] >= atk[k - 1]) {
            sum_atk += atk[k - 1];
            sum_cards += cards[cards.size() - k];

            best = max(best, (ll)sum_cards - sum_atk);
        } else {
            break;
        }
    }

    reverse(allof(cards));
    vector<int> remaining;
    for (int d : def) {
        bool success = false;
        while (!cards.empty() && !success) {
            if (cards.back() <= d) {
                remaining.push_back(cards.back());
            } else {
                success = true;
            }
            cards.pop_back();
        }

        if (!success) {
            cout << best;
            return 0;
        }
    }

    // insert the rest of the cards
    remaining.insert(remaining.end(), allof(cards));
    reverse(remaining.end() - cards.size(), remaining.end());
    inplace_merge(remaining.begin(), remaining.end() - cards.size(), remaining.end());
    reverse(allof(remaining));

    reverse(allof(atk));

    if (remaining.size() >= atk.size()) {
        for (int i = 0; i < (int)atk.size(); i++) {
            if (remaining[i] < atk[i]) {
                cout << best;
                return 0;
            }
        }

        best = max(best, accumulate(allof(remaining), 0ll) - accumulate(allof(atk), 0));
    }

    cout << best;
}
