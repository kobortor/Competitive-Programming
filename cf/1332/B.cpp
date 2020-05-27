#include<bits/stdc++.h>

// Created by kobortor On 01:22:06 on 27-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> ans;

        while (n--) {
            int x;
            cin >> x;

            int idx = 0;
            while (x % primes[idx]) idx++;

            ans.push_back(idx);
        }

        vector<int> tmp = ans;
        sort(allof(tmp));
        tmp.erase(unique(allof(tmp)), tmp.end());

        cout << tmp.size() << "\n";
        for (int i : ans) cout << (lower_bound(allof(tmp), i) - tmp.begin() + 1) << " ";
        cout << "\n";
    }
}
