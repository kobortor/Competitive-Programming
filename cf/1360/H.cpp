#include<bits/stdc++.h>

// Created by kobortor On 16:03:28 on 27-05-2020

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
        ll n, m;
        cin >> n >> m;

        ll k = (1ll << m) - n;

        ll median = (k - 1) / 2;

        vector<ll> a(n);
        for (ll &ai : a) {
            bitset<60> bits;
            cin >> bits;
            ai = bits.to_ullong();
        }

        sort(allof(a));
        ll added = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] - (i + 1) < median) {
                added = i + 1;
            }
        }

        median += added;

        string s = bitset<60>(median).to_string();
        s = s.substr(60 - m, string::npos);

        cout << s << "\n";
    }
}
