#include<bits/stdc++.h>

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
        string s, c;
        cin >> s >> c;

        pii best_swap{0, 0};

        int swap_posn = s.size() - 1;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (s[i] < s[swap_posn]) {
                swap_posn = i;
            }

            if (s[i] > s[swap_posn]) {
                best_swap = {i, swap_posn};
            }
        }

        swap(s[best_swap.first], s[best_swap.second]);

        if (s < c) {
            cout << s << "\n";
        } else {
            cout << "---\n";
        }
    }
}
