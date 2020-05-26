#include<bits/stdc++.h>

// Created by kobortor On 00:06:02 on 26-05-2020

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
        if (n == 1) {
            cout << -1 << "\n";
        } else {
            string s(n, '2');
            s.back() = '3';
            if ((n - 1) * 2 % 3 == 0) {
                s[0] = '4';
            }
            cout << s << '\n';
        }
    }
}
