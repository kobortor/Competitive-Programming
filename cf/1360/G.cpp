#include<bits/stdc++.h>

// Created by kobortor On 15:31:14 on 27-05-2020

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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        
        if (n * a == m * b) {
            cout << "YES\n";

            int col = 0;
            for (int i = 0; i < n; i++) {
                string s(m, '0');
                for (int j = 0; j < a; j++, col=(col+1)%m) {
                    s[col] = '1';
                }
                cout << s << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}
