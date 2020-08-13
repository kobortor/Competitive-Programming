#include<bits/stdc++.h>

// Created by kobortor On 23:13:57 on 08-08-2020

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

        string s;
        cin >> s;

        int k = 0;
        vector<int> zeros, ones;

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '0') {
                if (ones.empty()) {
                    ones.push_back(++k);
                }

                zeros.push_back(ones.back());
                ones.pop_back();

                ans[i] = zeros.back();
            } else {
                if (zeros.empty()) {
                    zeros.push_back(++k);
                }

                ones.push_back(zeros.back());
                zeros.pop_back();

                ans[i] = ones.back();
            }
        }

        cout << k << "\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
