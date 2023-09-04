#include<bits/stdc++.h>

// Created by kobortor On 10:23:24 on 15-06-2023

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
        int n;
        cin >> n;
        
        int min_odd = 2e9;
        int min_even = 2e9;
        int num_odd = 0;
        int num_even = 0;

        vector<int> A(n);
        for (int &ai : A) {
            cin >> ai;

            if (ai % 2 == 0) {
                num_even++;
                min_even = min(min_even, ai);
            } else {
                num_odd++;
                min_odd = min(min_odd, ai);
            }
        }

        bool good = false;

        // Make even
        good |= (num_odd == 0);

        // Make odd
        good |= (num_even == 0) || (min_odd < min_even);

        cout << (good ? "YES\n" : "NO\n");
    }
}
